/*
 * arch/arm/mach-tegra/board-star-baseband.h
 *
 * Copyright (C) 2011 NVIDIA Corporation
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef	BOARD_WHISTLER_BASEBAND_H
#define	BOARD_WHISTLER_BASEBAND_H

#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/spi/spi.h>
#include <linux/platform_data/tegra_usb.h>
#include <mach/usb_phy.h>
#include <linux/resource.h>
#include <linux/platform_device.h>
#include <linux/err.h>
#include <asm/mach-types.h>
#include <mach/pinmux.h>
#include <mach/spi.h>

#if defined(CONFIG_MACH_STAR)
#include <mach-tegra/clock.h>
#include <mach-tegra/gpio-names.h>
#include <mach-tegra/devices.h>
#else
#include "gpio-names.h"
#include "clock.h"
#include "devices.h"
#endif

#define	BOARD_WHISTLER_BASEBAND_U3XX		0
#define	BOARD_WHISTLER_BASEBAND_N731		1
#define	BOARD_WHISTLER_BASEBAND_SPI_LOOPBACK	2
#define	BOARD_WHISTLER_BASEBAND_HSIC		3

#define	TEGRA_CAIF_SSPI_GPIO_RESET	TEGRA_GPIO_PV0
#define	TEGRA_CAIF_SSPI_GPIO_POWER	TEGRA_GPIO_PV1
#define	TEGRA_CAIF_SSPI_GPIO_AWR	TEGRA_GPIO_PZ0
#define	TEGRA_CAIF_SSPI_GPIO_CWR	TEGRA_GPIO_PY6
#define	TEGRA_CAIF_SSPI_GPIO_SPI_INT	TEGRA_GPIO_PO6
#define	TEGRA_CAIF_SSPI_GPIO_SS		TEGRA_GPIO_PV2

#define MODEM_PWR_ON	TEGRA_GPIO_PV1
#define MODEM_RESET	TEGRA_GPIO_PV0

/* Rainbow1 and 570 */
#define AWR		TEGRA_GPIO_PZ0
#define CWR		TEGRA_GPIO_PY6
#define SPI_INT		TEGRA_GPIO_PO6
#define SPI_SLAVE_SEL	TEGRA_GPIO_PV2

/* PH450 */
#define AP2MDM_ACK2	TEGRA_GPIO_PU2
#define MDM2AP_ACK2	TEGRA_GPIO_PV2


struct whistler_baseband {
	struct tegra_clk_init_table *clk_init;
	struct platform_device **platform_device;
	int platform_device_size;
	struct spi_board_info *spi_board_info;
	int spi_board_info_size;
};

int whistler_baseband_init(void);

static int spi_init(void); // 20120202 jisil.park@lge.com 

extern int star_baseband_init(void);

#endif	/* BOARD_WHISTLER_BASEBAND_H */

