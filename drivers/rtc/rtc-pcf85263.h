/* SPDX-License-Identifier: GPL-2.0
 * NXP PCF85263 RTC driver
 * Copyright (C) 2015 Eurotech Ltd Fabrizio Castro
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>
 */

#ifndef __RTC_PCF85263_H__
#define __RTC_PCF85263_H__

#define DRIVER_VERSION "0.1"

#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80

/*
 * RTC mode time registers
 * RTCM = 0
 */

// RTC time and date registers
#define REGISTER_CENTS_OF_SECOND 0x00
#define CENTS_OF_SECONDS_BITS 0xFF

#define REGISTER_SECONDS 0x01
#define SECONDS_BITS 0x7F
#define OS BIT7
#define OS_SET BIT7
#define OS_CLEAR 0x00

#define REGISTER_MINUTES 0x02
#define MINUTES_BITS 0x7F
#define EMON BIT7

#define REGISTER_HOURS 0x03
#define HOURS_BITS 0x3F

#define REGISTER_DAYS 0x04
#define DAYS_BITS 0x3F

#define REGISTER_WEEKDAYS 0x05
#define WEEKDAYS_BITS 0x03

#define REGISTER_MONTHS 0x06
#define MONTHS_BITS 0x1F

#define REGISTER_YEARS 0x07
#define YEARS_BITS 0xFF

// RTC alarm1
#define REGISTER_SECOND_ALARM1 0x08

#define REGISTER_MINUTE_ALARM1 0x09

#define REGISTER_HOUR_ALARM1 0x0A

#define REGISTER_DAY_ALARM1 0x0B

#define REGISTER_MONTH_ALARM1 0x0C

// RTC alarm2
#define REGISTER_MINUTE_ALARM2 0x0D

#define REGISTER_HOUR_ALARM2 0x0E

#define REGISTER_WEEKDAY_ALARM2 0x0F

// RTC alarm enables
#define REGISTER_ALARM_ENABLES 0x10
#define WDAY_A2E BIT7
#define WDAY_A2E_ENABLE BIT7
#define WDAY_A2E_DISABLE 0x00
#define HR_A2E BIT6
#define HR_A2E_ENABLE BIT6
#define HR_A2E_DISABLE 0x00
#define MIN_A2E BIT5
#define MIN_A2E_ENABLE BIT5
#define MIN_A2E_DISABLE 0x00
#define MON_A1E BIT4
#define MON_A1E_ENABLE BIT4
#define MON_A1E_DISABLE 0x00
#define DAY_A1E BIT3
#define DAY_A1E_ENABLE BIT3
#define DAY_A1E_DISABLE 0x00
#define HR_A1E BIT2
#define HR_A1E_ENABLE BIT2
#define HR_A1E_DISABLE 0x00
#define MIN_A1E BIT1
#define MIN_A1E_ENABLE BIT1
#define MIN_A1E_DISABLE 0x00
#define SEC_A1E BIT0
#define SEC_A1E_ENABLE BIT0
#define SEC_A1E_DISABLE 0x00
#define ALARM1_BITS (MON_A1E | \
	DAY_A1E | \
	HR_A1E | \
	MIN_A1E | \
	SEC_A1E)
#define ALARM1_ENABLE (MON_A1E_ENABLE | \
	DAY_A1E_ENABLE | \
	HR_A1E_ENABLE | \
	MIN_A1E_ENABLE | \
	SEC_A1E_ENABLE)
#define ALARM1_DISABLE (MON_A1E_DISABLE | \
	DAY_A1E_DISABLE | \
	HR_A1E_DISABLE | \
	MIN_A1E_DISABLE | \
	SEC_A1E_DISABLE)
#define ALARM2_ENABLE (WDAY_A2E_ENABLE | \
	HR_A2E_ENABLE | \
	MIN_A2E_ENABLE)
#define ALARM2_DISABLE (WDAY_A2E_DISABLE | \
	HR_A2E_DISABLE | \
	MIN_A2E_DISABLE)

// RTC timestamp1 (TSR1)
#define REGISTER_TSR1_SECONDS 0x11

#define REGISTER_TSR1_MINUTES 0x12

#define REGISTER_TSR1_HOURS 0x13

#define REGISTER_TSR1_DAYS 0x14

#define REGISTER_TSR1_MONTHS 0x15

#define REGISTER_TSR1_YEARS 0x16

// RTC timestamp2 (TSR2)
#define REGISTER_TSR2_SECONDS 0x17

#define REGISTER_TSR2_MINUTES 0x18

#define REGISTER_TSR2_HOURS 0x19

#define REGISTER_TSR2_DAYS 0x1A

#define REGISTER_TSR2_MONTHS 0x1B

#define REGISTER_TSR2_YEARS 0x1C

// RTC timestamp3 (TSR3)
#define REGISTER_TSR3_SECONDS 0x1D

#define REGISTER_TSR3_MINUTES 0x1E

#define REGISTER_TSR3_HOURS 0x1F

#define REGISTER_TSR3_DAYS 0x20

#define REGISTER_TSR3_MONTHS 0x21

#define REGISTER_TSR3_YEARS 0x22

// RTC timestamp mode control
#define REGISTER_TSR_MODE 0x23
#define TSR1M (BIT1 | BIT0)
#define TSR1M_NO_TIMESTAMP 0x00
#define TSR1M_FIRST_TS_EVENT BIT0
#define TSR1M_LAST_TS_EVENT BIT1
#define TSR2M (BIT4 | BIT3 | BIT2)
#define TSR2M_NO_TIMESTAMP 0x00
#define TSR2M_FIRST_SWITCH_TO_BATTERY BIT2
#define TSR2M_LAST_SWITCH_TO_BATTERY BIT3
#define TSR2M_LAST_SWITCH_TO_VDD (BIT3 | BIT2)
#define TSR2M_FIRST_TS_EVENT BIT4
#define TSR2M_LAST_TS_EVENT (BIT4 | BIT2)
#define TSR3M (BIT7 | BIT6)
#define TSR3M_NO_TIMESTAMP 0x00
#define TSR3M_FIRST_SWITCH_TO_BATTERY BIT6
#define TSR3M_LAST_SWITCH_TO_BATTERY BIT7
#define TSR3M_LAST_SWITCH_TO_VDD (BIT7 | BIT6)

/*
 * Control and function registers overview
 */

// Offset register
#define REGISTER_OFFSET 0x24

// Control registers
#define REGISTER_OSCILLATOR 0x25
#define AMPM_12_24 BIT5
#define AMPM_12_HOUR_MODE BIT5
#define AMPM_24_HOUR_MODE 0x00
#define XTAL_CAP_LOAD 0x03	//BIT0 & BIT1
#define XTAL_CAP_7_0pf 0x00
#define XTAL_CAP_6_0pf 0x01
#define XTAL_CAP_12_5pf 0x02
#define XTAL_CAP_12_5_pf 0x03	//Datasheet says 12.5pF for both 0x02 & 0x03

#define REGISTER_BATTERY_SWITCH 0x26
#define BSOFF BIT4
#define BSOFF_ENABLE 0X00
#define BSOFF_DISABLE BIT4
#define BSRR BIT3
#define BSRR_LOW 0x00
#define BSRR_HIGH BIT3
#define BSM (BIT2 | BIT1)
#define BSM_VTH 0X00
#define BSM_VBAT BIT1
#define BSM_HIGHER BIT2
#define BSM_LOWER (BIT2 | BIT1)
#define BSTH BIT0
#define BSTH_1_5 0x00
#define BSTH_2_8 BIT0

#define BATTERY_SWITCH_OFF 0
#define BATTERY_SWITCH_VTH 1
#define BATTERY_SWITCH_VBAT 2
#define BATTERY_SWITCH_HIGHER 3
#define BATTERY_SWITCH_LOWER 4

#define BATTERY_VTH_1_5 0
#define BATTERY_VTH_2_8 1

#define REGISTER_PIN_IO 0x27
#define CLKPM BIT7
#define CLKPM_ENABLE 0x00
#define CLKPM_DISABLE BIT7
#define TSPULL BIT6
#define TSPULL_80_K_OHM 0x00
#define TSPULL_40_K_OHM BIT6
#define TSL BIT5
#define TSL_ACTIVE_HIGH 0x00
#define TSL_ACTIVE_LOW BIT5
#define TSIM BIT4
#define TSIM_CMOS_INPUT 0x00
#define TSIM_MECHANICAL_SWITCH_MODE BIT4
#define TSPM (BIT3 | BIT2)
#define TSPM_DISABLED 0x00
#define TSPM_INTB BIT2
#define TSPM_CLK_OUTPUT BIT3
#define TSPM_INPUT_MODE (BIT3 | BIT2)
#define INTAPM (BIT1 | BIT0)
#define INTAPM_CLK_OUTPUT 0x00
#define INTAPM_BATTERY_MODE_INDICATION BIT0
#define INTAPM_INTA BIT1
#define INTAPM_HIGH_IMPEDANCE (BIT1 | BIT0)

#define REGISTER_FUNCTION 0x28
#define RTCM BIT4
#define RTCM_RTC_MODE 0x00
#define RTCM_STOP_WATCH_MODE BIT4
#define COF (BIT2 | BIT1 | BIT0)
#define COF_32768 0x00
#define COF_16384 BIT0
#define COF_8192 BIT1
#define COF_4096 (BIT1 | BIT0)
#define COF_2048 BIT2
#define COF_1024 (BIT2 | BIT0)
#define COF_1 (BIT2 | BIT1)
#define COF_LOW (BIT2 | BIT1 | BIT0)

#define REGISTER_INTA_ENABLE 0x29
#define ILPA BIT7
#define ILPA_PULSE_SIGNAL 0x00
#define ILPA_PERMANENT_SIGNAL BIT7
#define PIEA BIT6
#define PIEA_ENABLE BIT6
#define PIEA_DISABLE 0x00
#define OIEA BIT5
#define OIEA_ENABLE BIT5
#define OIEA_DISABLE 0x00
#define A1IEA BIT4
#define A1IEA_ENABLE BIT4
#define A1IEA_DISABLE 0x00
#define A2IEA BIT3
#define A2IEA_ENABLE BIT3
#define A2IEA_DISABLE 0x00
#define TSRIEA BIT2
#define TSRIEA_ENABLE BIT2
#define TSRIEA_DISABLE 0x00
#define BSIEA BIT1
#define BSIEA_ENABLE BIT1
#define BSIEA_DISABLE 0x00
#define WDIEA BIT0
#define WDIEA_ENABLE BIT0
#define WDIEA_DISABLE 0x00

#define REGISTER_INTB_ENABLE 0x2A
#define ILPB BIT7
#define ILPB_PULSE_SIGNAL 0x00
#define ILPB_PERMANENT_SIGNAL BIT7
#define PIEB BIT6
#define PIEB_ENABLE BIT6
#define PIEB_DISABLE 0x00
#define OIEB BIT5
#define OIEB_ENABLE BIT5
#define OIEB_DISABLE 0x00
#define A1IEB BIT4
#define A1IEB_ENABLE BIT4
#define A1IEB_DISABLE 0x00
#define A2IEB BIT3
#define A2IEB_ENABLE BIT3
#define A2IEB_DISABLE 0x00
#define TSRIEB BIT2
#define TSRIEB_ENABLE BIT2
#define TSRIEB_DISABLE 0x00
#define BSIEB BIT1
#define BSIEB_ENABLE BIT1
#define BSIEB_DISABLE 0x00
#define WDIEB BIT0
#define WDIEB_ENABLE BIT0
#define WDIEB_DISABLE 0x00

#define REGISTER_FLAGS 0x2B
#define PERIODIC_INTERRUPT_FLAG BIT7
#define PERIODIC_INTERRUPT_FLAG_ACTIVE BIT7
#define PERIODIC_INTERRUPT_FLAG_CLEAR 0x00
#define ALARM2_FLAG BIT6
#define ALARM2_FLAG_ACTIVE BIT6
#define ALARM2_FLAG_CLEAR 0x00
#define ALARM1_FLAG BIT5
#define ALARM1_FLAG_ACTIVE BIT5
#define ALARM1_FLAG_CLEAR 0x00
#define WATCHDOG_FLAG BIT4
#define WATCHDOG_FLAG_ACTIVE BIT4
#define WATCHDOG_FLAG_CLEAR 0x00
#define BATTERY_SWITCH_FLAG BIT3
#define BATTERY_SWITCH_FLAG_ACTIVE BIT3
#define BATTERY_SWITCH_FLAG_CLEAR 0x00
#define TIMESTAMP_3_FLAG BIT2
#define TIMESTAMP_3_FLAG_ACTIVE BIT2
#define TIMESTAMP_3_FLAG_CLEAR 0x00
#define TIMESTAMP_2_FLAG BIT1
#define TIMESTAMP_2_FLAG_ACTIVE BIT1
#define TIMESTAMP_2_FLAG_CLEAR 0x00
#define TIMESTAMP_1_FLAG BIT0
#define TIMESTAMP_1_FLAG_ACTIVE BIT0
#define TIMESTAMP_1_FLAG_CLEAR 0x00

// RAM byte
#define REGISTER_RAM_BYTE 0x2C

// WatchDog registers
#define REGISTER_WATCHDOG 0x2D
#define WDM BIT7
#define WDM_SINGLE_SHOT 0x00
#define WDM_REPEAT_MODE BIT7
#define WDR (BIT6 | BIT5 | BIT4 | BIT3 | BIT2)
#define WDS (BIT1 | BIT0)
#define WDS_4_SECONDS 0x00
#define WDS_1_SECOND BIT0
#define WDS_1_OVER_4_SECOND BIT1
#define WDS_1_OVER_16_SECOND (BIT1 | BIT0)

// Stop
#define REGISTER_STOP_ENABLE 0x2E
#define STOP BIT0
#define STOP_RTC_RUN 0x00
#define STOP_RTC_STOPPED BIT0

// Reset
#define REGISTER_RESETS 0x2F
#define SR_CMD 0x2C	/* Software Reset, it also triggers CPR and CTS */
#define CPR_CMD 0xA4	/* Clear PRescaler */
#define CTS_CMD 0x25	/* Clear TimeStamps */
#define CPR_CTS_CMD 0xA5	/* Combines CPR and CTS commands */

#define ALARM_ENABLED 1
#define ALARM_DISABLED 0
#define ALARM_PENDING 1
#define ALARM_NOT_PENDING 0

#define NO_INTERRUPT -1
#define INTA 0
#define INTB 1

#endif				/* __RTC_PCF85263_H__ */