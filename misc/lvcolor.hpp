#ifndef LVCOLOR_H
#define LVCOLOR_H

#include <lvgl/lv_misc/lv_color.h>
#include <misc/lvmemory.hpp>

using LVColorHSV = lv_color_hsv_t;


/**
 * @brief LVGL 颜色类
 * 现在仅支持16位565颜色模式
 */
class LVColor
{
    LV_MEMAORY_FUNC

protected:
    lv_color_t m_this; //!< 类所装饰的数据类型
public:
    LVColor(uint16_t blue ,uint16_t green ,uint16_t red )
    {
        m_this.blue = blue;
        m_this.green = green;
        m_this.red = red;
    }

    LVColor(lv_color_t color)
    {
        m_this.full = color.full;
    }

    LVColor()
    {
        //默认白色
        m_this.full = 0XFFFF;
    }

    lv_color_t * operator->()
    {
        return &m_this;
    }

    operator lv_color_t()
    {
        return m_this;
    }

    /**
     * @brief 颜色中的蓝色分量
     * @return
     */
    uint16_t blue() { return m_this.blue; }

    /**
     * @brief 颜色中的绿色分量
     * @return
     */
    uint16_t green() { return m_this.green; }

    /**
     * @brief 颜色中的红色分量
     * @return
     */
    uint16_t red() { return m_this.red; }

    /**
     * @brief 颜色的全值
     * @return
     */
    uint16_t rgb(){ return m_this.full; }

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

    /*In color conversations:
     * - When converting to bigger color type the LSB weight of 1 LSB is calculated
     *   E.g. 16 bit Red has 5 bits
     *         8 bit Red has 2 bits
     *        ----------------------
     *        8 bit red LSB = (2^5 - 1) / (2^2 - 1) = 31 / 3 = 10
     *
     * - When calculating to smaller color type simply shift out the LSBs
     *   E.g.  8 bit Red has 2 bits
     *        16 bit Red has 5 bits
     *        ----------------------
     *         Shift right with 5 - 3 = 2
     */
    uint8_t toColor1()
    {
        return lv_color_to1(m_this);
    }

    uint8_t toColor8()
    {
        return lv_color_to8(m_this);
    }

    uint16_t toColor16()
    {
        return lv_color_to16(m_this);
    }

    uint32_t toColor32()
    {
        return lv_color_to32(m_this);
    }

    /**
     * @brief 颜色混合
     * @param color2 参与混合的颜色
     * @param mix 混合比例(第一种颜色占比)
     * @return
     */
    LVColor mixed(LVColor color2,uint8_t mix)
    {
        return  lv_color_mix(m_this,color2,mix);
    }

    LVColor & mix(LVColor color2,uint8_t mix)
    {
        m_this.full = lv_color_mix(m_this,color2,mix).full;
        return *this;
    }

    /**
     * Get the brightness of a color
     * @param color a color
     * @return the brightness [0..255]
     */
    uint8_t brightness()
    {
        return lv_color_brightness(m_this);
    }

    static LVColor fromHex(uint32_t c)
    {
        return lv_color_hex(c);
    }

    static LVColor fromhex3(uint32_t c)
    {
        return lv_color_hex3(c);
    }

    /**
     * Convert a HSV color to RGB
     * @param h hue [0..359]
     * @param s saturation [0..100]
     * @param v value [0..100]
     * @return the given RGB color in RGB (with LV_COLOR_DEPTH depth)
     */
    static LVColor fromHsv(uint16_t h, uint8_t s, uint8_t v)
    {
        return lv_color_hsv_to_rgb(h,s,v);
    }

    /**
     * Convert an RGB color to HSV
     * @param r red
     * @param g green
     * @param b blue
     * @return the given RGB color n HSV
     */
    LVColorHSV toHsv()
    {
        return lv_color_rgb_to_hsv(m_this.red,m_this.green,m_this.blue);
    }

    static LVColorHSV toHsv(uint8_t r, uint8_t g, uint8_t b)
    {
        return lv_color_rgb_to_hsv(r,g,b);
    }

};

#endif // LVCOLOR_H
