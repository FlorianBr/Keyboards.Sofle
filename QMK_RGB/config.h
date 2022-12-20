#pragma once

#include "config_common.h"

// RGB LED Matrix configuration
#define MATRIX_ROWS 10
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 150                            // Redefine tapping time to 150ms
#define TAPPING_TOGGLE 2                            // Number of taps for tap toggle (Default: 5)
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10

// The encoder
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 2

// Split communication
#define SOFT_SERIAL_PIN D2

#define MASTER_LEFT                                 // Left is the master
#define SPLIT_WPM_ENABLE                            // Sync WPM state between sides (for NEKO)
#define ISMASTER                                    // Compile for master side

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
#define RGBLIGHT_EFFECT_TWINKLE                     // Twinkle Anim
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING                   // Breathing
// #define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT             // Enable static gradient mode
#endif // RGBLIGHT_ENABLE


#ifdef OLED_ENABLE
#define OLED_TIMEOUT 300000                         // OLED Timeout 5min
#define OLED_FONT_H "font.c"
#endif // OLED_ENABLE
