
#include "sofle_choc.h"

#ifdef RGB_MATRIX_ENABLE
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  // 12 13 22 23 32 33       33 32 23 22 13 12  0
  //    02    03    04       04    03    02
  // 11 14 21 24 31 34       34 31 24 21 14 11  1
  //                01       01
  // 10 15 20 25 30 35       35 30 25 20 15 10  2
  //
  // 09 16 19 26 29 36       36 29 26 19 16 09  3
  //
  //     08 17 18 27 28     28 27 18 17 08      4
  //    07    06    05       05    06    07

led_config_t g_led_config = {
    // Key Matrix to LED Index
    {
        { 28, 21, 20, 11, 10,      0 },
        { 27, 22, 19, 12,  9,      1 },
        { 26, 23, 18, 13,  8,      2 },
        { 25, 24, 17, 14,  7,      3 },
        { 16, 15,  6,  5,  4, NO_LED },
        // Right
        { 57, 50, 49, 40, 39,     29 },
        { 56, 51, 48, 41, 38,     30 },
        { 55, 52, 47, 42, 37,     31 },
        { 54, 53, 46, 43, 36,     32 },
        { 45, 44, 35, 34, 33, NO_LED }
    },
    // LED Index to Physical Position
    {
        // LEFT
        {  95,   7 }, {  95,  21 }, {  95,  36 }, {  95,  50 }, { 115,  64 },
        {  95,  64 }, {  76,  62 }, {  76,  48 }, {  76,  33 }, {  76,  19 },
        {  76,   5 }, {  57,   3 }, {  57,  17 }, {  57,  31 }, {  57,  46 },
        {  57,  62 }, {  38,  64 }, {  38,  48 }, {  38,  33 }, {  38,  19 },
        {  38,   5 }, {  19,   7 }, {  19,  21 }, {  19,  36 }, {  19,  50 },
        {   0,  50 }, {   0,  36 }, {   0,  21 }, {   0,   7 },

        // RIGHT
        { 129,   7 }, { 129,  21 }, { 129,  36 }, { 129,  50 }, { 119, 64 },
        { 129,  64 }, { 148,  62 }, { 148,  48 }, { 148,  33 }, { 148, 19 },
        { 148,   5 }, { 167,   3 }, { 167,  17 }, { 167,  31 }, { 167, 46 },
        { 167,  62 }, { 186,  64 }, { 186,  48 }, { 186,  33 }, { 186, 19 },
        { 186,   5 }, { 209,   7 }, { 209,  21 }, { 209,  36 }, { 209, 50 },
        { 224,  50 }, { 224,  36 }, { 224,  21 }, { 224,   7 }
    },
    // LED Index to Flag
    {
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};
#endif  // RGB_MATRIX_ENABLE
