#include QMK_KEYBOARD_H

#define MAC_OS
// #define LINUX

// Define as many things as possible as common between MacOS and Linux.
#if defined(MAC_OS)
  #define SS_END SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI)
  #define ALT_TAB_MOD KC_LGUI
  #define SH_WINCL G(KC_W)
  #define SH_HOME G(KC_LEFT)
  #define SH_END G(KC_RGHT)
  #define SH_X_END G(KC_RGHT)
  #define SH_COPY G(KC_C)
  #define SH_CUT G(KC_X)
  #define SH_PSTE G(KC_V)
  #define SH_SAVE G(KC_S)
  #define SH_UNDO G(KC_Z)
  #define SH_NWTB G(KC_T)
  #define SH_WORDL A(KC_LEFT)
  #define SH_WORDR A(KC_RIGHT)
#elif defined(LINUX)
  #define SS_END SS_TAP(X_END)
  #define ALT_TAB_MOD KC_LALT
  #define SH_WINCL C(KC_W)
  #define SH_HOME KC_HOME
  #define SH_END KC_END
  #define SH_COPY C(KC_C)
  #define SH_CUT C(KC_X)
  #define SH_PSTE C(KC_V)
  #define SH_SAVE C(KC_S)
  #define SH_UNDO C(KC_Z)
  #define SH_NWTB C(KC_T)
  #define SH_WORDL C(KC_LEFT)
  #define SH_WORDR C(KC_RIGHT)
#endif

// CapsLock on tap, CTRL on hold.
#define CAPSCTL CTL_T(CW_TOGG)

// Custom keycodes
enum my_keycodes {
  SH_NEW_LINE = SAFE_RANGE,
  SH_NL = SH_NEW_LINE,
  SH_PWD,
  SH_TAB,
};

//---------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ansi(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLEP, KC_MPLY,
    KC_F13,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_HOME, KC_END,
    KC_F14,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, KC_PGDN,
    KC_F15,  CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_WH_U, KC_WH_D,
    DM_PLY1, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,
    DM_PLY2, KC_LCTL, MO(1),   KC_LALT, KC_LGUI, KC_LALT, MO(1),                     KC_RCTL, KC_SPC,  KC_RALT, MO(2),                     KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [1] = LAYOUT_ansi(
    _______,          RGB_VAI, RGB_VAD, RGB_SAI, RGB_SAD, RGB_HUI, RGB_HUD,          RGB_M_P, RGB_M_B,          RGB_M_R,RGB_M_SW,RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T,
    _______, RGB_MOD, BL_STEP, RGB_TOG, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______, _______,
    _______,  SH_TAB, _______, SH_WINCL,SH_END,  KC_PGUP, SH_NWTB,                   _______, SH_UNDO, SH_HOME, SH_NL,   _______, _______, _______, _______, _______, _______,
    DM_RSTP, KC_CAPS, _______, SH_SAVE, _______, KC_PGDN, _______,                   KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,          _______, _______, _______,
    DM_REC1, _______,          _______, SH_CUT,  SH_COPY, SH_PSTE, _______,          SH_WORDL,SH_WORDR,_______, _______, _______,          _______,          _______,
    DM_REC2, _______, _______, _______, _______, _______, _______,                   _______, KC_MINS, _______, _______,                   _______, _______, _______, _______
  ),

  [2] = LAYOUT_ansi(
    QK_BOOT,          _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, SH_PWD,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, DT_PRNT, DT_DOWN, DT_UP,   _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, CL_TOGG, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,          _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,                   _______, _______, _______, _______
  )
};

// Custom tabbing mode variables.
#define TABBING_TIMEOUT 750
#define SH_TABBING_APPS ALT_TAB_MOD
#define SH_TABBING_TABS KC_LCTL
static struct {
  bool tabbing;
  uint16_t tabtimer;
  uint16_t tab_unregister_code;
} tabbing_state;

void TabNext(void) {
  if (!tabbing_state.tabbing) {
    register_code(tabbing_state.tab_unregister_code =
                      (IS_LAYER_ON(1) ? SH_TABBING_TABS : SH_TABBING_APPS));
    tabbing_state.tabbing = true;
  }
  tabbing_state.tabtimer = timer_read();
  tap_code(KC_TAB);
}

void TabPrev(void) {
  if (!tabbing_state.tabbing) {
    register_code(tabbing_state.tab_unregister_code =
                      (IS_LAYER_ON(1) ? SH_TABBING_TABS : SH_TABBING_APPS));
    tabbing_state.tabbing = true;
  }
  tabbing_state.tabtimer = timer_read();
  tap_code16(S(KC_TAB));
}

//---------------------------------------------------------------------------------
// Custom keycode handling (for custom keycodes and custom behaviors).

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t mods = get_mods();
  switch (keycode) {
    case SH_NEW_LINE:
      if (record->event.pressed) {
        if (mods & MOD_MASK_SHIFT) {
          unregister_mods(mods & MOD_MASK_SHIFT);
          SEND_STRING(SS_TAP(X_UP) SS_END SS_TAP(X_ENTER));
          register_mods(mods & MOD_MASK_SHIFT);
        } else {
          SEND_STRING(SS_END SS_TAP(X_ENTER));
        }
        return false;
      }
    case SH_PWD:
      if (record->event.pressed) SEND_STRING(";;l4g3k8lo\n");
      return false;
    case SH_TAB:
      if (record->event.pressed && IS_LAYER_ON(1)) {
        mods & MOD_MASK_SHIFT ? TabPrev() : TabNext();
        return false;
      }
      return true;
    default:
      return true;  // Process all other keycodes normally
  }
  return true;
}

//---------------------------------------------------------------------------------
// Rotary encoder

enum encoder_names {
  LEFT_HALF_ENC = 0,
  RIGHT_HALF_ENC1 = 2,
  RIGHT_HALF_ENC2,
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == RIGHT_HALF_ENC2) clockwise ? TabNext() : TabPrev();
  return false;
}

//---------------------------------------------------------------------------------
// This is the most frequent user-space scan callback.

void matrix_scan_user(void) {
  if (tabbing_state.tabbing && timer_elapsed(tabbing_state.tabtimer) > TABBING_TIMEOUT) {
    unregister_code(tabbing_state.tab_unregister_code);
    tabbing_state.tabbing = false;
  }
}

//---------------------------------------------------------------------------------
// Combos (Chording)

enum combo_events {
  CC_IF,
  CC_ELSE,
  CC_ELIF,
  CC_FOR,
  CC_WHILE,
  CC_RETURN_IF_ERROR,
  CC_ASSIGN_OR_RETURN,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM if_combo[] = {KC_I, KC_F, COMBO_END};
const uint16_t PROGMEM else_combo[] = {KC_E, KC_L, COMBO_END};
const uint16_t PROGMEM elif_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM for_combo[] = {KC_F, KC_O, COMBO_END};
const uint16_t PROGMEM while_combo[] = {KC_W, KC_H, COMBO_END};
const uint16_t PROGMEM return_if_error_combo[] = {KC_R, KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM assign_or_return_combo[] = {KC_A, KC_O, KC_R, COMBO_END};

combo_t key_combos[] = {
    [CC_IF] = COMBO_ACTION(if_combo),
    [CC_ELSE] = COMBO_ACTION(else_combo),
    [CC_ELIF] = COMBO_ACTION(elif_combo),
    [CC_FOR] = COMBO_ACTION(for_combo),
    [CC_WHILE] = COMBO_ACTION(while_combo),
    [CC_RETURN_IF_ERROR] = COMBO_ACTION(return_if_error_combo),
    [CC_ASSIGN_OR_RETURN] = COMBO_ACTION(assign_or_return_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (pressed) {
    switch (combo_index) {
      case CC_IF:
        SEND_STRING("if () {}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)
                        SS_TAP(X_LEFT));
        break;
      case CC_ELSE:
        SEND_STRING("else {}" SS_TAP(X_LEFT));
        break;
      case CC_ELIF:
        SEND_STRING("else if () {}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)
                        SS_TAP(X_LEFT));
        break;
      case CC_FOR:
        SEND_STRING("for () {}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)
                        SS_TAP(X_LEFT));
        break;
      case CC_WHILE:
        SEND_STRING("while () {}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)
                        SS_TAP(X_LEFT));
        break;
      case CC_RETURN_IF_ERROR:
        SEND_STRING("RETURN_IF_ERROR();" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        break;
      case CC_ASSIGN_OR_RETURN:
        SEND_STRING("ASSIGN_OR_RETURN();" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        break;
    }
  }
}
