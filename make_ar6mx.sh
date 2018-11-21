# Quick little script to build the TAB series bootloader
ARCH=arm
CROSS_COMPILE=$PWD/../../../prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin/arm-eabi-
THREADS=8

echo CROSS_COMPILE=$CROSS_COMPILE
make -j$THREADS ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE distclean
make -j$THREADS ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE ar6mxandroid_defconfig
make -j$THREADS ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE

# Combine u-boot with SPL into one image
dd if=/dev/zero count=500 bs=1K | tr '\000' '\377' > u-boot.imx
dd if=SPL of=u-boot.imx conv=notrunc && dd if=u-boot.img of=u-boot.imx bs=1K seek=68 conv=notrunc

# Copy output files to the "out" dir
cp -v --remove-destination u-boot.imx ../../../out/target/product/ar6mx/u-boot.imx
cp -v --remove-destination u-boot.imx ../../../out/target/product/ar6mx/u-boot-6q.imx
