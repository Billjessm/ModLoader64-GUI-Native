make clean
cd extern_libs/raylib/src/
make -j8 PLATFORM=PLATFORM_RPI USE_RPI_CROSS_COMPILER=TRUE RPI_TOOLCHAIN=/opt/toolchain/arm-linux-gnueabihf RPI_TOOLCHAIN_SYSROOT=""
cd ../../../
make -j8 PLATFORM=PLATFORM_RPI USE_RPI_CROSS_COMPILER=TRUE RPI_TOOLCHAIN=/opt/toolchain/arm-linux-gnueabihf RPI_TOOLCHAIN_SYSROOT=""


