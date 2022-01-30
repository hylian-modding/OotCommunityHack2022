import gulp from 'gulp';
import fs from 'fs-extra';
import child_process from 'child_process';
import path from 'path';
import { SmartBuffer } from 'smart-buffer';

const PROJECT_NAME: string = "HMCommunity2022";
const PROJECT_HEADER: Buffer = Buffer.from('48594C49414E4D4F4444494E47434F4D4D554E4954593230323200', 'hex');

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

gulp.task('clean', function(){
    let og = process.cwd();
    process.chdir("./assets");
    if (fs.existsSync("./build.z64")){
        fs.unlinkSync("./build.z64");
    }
    if (fs.existsSync("./build-yaz.z64")){
        fs.unlinkSync("./build-yaz.z64");
    }
    if (fs.existsSync(`./${PROJECT_NAME}.z64`)){
        fs.unlinkSync(`./${PROJECT_NAME}.z64`);
    }
    if (fs.existsSync(`./${PROJECT_NAME}.bps`)){
        fs.unlinkSync(`./${PROJECT_NAME}.bps`);
    }
    process.chdir(og);
    return gulp.src('.');
});

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

function findLines(input: string, pattern: string, arr: string[] = []){
    let lines = input.split("\n");
    for (let i = 0; i < lines.length; i++){
        if (lines[i].indexOf(pattern) > -1){
            arr.push(lines[i]);
        }
    }
    return arr;
}

function findAllFiles(dir: string, ext: string){
    let arr: string[] = [];
    fs.readdirSync(dir).forEach((f: string)=>{
        let file: string = path.resolve(dir, f);
        if (fs.existsSync(file)){
            if (fs.lstatSync(file).isDirectory()) return;
            if (path.parse(file).ext === ext){
                arr.push(file);
            }
        }
    });
    return arr;
}

function getAllFolders(dirPath: string, arrayOfFiles: Array<string>) {
    let files = fs.readdirSync(dirPath);

    arrayOfFiles = arrayOfFiles || [];

    files.forEach((file) => {
        if (fs.statSync(dirPath + "/" + file).isDirectory()) {
            arrayOfFiles.push(path.join(dirPath, "/", file));
            arrayOfFiles = getAllFolders(dirPath + "/" + file, arrayOfFiles);
        }
    });

    return arrayOfFiles;
}

function compileActor(z64hdr: string, entry: string){
    let files = findAllFiles(".", ".c");
    if (files.length > 0){
        console.log(`Processing actor source found in ${path.parse(process.cwd()).name}`);
    }else{
        return;
    }
    files.forEach((file: string)=>{
        console.log(`Compiling ${path.parse(file).base}...`);
        let p = path.resolve(path.parse(z64hdr).dir, "..");
        child_process.execSync(`mips64-gcc -fno-zero-initialized-in-bss -std=gnu11 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3 -mno-shared -mdivide-breaks -mno-explicit-relocs -mno-memcpy -mno-check-zero-division -ffreestanding -fno-reorder-blocks -w -I${z64hdr} -I${p} -D_LANGUAGE_C -G 0 -O3 -c ./${path.parse(file).base}`);
        child_process.execSync(`mips64-ld -L${path.parse(z64hdr).dir} -T ${path.parse(entry).base} --emit-relocs -o ${path.parse(file).name}.elf ${path.parse(file).name}.o`);
        child_process.execSync(`nOVL -s -c -A 0x80800000 -o ${path.parse(file).name}.zovl ${path.parse(file).name}.elf`);
        let dump = child_process.execSync(`mips64-objdump -t -C -r -w --special-syms ${path.parse(file).name}.elf`).toString();
        //console.log(dump);
        fs.unlinkSync(`./${path.parse(file).name}.o`);
        fs.unlinkSync(`./${path.parse(file).name}.elf`);
    });
}

gulp.task('system', function(){
    let og = process.cwd();
    let z64hdr = path.resolve("./z64hdr/include");
    let entry = path.resolve("./z64hdr/oot_10.ld");
    process.chdir("./assets");
    process.chdir("./system");
    let folders = getAllFolders(".", []);
    folders.forEach((dir: string)=>{
        process.chdir(og);
        process.chdir("./assets");
        process.chdir("./system");
        process.chdir(dir);
        compileActor(z64hdr, entry);
    });
    process.chdir(og);
    return gulp.src('.');
});

gulp.task('actors', function(){
    let og = process.cwd();
    let z64hdr = path.resolve("./z64hdr/include");
    let entry = path.resolve("./z64hdr/oot_10.ld");
    process.chdir("./assets");
    process.chdir("./actor");
    let folders = getAllFolders(".", []);
    folders.forEach((dir: string)=>{
        process.chdir(og);
        process.chdir("./assets");
        process.chdir("./actor");
        process.chdir(dir);
        compileActor(z64hdr, entry);
    });
    process.chdir(og);
    return gulp.src('.');
});

function compileSceneAndRoom(z64hdr: string, entry: string){
    fs.copyFileSync(path.resolve(path.parse(entry).dir, "entry_default.ld"), "./entry.ld");

    let files = findAllFiles(".", ".c");
    let scene_index = -1;
    for (let i = 0; i < files.length; i++){
        if (files[i].indexOf("scene") > -1){
            scene_index = i;
        }
    }
    if (files.length > 0){
        console.log(`Processing fast64 files found in ${path.parse(process.cwd()).name}`);
        let scene = files.splice(scene_index, 1);
        files.unshift(...scene);
    }else{
        return;
    }

    files.forEach((file: string)=>{
        try{
            let isScene: boolean = false;
            console.log(`Compiling ${path.parse(file).base}...`);
            child_process.execSync(`mips64-gcc -fno-zero-initialized-in-bss -std=gnu11 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3 -mno-shared -mdivide-breaks -mno-explicit-relocs -mno-memcpy -mno-check-zero-division -ffreestanding -fno-reorder-blocks -w -I${z64hdr} -D_LANGUAGE_C -G 0 -O0 -c ./${path.parse(file).base}`);
            child_process.execSync(`mips64-ld -L./ -T entry.ld --emit-relocs -o ${path.parse(file).name}.elf ${path.parse(file).name}.o`);
            let dump = child_process.execSync(`mips64-objdump -t -C -r -w --special-syms ${path.parse(file).name}.elf`).toString();
            let arr = findLines(dump, "O .data");
            findLines(dump, "O .bss", arr);
            if (path.parse(file).base.indexOf("scene") > -1){
                console.log("Generating linker script for rooms from scene...");
                let entry = fs.readFileSync("./entry.ld").toString();
                entry = entry.replace(". = 0x02000000;", ". = 0x03000000;");
                entry += "\n";
                arr.forEach((e: string)=>{
                    let s = e.split(" ");
                    let offset = parseInt(s[0], 16);
                    let symbol = s[s.length - 1];
                    entry += `${symbol} = 0x${offset.toString(16)};\n`;
                });
                fs.writeFileSync("./entry.ld", entry);
                isScene = true;
            }
            let ext = ".zmap";
            if (isScene){
                ext = ".zscene";
            }
            let out = `${path.parse(file).name}${ext}`;
            child_process.execSync(`mips64-objcopy -O binary ${path.parse(file).name}.elf ${out}`);
            let _o = fs.readFileSync(`./${out}`);
            let sb = new SmartBuffer();
            sb.writeBuffer(_o);
            let padding: number = 0;
            while (sb.length % 0x10 !== 0){
                sb.writeUInt8(0);
                padding++;
            }
            if (padding > 0){
                console.log(`Added 0x${padding.toString(16)} bytes of padding for alignment.`);
            }
            fs.writeFileSync(`./${out}`, sb.toBuffer());
            fs.unlinkSync(`./${path.parse(file).name}.o`);
            fs.unlinkSync(`./${path.parse(file).name}.elf`);
        }catch(err){
            return;
        }
    });
    fs.unlinkSync("./entry.ld");
}

gulp.task('fast64', function(){
    let og = process.cwd();
    let z64hdr = path.resolve("./z64hdr/include");
    let entry = path.resolve("./tools/entry.ld");
    process.chdir("./assets");
    process.chdir("./scene");
    let folders = getAllFolders(".", []);
    folders.forEach((dir: string)=>{
        process.chdir(og);
        process.chdir("./assets");
        process.chdir("./scene");
        process.chdir(dir);
        compileSceneAndRoom(z64hdr, entry);
    });
    process.chdir(og);
    return gulp.src('.');
});

gulp.task('_build', function () {
    setID();
    let og = process.cwd();
    process.chdir("./assets");
    console.log("Running zzrtl...");
    child_process.execSync("zzrtl.exe oot_build.rtl");
    process.chdir(og);
    return gulp.src('.');
});

gulp.task('makepatch', function(){
    setID();
    let og = process.cwd();
    process.chdir("./assets");
    console.log("Making patch...");
    if (fs.existsSync(`./${PROJECT_NAME}.z64`)){
        try {
            child_process.execSync(`flips.exe --create baserom.z64 ${PROJECT_NAME}.z64 ${PROJECT_NAME}.bps`);
        } catch (err) { }
    }
    process.chdir(og);
    fs.copyFileSync(`./assets/${PROJECT_NAME}.bps`, `./output/${PROJECT_NAME}.bps`);
    return gulp.src('.');
});

gulp.task("_dist", function(){
    setID();
    let og = process.cwd();
    process.chdir("./assets");
    let built_rom: string = "build-yaz.z64";
    if (id === DEBUG){
        built_rom = "build.z64";
    }
    let buf = fs.readFileSync(`./${built_rom}`);
    PROJECT_HEADER.copy(buf, 0x20);
    fs.writeFileSync(`./${PROJECT_NAME}.z64`, buf);
    process.chdir(og);
    try {
        fs.removeSync("./output");
    } catch (err) {
    }
    try {
        fs.mkdirSync("./output")
    } catch (err) {
    }
    fs.copyFileSync(`./assets/${PROJECT_NAME}.z64`, `./output/${PROJECT_NAME}.z64`);
    console.log("Done.");
    return gulp.src('.');
});

gulp.task("build", gulp.series(['clean', '_build']));

gulp.task("dist", gulp.series(['build', '_dist', 'makepatch']));

gulp.task("_test", function(){
    let built_rom: string = "build-yaz.z64";
    if (id === DEBUG){
        built_rom = "build.z64";
    }
    child_process.execSync(path.resolve(`./assets/${built_rom}`));
});

gulp.task('test', gulp.series(['build', '_test']));

gulp.task("default", gulp.series(['build']));