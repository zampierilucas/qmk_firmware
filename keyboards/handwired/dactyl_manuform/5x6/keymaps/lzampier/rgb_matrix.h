#ifdef RGB_MATRIX_ENABLE
// LED layout
// 00  01  02  03  04  05     37  36  35  34  33  32
// 06  07  08  09  10  11     43  42  41  40  39  38
// 12  13  14  15  16  17     49  48  47  46  45  44
// 18  19  20  21  22  23     55  54  53  52  51  50
//         24  25                            57  56
//             26  27            59  58
//                 28  29     61  60
//                 31  30     62  63
led_config_t g_led_config = { {
    {      0,      1,  2,  3,      4,      5 },
    {     11,     10,  9,  8,      7,      6 },
    {     12,     13, 14, 15,     16,     17 },
    {     23,     22, 21, 20,     19,     18 },
    { NO_LED, NO_LED, 24, 25,     26,     27 },
    { NO_LED, NO_LED, 30, 31,     28,     29 },
    {     37,     36, 35, 34,     33,     32 },
    {     43,     42, 41, 40,     39,     38 },
    {     49,     48, 47, 46,     45,     44 },
    {     55,     54, 53, 52,     51,     50 },
    {     59,     58, 57, 56, NO_LED, NO_LED},
    {     61,     60, 62, 63, NO_LED, NO_LED }

}, {
    {  0,  0 }, {  17,  0 }, {  34,  0 }, {  52,  0 }, {  69,  0 }, {  86,  0 }, {  86,  9 }, {  69,  9 },
    {  52,  9 }, {  34,   9 }, {  17,   9 }, {  0,  9 }, {  0,  18 }, {  17,  18 }, {  34,  18 }, {  52,  18 },
    {  60,  18 }, {  86,   18 }, {  86,   27 }, {  69,  27 }, {  52,  27 }, {  34,  27 }, {  17,  27 }, {  0,   27 },
    {  34,   37 }, {   52,  37 }, {   69,  45 }, { 86,  45 }, { 103,  55 }, { 103,  64 }, { 86,  55 }, { 86,  64 },


    { 224,  0 }, { 207,  0 }, { 190,  0 }, { 172,  0 }, { 155,   0 }, { 138,   0 }, { 224,  9 }, { 207,  9 },
    { 190,  9 }, { 172,  9 }, { 155,  9 }, { 138,  9 }, { 224,  18 }, { 207,  18 }, { 190,  18 },{ 172,  18 },
    { 155,  18 }, { 138,   18 }, { 224,  27 }, { 207,  27 }, { 190,  27}, { 172,  27 },{ 155,  27 }, { 138,  27 },
    { 190,  37 }, { 172,  37 }, { 155,  45}, { 138,  45 }, { 121,  55 }, { 121,  64 },  { 138,  64 }, { 138,  55 }
}, {
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2
} };
#endif
// void suspend_power_down_kb(void) {
//     rgblight_disable_noeeprom();
//     oled_off();
//     suspend_power_down_user();
// }
// void suspend_wakeup_init_kb(void) {
//     rgblight_enable_noeeprom();
//     oled_on();
//     suspend_wakeup_init_user();
// }

