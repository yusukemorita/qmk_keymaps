/* Copyright 2024 Yusuke Morita
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// #define PMW3389_SCLK_PIN   GP22    // SCK
// #define PMW3389_MOSI_PIN   GP20    // CO (COPI)
// #define PMW3389_MISO_PIN   GP23    // CI (CIPO)
// #define PMW3389_CS_PIN     GP21    // pin "21"
// #define PMW3389_INT_PIN    GP8     // if you wired MT here
// #define PMW3389_RST_PIN GP9     // if you wire RS

// --- SPI on RP2040 ---
#define SPI_DRIVER SPID0            // Use SPI0
#define SPI_SCK_PIN  GP22           // Pro Micro SCK pad
#define SPI_MOSI_PIN GP23           // Pro Micro CO (COPI/MOSI)
#define SPI_MISO_PIN GP20           // Pro Micro CI (CIPO/MISO)

// --- PMW3389 sensor ---
#define PMW33XX_CS_PIN GP21         // Pro Micro pin "21" wired to NCS/SS

// Optional: motion interrupt, if you wired MOT -> Pro Micro pin "19"
// #define POINTING_DEVICE_MOTION_PIN GP19
