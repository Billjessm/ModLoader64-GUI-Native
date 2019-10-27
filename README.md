# ModLoader 64 GUI - Native

This is the repository for the native launcher. The purpose of this launcher is to support multimedia PC's and the Raspberry PI. So that you can play on TV with Gamepad only.

# Status
Currently the launcher is in a complete rewrite and not yet usable.
The following features will be added: [TODO](TODO.md)

# Contribute
In the current status it is difficult to help. 
Since I haven't written a C program in a long time, it would be most helpful if you look over the structure and give me some tips.

# Build
You need cmake 3.11 to compile the sources.
if your system does not provide this version with the packet manager, the following blog post will help you:
[How to install the latest version of Cmake](https://anglehit.com/how-to-install-the-latest-version-of-cmake-via-command-line/)

### Clone
```
git clone --recurse-submodules https://github.com/hylian-modding/ModLoader64-GUI-Native
cd ModLoader64-GUI-Native
```
### Build
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Cross-compile

cross-compile is only tested with ubuntu so far and only creating a win32 exe.
For this you need mingw:
```bash
sudo apt install g++-mingw-w64-i686 gcc-mingw-w64-i686
```
Then you can compile as follow:
```bash
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE="../i686-w64-mingw32.cmake" ...
cmake --build .
```

# Licence
[GNU GENERAL PUBLIC LICENSE](LICENSE.md)
