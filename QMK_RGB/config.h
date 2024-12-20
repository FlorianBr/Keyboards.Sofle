#pragma once

/****** Main Build Configuration */
/* To save flash the build for left and right sides
 * are different! Therefore we need to specify what
 * side we want to compile here
 */
// #define IS_LEFT                                     // We want to build the LEFT side
#define IS_RIGHT                                    // We want to build the RIGHT side

#define MASTER_LEFT                                 // Left is the master

/****** Unicode Input Mode */
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

/****** Split Configuration */
#define SPLIT_WPM_ENABLE                            // Sync WPM state between sides (for NEKO)
#define SOFT_SERIAL_PIN D2                          // Serial connection
#define SPLIT_LAYER_STATE_ENABLE                    // For layer-dependend key LEDs

/****** Features: Tapping */
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 150                            // Redefine tapping time to 150ms
#define TAPPING_TOGGLE 2                            // Number of taps for tap toggle (Default: 5)
#define TAP_CODE_DELAY 10                           // Delay in between register and unregister_code

/****** Features: Caps Word */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD              // Turn on on left+right shift

/****** Hardware: Encoder */
#define ENCODER_RESOLUTION 2

/****** Hardware: LEDs */
#define WS2812_DI_PIN D3                            // LED Data Pin
#define RGBLED_NUM 72                               // 58 key LEDs, 12 drop lights, 2 indicators


#ifdef RGB_MATRIX_ENABLE                            // *** RGB Matrix Config ***
#define RGB_MATRIX_LED_COUNT RGBLED_NUM
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120           // Maximum brightness
#define RGB_MATRIX_HUE_STEP 8                       // Step sizes for inc/dec
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#define RGB_MATRIX_KEYPRESSES                       // Reacts to keypresses
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS              // Enable framebuffer effects
#define RGB_MATRIX_SPLIT {36,36}                    // 36 LEDs on each side
#define SPLIT_TRANSPORT_MIRROR                      // Mirror master to slave
#define RGB_MATRIX_SLEEP                            // Turn off when suspended

// Enabled effects
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif

#ifdef OLED_ENABLE
#define OLED_TIMEOUT 300000                         // OLED Timeout 5min
#define OLED_FONT_H "font.c"
#endif // OLED_ENABLE
