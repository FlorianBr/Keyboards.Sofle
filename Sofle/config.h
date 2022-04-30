/* 
 * Copyright 2022 Florian Brandner
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

// #define ISMASTER                                    // Compile for master side

#define SPLIT_WPM_ENABLE                            // Sync WPM state between sides (for NEKO)

#define MASTER_LEFT                                 // Left is the master

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 150                            // Redefine tapping time to 150ms

#define TAPPING_TOGGLE 2                            // Number of taps for tap toggle (Default: 5)

#ifdef RGBLIGHT_ENABLE                              // *** RGB Config ***
#define RGB_DI_PIN D3                               // LED Data Pin
#define RGBLED_NUM 72                               // 58 key LEDs, 12 drop lights, 2 indicators
#define RGBLED_SPLIT { 36, 36 }                     // 36 LEDs on each side

#define RGBLIGHT_LIMIT_VAL 150                      // Max. Brightness
#define RGBLIGHT_HUE_STEP 5                         // Step size 
#define RGBLIGHT_SAT_STEP 10                        // Step size 
#define RGBLIGHT_VAL_STEP 10                        // Step size 
#define RGBLIGHT_SLEEP                              // LEDs OFF on sleep
#define RGBLIGHT_LAYERS                             // Enable RGB layers

// Enable specific animations. All of them wont fit
// #define RGBLIGHT_EFFECT_TWINKLE                     // Twinkle Anim
// #define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING                   // Breathing
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT             // Enable static gradient mode

#endif  // RGBLIGHT_ENABLE


#ifdef OLED_ENABLE
#define OLED_TIMEOUT 300000                         // OLED Timeout 5min
#define OLED_FONT_H "font.c"
#endif
