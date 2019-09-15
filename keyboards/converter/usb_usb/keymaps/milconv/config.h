/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU|
 * |-----------------------------------------------------------| |-----------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Retn| |Del|End|PgD|
 * |------------------------------------------------------`    | `-----------'
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|    |              
 * |-----------------------------------------------------------|     ,---.    
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |    
 * |-----------------------------------------------------------| ,-----------.
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig|
 * `-----------------------------------------------------------' `-----------'
 */
#define LAYOUT_tkl( \
    K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,  K46,K47,K48,  \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K2A,  K49,K4A,K4B,  \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,K28,  K4C,K4D,K4E,  \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,K32,                    \
    KE1,K64,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    KE5,      K52,      \
    KE0,KE3,KE2,        K2C,                KE6,KE7,K65,KE4,  K50,K51,K4F  \
) LAYOUT_all(                                                                                                                                                                                \
                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                                                        \
    K29,          K3A,   K3B,   K3C,   K3D,   K3E,   K3F,   K40,   K41,   K42,   K43,   K44,   K45,             K46,   K47,   K48,      KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,                \
    K35,   K1E,   K1F,   K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K2D,   K2E,   KC_NO, K2A,      K49,   K4A,   K4B,      KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,      \
    K2B,   K14,   K1A,   K08,   K15,   K17,   K1C,   K18,   K0C,   K12,   K13,   K2F,   K30,          K32,      K4C,   K4D,   K4E,      KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO, KC_NO, \
    K39,   K04,   K16,   K07,   K09,   K0A,   K0B,   K0D,   K0E,   K0F,   K33,   K34,          K32,   K28,                              KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO, KC_NO,       \
    KE1,   K64,   K1D,   K1B,   K06,   K19,   K05,   K11,   K10,   K36,   K37,   K38,          KC_NO, KE5,             K52,             KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,         \
    KE0,   KE3,   KE2,   KC_NO, KC_NO,        K2C,          KC_NO, KC_NO, KC_NO, KE6,   KE7,   K65,   KE4,      K50,   K51,   K4F,      KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO               \
)


#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION
#define MANUFACTURER    mil
#define PRODUCT         milconv
#define DESCRIPTION     mils conv.. if found: miles@userbound.com

#define MIDI_ENABLE_STRICT 1
//#define MIDI_BASIC
#define MIDI_ADVANCED
#define MIDI_TONE_KEYCODE_OCTAVES 6


// Incompatible with LTO
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define LINK_TIME_OPTIMIZATION_ENABLE

