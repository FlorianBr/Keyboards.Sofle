#pragma once

/****** Main Build Configuration */
/* To save flash the build for left and right sides
 * are different! Therefore we need to specify what
 * side we want to compile here
 */
#define IS_LEFT                                     // We want to build the LEFT side
// #define IS_RIGHT                                    // We want to build the RIGHT side

#define MASTER_LEFT                                 // Left is the master

/****** Split Configuration */
#define SPLIT_WPM_ENABLE                            // Sync WPM state between sides (for NEKO)
#define SPLIT_LAYER_STATE_ENABLE                    // For layer-dependent key LEDs

/****** Features: Tapping */
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif

/****** Features: Caps Word */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD              // Turn on on left+right shift

/****** Hardware: Encoder */
#define ENCODER_RESOLUTION 2

/****** Hardware: LEDs */
// #define RGBLED_NUM 72                               // 58 key LEDs, 12 drop lights, 2 indicators


#ifdef RGB_MATRIX_ENABLE                            // *** RGB Matrix Config ***
// #define RGB_MATRIX_LED_COUNT RGBLED_NUM
// #define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120           // Maximum brightness
#define RGB_MATRIX_HUE_STEP 8                       // Step sizes for inc/dec
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#define RGB_MATRIX_KEYPRESSES                       // Reacts to keypresses
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS              // Enable framebuffer effects

// Enabled effects
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif

#ifdef OLED_ENABLE
#define OLED_TIMEOUT 300000                         // OLED Timeout 5min
#define OLED_FONT_H "font.c"
#endif // OLED_ENABLE
