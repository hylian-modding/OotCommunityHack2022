import gulp from 'gulp';
import fs from 'fs-extra';
import child_process from 'child_process';
import AdmZip from 'adm-zip';
import path from 'path';

gulp.task('install', function(){
    try{
        fs.mkdirSync("./assets");
    }catch(err){}
    console.log("Setting up zzrtl...");
    let og = process.cwd();
    fs.copyFileSync("./tools/zzrtl-r5b-4.exe", "./assets/zzrtl.exe");
    fs.copyFileSync("./tools/oot_names.tsv", "./assets/oot_names.tsv");
    fs.copyFileSync("./tools/oot_dump.rtl", "./assets/oot_dump.rtl");
    fs.copyFileSync("./tools/oot_build.rtl", "./assets/oot_build.rtl");
    fs.copyFileSync("./tools/flips.exe", "./assets/flips.exe");
    fs.copyFileSync("./tools/config.tsv", "./assets/config.tsv");
    let baserom: string = "";
    fs.readdirSync("./rom").forEach((f: string)=>{
        let file = path.resolve("./rom", f);
        if (fs.existsSync(file)){
            if (fs.lstatSync(file).isDirectory()) return;
            if (path.parse(file).ext === ".z64"){
                baserom = file;
            }
        }
    });
    if (baserom !== ""){
        fs.copyFileSync(baserom, "./assets/baserom.z64");
    }
    process.chdir("./assets");
    child_process.execSync("zzrtl.exe oot_dump.rtl");
    process.chdir(og);
    return gulp.src('.');
});

gulp.task('_build', function () {
    let zip = new AdmZip();
    let og = process.cwd();
    process.chdir("./assets");
    console.log("Building rom...");
    child_process.execSync("zzrtl.exe oot_build.rtl");
    console.log("Making patch...");
    child_process.execSync("flips.exe --create baserom.z64 build-yaz.z64 HMCommunity2022.bps");
    process.chdir(og);
    try{
        fs.removeSync("./output");
        fs.mkdirSync("./output")
    }catch(err){
    }
    fs.copySync("./assets/HMCommunity2022.bps", "./output/HMCommunity2022.bps");
    zip.addLocalFolder("./output");
    zip.writeZip("./output/HMCommunity2022.zip");
    fs.copySync("./assets/build-yaz.z64", "./output/HMCommunity2022.z64");
    console.log("Done. Output at ./output/HMCommunity2022.zip");
    process.chdir(og);
    return gulp.src('.');
});

gulp.task("build", gulp.series(['_build']));

gulp.task("default", gulp.series(['build']));