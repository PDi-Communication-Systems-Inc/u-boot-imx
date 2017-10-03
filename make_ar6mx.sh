# Quick little script to build the TAB series bootloader
ARCH=arm
CROSS_COMPILE=../../../prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin/arm-eabi-
THREADS=8

make -j$THREADS distclean ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE
make -j$THREADS ar6mxqandroid_config ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE
make -j$THREADS ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE
cp -v --remove-destination u-boot.imx ../../../out/target/product/ar6mx/u-boot.imx
cp -v --remove-destination u-boot.imx ../../../out/target/product/ar6mx/u-boot-6q.imx
