import gulp from 'gulp';
import fs from 'fs-extra';
import child_process from 'child_process';
import AdmZip from 'adm-zip';

gulp.task('_build', function () {
    let zip = new AdmZip();
    zip.addLocalFolder("./assets");
    console.log("Setting up zzrtl...");
    let og = process.cwd();
    fs.copyFileSync("./tools/zzrtl-v1.0.5-win32.exe", "./assets/zzrtl-v1.0.5-win32.exe");
    fs.copyFileSync("./tools/oot_names.tsv", "./assets/oot_names.tsv");
    fs.copyFileSync("./tools/oot_dump.rtl", "./assets/oot_dump.rtl");
    fs.copyFileSync("./tools/oot_build.rtl", "./assets/oot_build.rtl");
    fs.copyFileSync("./tools/flips.exe", "./assets/flips.exe");
    process.chdir("./assets");
    child_process.execSync("zzrtl-v1.0.5-win32.exe oot_dump.rtl");
    console.log("Building rom...");
    child_process.execSync("zzrtl-v1.0.5-win32.exe oot_build.rtl");
    console.log("Making patch...");
    child_process.execSync("flips.exe --create baserom.z64 build-yaz.z64 HMCommunity2022.bps");
    process.chdir(og);
    if (fs.existsSync("./assets/actor")){
        fs.removeSync("./assets/actor");
    }
    if (fs.existsSync("./assets/object")){
        fs.removeSync("./assets/object");
    }
    if (fs.existsSync("./assets/particle")){
        fs.removeSync("./assets/particle");
    }
    if (fs.existsSync("./assets/system")){
        fs.removeSync("./assets/system");
    }
    if (fs.existsSync("./assets/scene")){
        fs.removeSync("./assets/scene");
    }
    try{
        fs.mkdirSync("./output")
    }catch(err){
    }
    fs.copySync("./assets/HMCommunity2022.bps", "./output/HMCommunity2022.bps");

    zip.extractAllTo("./assets");
    console.log("Done. Output at ./output/HMCommunity2022.bps");
    return gulp.src('.');
});

gulp.task("build", gulp.series(['_build']));

gulp.task("default", gulp.series(['build']));