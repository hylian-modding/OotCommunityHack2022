import gulp from 'gulp';
import fs from 'fs-extra';
import child_process from 'child_process';
import AdmZip from 'adm-zip';
import path from 'path';

const N0: string = "CZLE";
const DEBUG: string = "NZLE";
let id: string = "";

function setID() {
    let rom = fs.readFileSync("./assets/baserom.z64");
    let header = rom.slice(0x0, 0x50);
    id = header.slice(0x3B, 0x3B + 0x4).toString();
    if (id === DEBUG) {
        // Debug rom. Change config.
        console.log("Debug rom detected. Configuring...")
        let config = fs.readFileSync("./assets/config.tsv").toString();
        config = config.replace("using_oot_debug_rom	false	(true = debug, false = 1.0)", "using_oot_debug_rom	true	(true = debug, false = 1.0)");
        fs.writeFileSync("./assets/config.tsv", config);
    } else if (id === N0) {
        console.log("1.0 rom detected.");
    } else {
        console.log("Unknown rom version!");
    }
}

gulp.task('install', function () {
    try {
        fs.mkdirSync("./assets");
    } catch (err) { }
    console.log("Setting up zzrtl...");
    let og = process.cwd();
    fs.copyFileSync("./tools/zzrtl-r5b-4.exe", "./assets/zzrtl.exe");
    fs.copyFileSync("./tools/oot_names.tsv", "./assets/oot_names.tsv");
    fs.copyFileSync("./tools/oot_dump.rtl", "./assets/oot_dump.rtl");
    fs.copyFileSync("./tools/oot_build.rtl", "./assets/oot_build.rtl");
    fs.copyFileSync("./tools/flips.exe", "./assets/flips.exe");
    fs.copyFileSync("./tools/config.tsv", "./assets/config.tsv");
    let baserom: string = "";
    fs.readdirSync("./rom").forEach((f: string) => {
        let file = path.resolve("./rom", f);
        if (fs.existsSync(file)) {
            if (fs.lstatSync(file).isDirectory()) return;
            if (path.parse(file).ext === ".z64") {
                baserom = file;
            }
        }
    });
    if (baserom !== "") {
        fs.copyFileSync(baserom, "./assets/baserom.z64");
        setID();
    }
    process.chdir("./assets");
    child_process.execSync("zzrtl.exe oot_dump.rtl");
    process.chdir(og);
    return gulp.src('.');
});

gulp.task('_build', function () {
    setID();
    let zip = new AdmZip();
    let og = process.cwd();
    process.chdir("./assets");
    console.log("Building rom...");
    child_process.execSync("zzrtl.exe oot_build.rtl");
    console.log("Making patch...");
    let built_rom: string = "build-yaz.z64";
    if (id === DEBUG){
        built_rom = "build.z64";
    }
    try {
        child_process.execSync(`flips.exe --create baserom.z64 ${built_rom} HMCommunity2022.bps`);
    } catch (err) { }
    process.chdir(og);
    try {
        fs.removeSync("./output");
        fs.mkdirSync("./output")
    } catch (err) {
    }
    fs.copySync("./assets/HMCommunity2022.bps", "./output/HMCommunity2022.bps");
    zip.addLocalFolder("./output");
    zip.writeZip("./output/HMCommunity2022.zip");
    fs.copySync(`./assets/${built_rom}`, "./output/HMCommunity2022.z64");
    console.log("Done. Output at ./output/HMCommunity2022.zip");
    process.chdir(og);
    return gulp.src('.');
});

gulp.task("build", gulp.series(['_build']));

gulp.task("default", gulp.series(['build']));