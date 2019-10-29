make clean
cd extern_libs/raylib/src/
make -j8 PLATFORM=PLATFORM_DESKTOP
cd ../../../
make -j8 PLATFORM=PLATFORM_DESKTOP


