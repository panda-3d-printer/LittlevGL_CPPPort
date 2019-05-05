#ifndef LVMATH_H
#define LVMATH_H

#include <lv_misc/lv_math.h>

/**
 * Convert a number to string
 * @param num a number
 * @param buf pointer to a `char` buffer. The result will be stored here (max 10 elements)
 * @return same as `buf` (just for convenience)
 */
char * lvNumberToString(int32_t num, char * buf);

/**
 * Return with sinus of an angle
 * @param angle
 * @return sinus of 'angle'. sin(-90) = -32767, sin(90) = 32767
 */
int16_t lvTrigoSin(int16_t angle);

/**
 * Calculate a value of a Cubic Bezier function.
 * @param t time in range of [0..LV_BEZIER_VAL_MAX]
 * @param u0 start values in range of [0..LV_BEZIER_VAL_MAX]
 * @param u1 control value 1 values in range of [0..LV_BEZIER_VAL_MAX]
 * @param u2 control value 2 in range of [0..LV_BEZIER_VAL_MAX]
 * @param u3 end values in range of [0..LV_BEZIER_VAL_MAX]
 * @return the value calculated from the given parameters in range of [0..LV_BEZIER_VAL_MAX]
 */
int32_t lvBezier3(uint32_t t, int32_t u0, int32_t u1, int32_t u2, int32_t u3);

//////// 增强转换函数 //////////////////////////////////////

/**
 * @brief 整数转字符串
 * @param value
 * @return
 */
char * itos(int32_t value);

/**
 * @brief 浮点数转字符串
 * 智能转换浮点数到字符串,小数精度3位,无小数位时不显示小数部分
 * @param value
 * @return
 */
char * ftos(float value);

/**
 * @brief 字符串转整数
 * @param str
 * @return
 */
int32_t stoi(char * str);

/**
 * @brief 字符串转浮点数
 * @param str
 * @return
 */
float stof(char * str);

#endif // LVMATH_H
