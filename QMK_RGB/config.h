#pragma once

#include "config_common.h"

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
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 2

/****** Hardware: Key Matrix */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

/****** Hardware: LEDs */
#define RGB_DI_PIN D3                               // LED Data Pin
#define RGBLED_NUM 72                               // 58 key LEDs, 12 drop lights, 2 indicators

#ifdef RGB_MATRIX_ENABLE                            // *** RGB Matrix Config ***
#define RGB_MATRIX_LED_COUNT RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120           // Maximum brightness
#define RGB_MATRIX_HUE_STEP 8                       // Step sizes for inc/dec
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#define RGB_MATRIX_KEYPRESSES                       // Reacts to keypresses
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS              // Enable framebuffer effects
#define RGB_MATRIX_SPLIT {36,36}                    // 36 LEDs on each side
#define SPLIT_TRANSPORT_MIRROR                      // Mirror master to slave
#define RGB_DISABLE_WHEN_USB_SUSPENDED              // Turn off when suspended

// Enabled effects
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL      
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT  
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL  
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT 
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL    
// #define ENABLE_RGB_MATRIX_CYCLE_ALL          
// #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT   
// #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN      
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL  
// #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON 
// #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL      
// #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL        
// #define ENABLE_RGB_MATRIX_DUAL_BEACON 
// #define ENABLE_RGB_MATRIX_RAINBOW_BEACON      
// #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS   
// #define ENABLE_RGB_MATRIX_RAINDROPS           
// #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS 
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP     
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN        
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS 
// #define ENABLE_RGB_MATRIX_SPLASH        
// #define ENABLE_RGB_MATRIX_MULTISPLASH        
#define ENABLE_RGB_MATRIX_SOLID_SPLASH       
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#ifdef OLED_ENABLE
#define OLED_TIMEOUT 300000                         // OLED Timeout 5min
#define OLED_FONT_H "font.c"
#endif // OLED_ENABLE
