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
 *
 *************************************************
 * Keymap for the Sofle RGB, based on the design made by Dane Evans
 */


#include <stdio.h>
#include "config.h"


#include QMK_KEYBOARD_H

#define LOGO_TIMEOUT        2000          // Timeout for the logo display
#define MIN_WALK_SPEED      10            // WPM Threshold for walk anim
#define MIN_RUN_SPEED       40            // WPM Threshold for run anim
#define SPRITE_DURATION     500           // Length in ms for a sprite
#define SPRITE_SIZE         128           // Size of one sprite in byte

#ifndef IS_LEFT
#ifndef IS_RIGHT
#error No side defined!
#endif
#endif


enum layers {
    _STD = 0,
    _ALT,
    _SET,
    _CRS,
    NUM_LAYERS  // not a layer but used in the code. Must be last entry
};

 /**************************************************** CUSTOM KEYCODES */

enum custom_keycodes {
     UML_A = SAFE_RANGE,
     UML_U,
     UML_O,
  BRK_L1,
  BRK_R1,
  BRK_L2,
     BRK_R2,
     ESIGN
 };

/**************************************************** THE LAYERS */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_STD] = LAYOUT(
  //,---------------------------------------------------.                     ,-----------------------------------------------------.
     KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    LT(_SET,KC_TAB),KC_Q,KC_W,    KC_F,    KC_P,    KC_G,                          KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,MO(_CRS),
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     LT(_ALT,KC_PAUSE),    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                          KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     KC_DEL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,    _______,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
                      KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT,   KC_SPC,     KC_ENT, KC_RSFT, KC_RALT,  KC_EQL, KC_MINS
  //                \--------+--------+--------+--------+---------|   |-------+--------+--------+--------+-------/
),
  [_ALT] = LAYOUT(
  //,---------------------------------------------------.                     ,-----------------------------------------------------.
    KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                       _______, _______,   UML_U, _______, _______,  KC_F12,
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     _______,   UML_A, _______, _______, _______, _______,                        BRK_L1 , BRK_R1,   ESIGN, _______,   UML_O, _______,
  //|------+--------+--------+--------+--------+--------|  =====  |   |  ===  |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______ ,_______, _______,  _______,    _______,  BRK_L2,  BRK_R2, _______, _______, _______, _______,
  //|------+--------+--------+--------+--------+--------|  =====  |   |  ===  |--------+--------+--------+--------+--------+--------|
                      _______, _______, _______, _______,  _______,    _______, KC_PSCR, _______, _______, _______
  //                \--------+--------+--------+--------+---------|   |-------+--------+--------+--------+-------/
),
  [_SET] = LAYOUT(
  //,---------------------------------------------------.                     ,-----------------------------------------------------.
    RGB_TOG,RGB_RMOD, RGB_MOD, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______,                       _______, _______, _______, _______, _______, _______,
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______,                       _______, _______, _______, _______, _______, _______,
  //|------+--------+--------+--------+--------+--------|  =====  |   |  ===  |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|------+--------+--------+--------+--------+--------|  =====  |   |  ===  |--------+--------+--------+--------+--------+--------|
                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //                \--------+--------+--------+--------+---------|   |-------+--------+--------+--------+-------/
),
  [_CRS] = LAYOUT(
  //,---------------------------------------------------.                     ,-----------------------------------------------------.
    _______, _______, _______,_______,_______,_______,                          _______, _______, _______, _______, _______, _______,
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______, KC_HOME,   KC_UP,  KC_END, _______, KC_PGUP,                       _______, _______, _______, _______, _______, _______,
  //|------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, KC_PGDN,                       _______, _______, _______, _______, _______, _______,
  //|------+--------+--------+--------+--------+--------|  =====  |   |  ===  |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|------+--------+--------+--------+--------+--------|  =====  |   |  ===  |--------+--------+--------+--------+--------+--------|
                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //                \--------+--------+--------+--------+---------|   |-------+--------+--------+--------+-------/
),
};

// clang-format on

/**************************************************** KEYCODE PROCESSING */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
     case UML_A:
        if (record->event.pressed) {
          tap_code(KC_PAUSE);
          tap_code(KC_A);
          register_code(KC_RIGHT_SHIFT);
          tap_code(KC_QUOTE);
          unregister_code(KC_RIGHT_SHIFT);
        } else {
        }
        break;
     case UML_U:
         if (record->event.pressed) {
           tap_code(KC_PAUSE);
           tap_code(KC_U);
           register_code(KC_RIGHT_SHIFT);
           tap_code(KC_QUOTE);
           unregister_code(KC_RIGHT_SHIFT);
         } else {
         }
         break;
     case UML_O:
         if (record->event.pressed) {
           tap_code(KC_PAUSE);
           tap_code(KC_O);
           register_code(KC_RIGHT_SHIFT);
           tap_code(KC_QUOTE);
           unregister_code(KC_RIGHT_SHIFT);
         } else {
         }
         break;
     case ESIGN:
        if (record->event.pressed) {
          tap_code(KC_PAUSE);
          tap_code(KC_C);
          tap_code(KC_EQUAL);

        } else {
        }
        break;
    case BRK_L1:  // Left Bracket 1: [
        if (record->event.pressed) {
            tap_code(KC_LEFT_BRACKET);
        } else {
        }
        break;
    case BRK_R1:  // Right Bracket 1: [
        if (record->event.pressed) {
            tap_code(KC_RIGHT_BRACKET);
        } else {
        }
        break;
    case BRK_L2:  // Left Bracket 2: {
        if (record->event.pressed) {
            register_code(KC_RIGHT_SHIFT);
            tap_code(KC_LEFT_BRACKET);
            unregister_code(KC_RIGHT_SHIFT);
        } else {
        }
        break;
    case BRK_R2:  // Right Bracket 2: }
        if (record->event.pressed) {
            register_code(KC_RIGHT_SHIFT);
            tap_code(KC_RIGHT_BRACKET);
            unregister_code(KC_RIGHT_SHIFT);
        } else {
        }
        break;
    } // end switch
    return true;
};

/**************************************************** THE ENCODER */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {           // First encoder (Left Side)
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) {    // Second encoder (Right Side)
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  }
  return true;
}
#endif // ENCODER_ENABLE

/**************************************************** OLEDs */
#ifdef OLED_ENABLE
static uint32_t sleep_timer;
#ifdef IS_LEFT
static void print_left(void) {

  // Note: Do not use snprintf, it needs too much flash

  // OLED Sleep Mode
  if (get_current_wpm() > 0) {
    oled_on();
    sleep_timer = timer_read32();
  } else if (timer_elapsed32(sleep_timer) > OLED_TIMEOUT) {
    oled_off();
  }

  if (is_oled_on()) {
    oled_set_cursor(0, 1);

    // Standard Layer: TUX Logo
    if (get_highest_layer(layer_state) == _STD) {
        oled_write_P(PSTR("  "), false);
        oled_write_char(0x99, false);
        oled_write_char(0x9A, false);
        oled_write_P(PSTR("   "), false);
        oled_write_char(0xB9, false);
        oled_write_char(0xBA, false);
        oled_write_ln_P(PSTR("  "), false);
    }
    // ALT Functions Layer: Layer name
    else if (IS_LAYER_ON(_ALT)) {
      oled_write_ln_P(PSTR(" Alt "), true);
    }
    // SET Functions Layer: Layer name plus current RGB Mode
    else if (IS_LAYER_ON(_SET)) {
      oled_write_ln_P(PSTR(" Set "), true);
      uint8_t Tens, Ones;

      oled_write_char('M', false);
      oled_write_char('=', false);

      Tens = rgb_matrix_get_mode()/10;
      Ones = rgb_matrix_get_mode() - 10*Tens;
      if (0==Tens) oled_write_char('0', false); else oled_write_char('0'+Tens, false);
      if (0==Ones) oled_write_char('0', false); else oled_write_char('0'+Ones, false);
    }
    // CRS Functions Layer: Layer name
    else if (IS_LAYER_ON(_CRS)) {
      oled_write_ln_P(PSTR(" Crs "), true);
    }

    // Modifier keys
    oled_set_cursor(0, 15);
    if (get_mods() & MOD_MASK_SHIFT) {  oled_write_char('S', true);    } else { oled_write_char(' ', false); }
    if (get_mods() & MOD_MASK_CTRL) {   oled_write_char('C', true);    } else { oled_write_char(' ', false); }
    if (get_mods() & MOD_MASK_GUI) {    oled_write_char('G', true);    } else { oled_write_char(' ', false); }
    if (get_mods() & MOD_MASK_ALT) {    oled_write_char('A', true);    } else { oled_write_char(' ', false); }
    if (is_caps_word_on()) {            oled_write_char('W', true);    } else { oled_write_char(' ', false); }
  } // is_oled_on
} // print_left()

#else // IS_LEFT

#ifdef WPM_ENABLE
static uint32_t anim_timer = 0;       // animation timer
static uint8_t current_frame = 0;     // current frame
static bool isawake = false;          // Awake anim?

static void render_neko(int PosX, int PosY) {
  static const char PROGMEM awake[SPRITE_SIZE] = {
    0x01, 0x40, 0x40, 0x80, 0x80, 0x04, 0x08, 0x10, 0x20, 0x00, 0xc0, 0x30, 0x08, 0x10, 0x60, 0x80, 0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc0, 0x00, 0x10, 0x08, 0x04, 0x80, 0x80, 0x40, 0x40, 0x00, 0x08, 0x08, 0x08, 0x08, 0x00, 0x01, 0x01, 0x00, 0x00, 0x7f, 0x80, 0x40, 0x40, 0x5c, 0x00, 0x01, 0x41, 0x01, 0x00, 0x5c, 0x40, 0x40, 0x80, 0x7f, 0x00, 0x01, 0x01, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0xe1, 0x12, 0x0a, 0x06, 0x00, 0x80, 0x00, 0x06, 0x0a, 0x12, 0xe1, 0x90, 0x48, 0x64, 0x92, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x11, 0x10, 0x10, 0x14, 0x14, 0x1f, 0x18, 0x00, 0x00, 0x00, 0x00
  };
  static const char PROGMEM kaki[][SPRITE_SIZE] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x1a, 0x22, 0xc2, 0x04, 0x04, 0x04, 0x07, 0x00, 0xc0, 0x20, 0x10, 0x80, 0x80, 0x01, 0x01, 0x02, 0xfc, 0xfe, 0x02, 0x3c, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0d, 0x8d, 0x55, 0x50, 0x94, 0xf0, 0x10, 0x09, 0x08, 0x00, 0x80, 0x00, 0x06, 0x09, 0x1b, 0xee, 0x00, 0x00, 0x00, 0x00, 0x81, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x19, 0x18, 0x1c, 0x14, 0x16, 0x15, 0x14, 0x14, 0x14, 0x14, 0x08,  },
    { 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x01, 0x02, 0x04, 0x04, 0x03, 0x80, 0x40, 0x40, 0x20, 0x00, 0x01, 0x02, 0x8c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0d, 0x8d, 0x55, 0x50, 0x94, 0xf0, 0x10, 0x0a, 0x0e, 0x1d, 0x95, 0x24, 0x24, 0x27, 0x13, 0xe1, 0x01, 0x01, 0x01, 0x01, 0x02, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x19, 0x18, 0x1c, 0x14, 0x14, 0x17, 0x14, 0x14, 0x14, 0x14, 0x08 }
  };
  // static const char PROGMEM mati[][SPRITE_SIZE] = {
  //   { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x08, 0x10, 0x60, 0x80, 0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x40, 0x40, 0x5c, 0x00, 0x01, 0x41, 0x01, 0x00, 0x5c, 0x40, 0x40, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0xe1, 0x12, 0x0a, 0x06, 0x00, 0x80, 0x00, 0x06, 0x0a, 0x12, 0xe1, 0x80, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x11, 0x10, 0x10, 0x14, 0x14, 0x1f, 0x1c, 0x14, 0x14, 0x14, 0x08,  },
  //   { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x08, 0x10, 0x60, 0x80, 0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x90, 0x12, 0x0a, 0x02, 0xf4, 0x09, 0x0d, 0xf1, 0x04, 0x02, 0x0a, 0x12, 0x90, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0xe1, 0x12, 0x0a, 0x06, 0x01, 0x81, 0x00, 0x06, 0x0a, 0x12, 0xe1, 0x80, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x11, 0x10, 0x10, 0x14, 0x14, 0x1f, 0x1c, 0x14, 0x14, 0x14, 0x08 }
  // };
  static const char PROGMEM run[][SPRITE_SIZE] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x10, 0x10, 0x08, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x10, 0x88, 0x44, 0x22, 0x99, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x13, 0x0c, 0x08, 0x08, 0x04, 0x04, 0x82, 0x39, 0x47, 0x80, 0x00, 0x03, 0x02, 0x01, 0x00, 0x00, 0x01, 0xc2, 0xfc, 0xf0, 0xc0, 0x00, 0x30, 0xd0, 0x50, 0x58, 0x28, 0x16, 0x09, 0x80, 0x80, 0xc4, 0xc2, 0x62, 0x26, 0x44, 0x44, 0x40, 0x43, 0x40, 0x20, 0x17, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x03, 0x06, 0x07, 0x01, 0x01, 0x01, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  },
    { 0x38, 0x48, 0x88, 0x30, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x0e, 0x00, 0x00, 0x01, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0x10, 0x20, 0x30, 0x0c, 0x06, 0x01, 0x01, 0x40, 0x40, 0x40, 0x40, 0x1d, 0x01, 0x02, 0x1c, 0xe0, 0x00, 0xf8, 0x88, 0xc6, 0xe1, 0xe0, 0x60, 0x60, 0x70, 0x70, 0x30, 0x28, 0x68, 0x44, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0xe0, 0xe0, 0xc0, 0x80, 0x8c, 0x1c, 0x32, 0x62, 0xc2, 0x82, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x01, 0x01, 0x02, 0x02, 0x03, 0x01, 0x00, 0x00 }
  };
  static const char PROGMEM sleep[][SPRITE_SIZE] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0xa8, 0x48, 0xa8, 0x18, 0x08, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x80, 0x44, 0x84, 0x06, 0x05, 0x04, 0x80, 0x40, 0x20, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x18, 0x04, 0x04, 0x02, 0x7a, 0x86, 0x01, 0x80, 0x80, 0x01, 0x03, 0x05, 0x07, 0x01, 0x00, 0x00, 0x80, 0x83, 0x45, 0xfa, 0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x33, 0x24, 0x28, 0x28, 0x29, 0x29, 0x29, 0x3a, 0x18, 0x1c, 0x39, 0x24, 0x24, 0x3a, 0x2d, 0x26, 0x31, 0x1f, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0x3a, 0x2a, 0x26, 0x22, 0x80, 0xc0, 0x80, 0x00, 0x24, 0x34, 0x2c, 0xe4, 0x60, 0x10, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38, 0x04, 0x02, 0x02, 0x01, 0x79, 0x87, 0x01, 0x80, 0x81, 0x83, 0x05, 0x05, 0x03, 0x01, 0x00, 0x00, 0x80, 0x43, 0x05, 0xfa, 0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x33, 0x24, 0x28, 0x28, 0x28, 0x29, 0x29, 0x3a, 0x18, 0x1c, 0x39, 0x24, 0x24, 0x3a, 0x2d, 0x26, 0x31, 0x1f, 0x00 },
  };

  // Animation timer
  if (timer_elapsed32(anim_timer) > SPRITE_DURATION) {
    anim_timer = timer_read32();
    current_frame = (current_frame + 1) % 2;  // toggle frame

    oled_set_cursor(PosX, PosY);

    // State of caps word is not synced, wont work on right side
    // if (caps_word_get()) {
    //   oled_write_raw_P(mati[abs(1 - current_frame)], SPRITE_SIZE);
    // } else

    if (get_current_wpm() <= MIN_WALK_SPEED) {
      oled_write_raw_P(sleep[abs(1 - current_frame)], SPRITE_SIZE);
      isawake = false;
    } else if (get_current_wpm() <= MIN_RUN_SPEED) {
      if (!isawake) {
        oled_write_raw_P(awake, SPRITE_SIZE);
      } else {
        oled_write_raw_P(kaki[abs(1 - current_frame)], SPRITE_SIZE);
      }
      isawake = true;
    } else {
      oled_write_raw_P(run[abs(1 - current_frame)], SPRITE_SIZE);
    }
  } // timer elapsed
}  // render_neko
#endif  // WPM_ENABLE

extern oled_rotation_t oled_rotation;

static void print_right(void) {

  // static const char PROGMEM logo[] = {
  //   0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
  //   0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
  // };

  if (get_current_wpm() > 0) {
    oled_on();
    sleep_timer = timer_read32();
  } else if (timer_elapsed32(sleep_timer) > OLED_TIMEOUT) {
    oled_off();
  }

  if (is_oled_on()) {
    // if (oled_rotation != OLED_ROTATION_180) oled_init(OLED_ROTATION_180);  // Orientation for Logo
    // oled_write_P(logo, false);

    if (oled_rotation != OLED_ROTATION_270) oled_init(OLED_ROTATION_270);  // Orientation for status
#ifdef WPM_ENABLE
      oled_set_cursor(0, 1);
    if (get_current_wpm()>0) {
      uint8_t Huns, Tens, Ones;
      Huns = get_current_wpm()/100;
      Tens = get_current_wpm()/10 - 10*Huns;
      Ones = get_current_wpm() - 10*Tens - 100*Huns;

      if (0==Huns) oled_write_char(' ', false); else oled_write_char('0'+Huns, false);
      if ((0==Tens) && (Huns>0))
        oled_write_char('0', false);
      else if (Tens==0)
        oled_write_char(' ', false);
      else oled_write_char('0'+Tens, false);


      if (0==Ones) oled_write_char('0', false); else oled_write_char('0'+Ones, false);
    } else {
      oled_write_ln_P(PSTR("     "), false);
    }
    render_neko(0, 3);
#endif  // WPM_ENABLE
  } // is_oled_on
} // print_right()
#endif

bool oled_task_user(void) {
#ifdef IS_LEFT
  print_left();
#else
  print_right();
#endif
  return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#ifdef IS_LEFT
  return OLED_ROTATION_270;
#endif
  // Orientation of slave is handled in the display function
  return rotation;
}
#endif // OLED_ENABLE


// /**************************************************** RGB Light Layers */
#ifdef RGB_MATRIX_ENABLE
// Downlight: Blue
// Keylights:
//    Standard Layer: Configured Effect, blue downlights
//    ALT Layer:      RED for special keys
//    Cursor Layer:   GREEN for special keys
 //    Setting Layer:  PURPLE for special keys
//
// Note: The RGB variable stores in different byte order, so the order in the
// set_color call is different!
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  // Target color for key and downlight leds (one for every layer)
  RGB ledcol[NUM_LAYERS] = { {RGB_BLUE}, {RGB_RED}, {RGB_PURPLE}, {RGB_GREEN} } ;
  uint8_t layer = get_highest_layer(layer_state);

  // For special layers: Set the key LEDs, overwriting effects
  if (layer > _STD) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t index = g_led_config.matrix_co[row][col];

        // Valid LED on that position?
        if ((index >= led_min) && (index < led_max) && (index != NO_LED)) {
          // Highlight keys with special functions
          if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
            rgb_matrix_set_color(index, ledcol[layer].g, ledcol[layer].r, ledcol[layer].b);
          }
        }
      }
    }
  }

  // All layers: Underglow and Indicators (with reduced intensity)
  for (uint8_t i = led_min; i < led_max; i++) {
    if (g_led_config.flags[i] == LED_FLAG_UNDERGLOW) {
      rgb_matrix_set_color(i, ledcol[layer].g, ledcol[layer].r, ledcol[layer].b);
    }
    if (g_led_config.flags[i] == LED_FLAG_INDICATOR) {
      rgb_matrix_set_color(i, ledcol[layer].g>>4, ledcol[layer].r>>4, ledcol[layer].b>>4);
    }
  }

  return false;
}
#endif // RGB_MATRIX_ENABLE
