#ifndef LVLINEMETER_H
#define LVLINEMETER_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_lmeter.h>

class LVLineMeter : public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a line meter objects
    * @param par pointer to an object, it will be the parent of the new line meter
    * @param copy pointer to a line meter object, if not NULL then the new object will be copied from it
    * @return pointer to the created line meter
    */
    DEFINE_CONSTRUCTOR(LVLineMeter,lv_lmeter_create,LVObject)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a new value on the line meter
    * @param lmeter pointer to a line meter object
    * @param value new value
    */
    void setValue(int16_t value)
    {
        lv_lmeter_set_value(m_this, value);
    }

    /**
    * Set minimum and the maximum values of a line meter
    * @param lmeter pointer to he line meter object
    * @param min minimum value
    * @param max maximum value
    */
    void setRange(int16_t min, int16_t max)
    {
        lv_lmeter_set_range(m_this, min, max);
    }

    /**
    * Set the scale settings of a line meter
    * @param lmeter pointer to a line meter object
    * @param angle angle of the scale (0..360)
    * @param line_cnt number of lines
    */
    void setScale(uint16_t angle, uint8_t line_cnt)
    {
        lv_lmeter_set_scale(m_this, angle, line_cnt);
    }

    /**
    * Set the styles of a line meter
    * @param lmeter pointer to a line meter object
    * @param bg set the style of the line meter
    */
    //void setStyle(lv_style_t *bg)

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the value of a line meter
    * @param lmeter pointer to a line meter object
    * @return the value of the line meter
    */
    int16_t getValue()
    {
        return lv_lmeter_get_value(m_this);
    }

    /**
    * Get the minimum value of a line meter
    * @param lmeter pointer to a line meter object
    * @return the minimum value of the line meter
    */
    int16_t getMinValue()
    {
        return lv_lmeter_get_min_value(m_this);
    }

    /**
    * Get the maximum value of a line meter
    * @param lmeter pointer to a line meter object
    * @return the maximum value of the line meter
    */
    int16_t getMaxValue()
    {
        return lv_lmeter_get_max_value(m_this);
    }

    /**
    * Get the scale number of a line meter
    * @param lmeter pointer to a line meter object
    * @return number of the scale units
    */
    uint8_t getLineCount()
    {
        return lv_lmeter_get_line_count(m_this);
    }

    /**
    * Get the scale angle of a line meter
    * @param lmeter pointer to a line meter object
    * @return angle of the scale
    */
    uint16_t getScaleAngle()
    {
        return lv_lmeter_get_scale_angle(m_this);
    }

    /**
    * Get the style of a line meter
    * @param lmeter pointer to a line meter object
    * @return pointer to the line meter's style
    */
    //lv_style_t * getStyle()
};

#endif // LVLINEMETER_H
