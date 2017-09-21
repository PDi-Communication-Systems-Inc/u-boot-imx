/*
 * Copyright (C) 2013-2014 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef MX6_SABRE_ANDROID_COMMON_H
#define MX6_SABRE_ANDROID_COMMON_H

#define CONFIG_SERIAL_TAG

#define CONFIG_USB_DEVICE
#define CONFIG_IMX_UDC		       1

#define CONFIG_FASTBOOT		       1
#define CONFIG_FASTBOOT_VENDOR_ID      0x18d1
#define CONFIG_FASTBOOT_PRODUCT_ID     0x0d02
#define CONFIG_FASTBOOT_BCD_DEVICE     0x311
#define CONFIG_FASTBOOT_MANUFACTURER_STR  "Freescale"
#define CONFIG_FASTBOOT_PRODUCT_NAME_STR "i.mx6 AR6MX Board"
#define CONFIG_FASTBOOT_INTERFACE_STR	 "Android fastboot"
#define CONFIG_FASTBOOT_CONFIGURATION_STR  "Android fastboot"
#define CONFIG_FASTBOOT_SERIAL_NUM	"12345"
#define CONFIG_FASTBOOT_SATA_NO		 0

#if defined CONFIG_SYS_BOOT_NAND
#define CONFIG_FASTBOOT_STORAGE_NAND
#elif defined CONFIG_SYS_BOOT_SATA
#define CONFIG_FASTBOOT_STORAGE_SATA
#else
#define CONFIG_FASTBOOT_STORAGE_MMC
#endif

/*  For system.img growing up more than 256MB, more buffer needs
*   to receive the system.img*/
#define CONFIG_FASTBOOT_TRANSFER_BUF	0x2c000000
#define CONFIG_FASTBOOT_TRANSFER_BUF_SIZE 0x19000000 /* 400M byte */


#define CONFIG_CMD_BOOTI

/* Display logo, could be customized for distributors */
#define CONFIG_CMD_BMP

/* Enable recovery, BCM had it disabled for some reason */
#define CONFIG_ANDROID_RECOVERY

/* May need to get a guid from time to time */
#define CONFIG_CMD_UUID

/* which mmc bus is your main storage ? */
#define CONFIG_ANDROID_MAIN_MMC_BUS 3
#define CONFIG_ANDROID_BOOT_PARTITION_MMC 1
#define CONFIG_ANDROID_SYSTEM_PARTITION_MMC 5
#define CONFIG_ANDROID_RECOVERY_PARTITION_MMC 2
#define CONFIG_ANDROID_CACHE_PARTITION_MMC 6

#undef CONFIG_EXTRA_ENV_SETTINGS
#undef CONFIG_BOOTCOMMAND

/* Note that code in board/bcmcom/ar6mx/ar6mx.c determines
   whether bootargs_ldb or bootargs_hdmi is used
*/
#define CONFIG_EXTRA_ENV_SETTINGS					\
	"splashpos=m,m\0"	  \
	"fdt_high=0xffffffff\0"	  \
	"fdt_addr=0x14f00000\0"   \
	"initrd_high=0xffffffff\0" \
	"bootargs=console=ttymxc0,115200\0"	\
	"bootargs_base=setenv bootargs console=ttymxc0,115200 "\
		"vmalloc=400M androidboot.console=ttymxc0 "\
        "ldb_di_clk_sel=pll5_video_div "\
		"androidboot.hardware=freescale "\
		"video=mxcfb0:bpp=32\0"

#if defined(CONFIG_FASTBOOT_STORAGE_NAND)
#define ANDROID_FASTBOOT_NAND_PARTS "16m@64m(boot) 16m@80m(recovery) 810m@96m(android_root)ubifs"
#endif

#endif /* MX6_SABRE_ANDROID_COMMON_H */
