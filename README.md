# OotCommunityHack2022
A romhack created by the Hylian Modding community as a collective project.

The structure of this repository is subject to change. Below is a guide for our members.

# Setting up Github
**It is important that everyone regularly uploads thier progress to the Github
repository so everyone has a proper method of accessing each other's work, 
and to have proper version control in case of technical issues.**

Install Github Desktop from <https://desktop.github.com/> and log in.

**`If you are the *FIRST* person to make a fork for your zone, follow these instructions:`**

1) On Github's website, fork this repository onto your account: <https://github.com/hylian-modding/OotCommunityHack2022>

2) In Github Desktop, go to `File->Clone Repository` and choose your fork of `OotCommunityHack2022` and where to place it. 

3) Next, create a new branch titled "zone-`x`" using `Branch->New Branch` where `x` is the zone letter you're working in. 

4) Give your zone contributers push permissions to the repo by going into the repo's settings on github's website and inviting them as a contributor.

**`If someone has *ALREADY* made a fork for your zone, follow these instructions:`**

1) Obtain the link to your zone's fork of the repository (pinned in your zone's channel).

2) In Github Desktop, go to `File->Clone Repository`, click the `URL` tab, and paste the link to your zone's fork and where to place it. 

3) Once cloned, change your branch to the zone you are working on via the `Current branch` menu.

4) Ask your zone's host to add you as a contributor to the repository so you can push your work. 


You should now have your repository cloned on your computer for you to work in. **This is your dev environment.**

# Setting up the Github Repository

To set up this repository you must place an `Oot Debug` or `Oot 1.0` rom in the `/rom` folder.

Install `nodejs` from <https://nodejs.org/en/>

Run the following commands in a cmd/powershell terminal in your repo's directory:
```
npm install -g yarn

yarn
```
This will build the repository, creating an assets folder for your zzrtl project, among a few other things.

Alternatively, run `_setup.bat`.
# Developer Ecosystem

## zzrtl
The `/assets` folder will be your zzrtl project. Using SharpOcarina or Custom Actor Toolkit and injecting into the project.zzrpl
will automatically write to the expected folders. [Please read the zzrtl readme for more context on how to use it.](https://github.com/jaredemjohnson/zzrtl-audio/blob/master/README.md)   


## raw assets

The `/raw_assets` folder will host all the work created by everyone, be it model files, code, music, exported binaries, etc. 
The folder structure is like so:
```
-code
	-code_folder
-object
	-object_folder
-zone
	-data
		-map0_data
	-model_files
		-map0
```

The `/code` folder is where all custom code should be developed in. Simply make a folder for your code project and work within that.
`z64hdr` is the C library of choice for all custom C here. 

The `/object` folder is where all custom objects will be placed in. Each object will have its own folder, with its data within (blend files, zobjs, etc).

The `/zone` folders are where each zone's exclusive data is stored. `/data` is where each map keeps things like SharpOcarina XMLs, exported binaries,
fast64 data, etc. The `/model_files` folder is where the blend files and other related content is stored. 

## fast64
To compile fast64 files, you need mips64-gcc installed. For windows users, use WSL.
1)	Export your scene into `./assets/scene/[scene_folder]/fast64/`
2)	Run ```yarn fast64``` (If using WSL, run using that instead of command prompt)
3)	If successful, your built zscene & zmap(s) should be placed in `./assets/scene/[scene_folder]`

# Building

When you want to build the repo, run the following command in a cmd/powershell terminal in your repo's directory:
```
yarn build
```
This will automatically build the zzrtl project.

Alternatively, run `_build.bat`.

# Distributing

When you want to distribute a patch, run the following command in a cmd/powershell terminal in your repo's directory:
```
yarn dist
```
This will automatically build the zzrtl project and places the end result into `/output`. 
This folder should have the built ROM, a bps patch, and a zipped bps patch (in case of patch size getting inflated).

Alternatively, run `_dist.bat`.

# Testing
When you want to test the repo, run the following command in a cmd/powershell terminal in your repo's directory:
```
yarn test
```
This will build the zzrtl project and open the built ROM automatically using the default emulator tied to `.z64` files, if set up.

Alternatively, run `_test.bat`.

**Keep in mind you could miss errors using the scripts as Windows automatically closes the terminal after script execution has ended.**

If something isn't working, run it using the command prompt to see what went wrong and let us know what happened if you need help.

# Contributing to the Github Repository

When you are ready to push your files onto Github for others to have available and updated, do the following steps:

1)	`Fetch for updates` and pull them if there are any. It is important you are up to date before pushing your own changes.
2)	Make sure everything is in place and the changes displayed in Github Desktop look to be correct (no files in wrong places, etc).
3)	Write a commit message summarizing your recent changes and press `Commit to [fork]`. 
4)	Press `Push`

Now your files are up on the repo for everyone able to pull. Make sure to commit and pull often as to make sure everyone has the most recent stuff!
If there are any isssues like merge conflicts, let us know if you need help solving them. 

# Merging from Upstream

The `upstream` repository is what you forked from, specifically `hylian-modding/OotCommunityHack2022`.
When the upstream repository updates, it is important to merge it with your branch. Here's how: 

1)	Open the `Current branch` menu in Github Desktop and select `Choose a branch to merge into <`**your_branch_here**`>`.
2)	Select `upstream/master` under the `Other branches` category.
3)	Press `Create a merge commit`.
4)	Once succesfully merged, push to update the repo so it is up to date with upstream. 

# Sending Pull Requests to Upstream

When you are ready to push your zone to upstream, you can make a pull request for it to be merged. 

1)	Select `Create Pull Request` in Github Desktop to open a Github webpage to create the PR.
2)	Make sure you are trying to merge your zone's fork to `hylian-modding/OotCommunityHack2022`.
3)	Write a description of what has changed in this PR.
4)	Select `Create Pull Reqeust` to submit the PR for review

When Psi-Hate, Denoflions, or CDi-Fails are able, they will review the PR and ensure it is working before merging.
**In an effort to keep everyone's progress regularly catalogued , please PR at least once per week if there are any updates.**

If you have any questions regarding this guide or need something specific answered, please reach out to us for further guidance.
