#include QMK_KEYBOARD_H

#define BASE     0
#define SECOND   1
#define MIDI     2
#define LPSWITCH 3
#define _ KC_TRNS


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [BASE] = LAYOUT_tkl(
      KC_GRV,      KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,      KC_PSCR,KC_SLCK,KC_BRK,
      KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS, KC_HOME,KC_PGUP,    
      KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_ENT,      KC_DEL, KC_END, KC_PGDN,    

      MT(MOD_LCTL, KC_ESC),KC_A,   KC_S,   LT(SECOND, KC_D),   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NUHS,                             
      KC_LSFT,KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,     MO(SECOND),          KC_UP,           
      MT(MOD_LCTL,KC_ESC),KC_LGUI,KC_LALT,          LT(MIDI, KC_SPC),                     KC_RALT,/*KC_RGUI*/ TO(MIDI),/*KC_APP*/ TO(MIDI), /*KC_RCTL*/TO(MIDI),     KC_LEFT,KC_DOWN,KC_RGHT
    ),

    [SECOND] = LAYOUT_tkl(
      _, _, _, _, _, _, _,  _,  _,  _,  _, _, _, _,_,_,
      _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,_,    
      _, _, _, _, _, _, _, KC_VOLD, KC_VOLU, _, _, _,_,_, _, _, _,    
      _, _, _, _, _, _, KC_LEFT,   KC_DOWN,   KC_UP,   KC_RIGHT,   _,_,_,                             
      _, _, _, _, _, _, KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,_, _,     _,          _,           
      _,_,_,          _,                     _,_,_, _,     _,_,_
    ),

    [MIDI] = LAYOUT_tkl(
      _, _, _, _, _, _, _,  _,  _,  _,  _, _, _, _,_,_,

      // Num row
      TO(BASE),
      MI_C, MI_Cs,  MI_D, MI_Ds, //lh
      MI_Gs_4,    MI_A_4, // midkeys
      MI_E,    MI_F,    MI_Fs,  MI_G,  //rh
      _, _, _, _, _, KC_M,

      // qwerty row
      /*MO(LPSWITCH)*/ TO(BASE), 
      MI_E_1,    MI_F_1,    MI_Fs_1,  MI_G_1,  //lh
      MI_As_4,    MI_B_4, //midkeys
      MI_Gs_1,    MI_A_1,    MI_As_1,  MI_B_1,  //rh
      _,_, _, _, _, _,


      //asdf row
      KC_M, 
      MI_Gs_2,    MI_A_2,    MI_As_2,  MI_B_2,  //lh
      MI_C_5,    MI_Cs_5, //midkeys
      MI_C_3, MI_Cs_3,  MI_D_3, MI_Ds_3, //rh
      _,_,                             


      //zxcv row
      _, _,
      MI_C_4,  MI_Cs_4, MI_D_4, MI_Ds_4, //lh
      MI_D_5, MI_Ds_5, //midkeys
      MI_E_4,    MI_F_4,    MI_Fs_4,  MI_G_4,  //rh
      _, _, 


      TO(BASE),_,MI_Cs_2, _, MI_Cs_2,_,_, _, _,_,_
    ),

};

void matrix_init_user(void) {
/*
        writePinHigh(B0);
        writePinHigh(B1);
        writePinHigh(B2);
        writePinHigh(B3);
        writePinHigh(B4);
        led_set_kb(B0);

*/
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {
/*
        writePinHigh(B0);
        writePinHigh(B1);
        writePinHigh(B2);
        writePinHigh(B3);
        writePinHigh(B4);
*/
}
