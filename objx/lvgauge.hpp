#ifndef LVGAUGE_H
#define LVGAUGE_H

#include <objx/lvlinemeter.hpp>
#include <lvgl/lv_objx/lv_gauge.h>

class LVGauge : public LVLineMeter
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a gauge objects
    * @param par pointer to an object, it will be the parent of the new gauge
    * @param copy pointer to a gauge object, if not NULL then the new object will be copied from it
    * @return pointer to the created gauge
    */
    DEFINE_CONSTRUCTOR(LVGauge,lv_gauge_create,LVLineMeter)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the number of needles
    * @param gauge pointer to gauge object
    * @param needle_cnt new count of needles
    * @param colors an array of colors for needles (with 'num' elements)
    */
    void setNeedleCount(uint8_t needle_cnt, const lv_color_t * colors)
    {
        lv_gauge_set_needle_count(m_this, needle_cnt, colors);
    }

    /**
    * Set the value of a needle
    * @param gauge pointer to a gauge
    * @param needle_id the id of the needle
    * @param value the new value
    */
    void setValue(uint8_t needle_id, int16_t value)
    {
        lv_gauge_set_value(m_this, needle_id, value);
    }

    /**
    * Set minimum and the maximum values of a gauge
    * @param gauge pointer to he gauge object
    * @param min minimum value
    * @param max maximum value
    */
    //void setRange(int16_t min, int16_t max)

    /**
    * Set a critical value on the scale. After this value 'line.color' scale lines will be drawn
    * @param gauge pointer to a gauge object
    * @param value the critical value
    */
    void setCriticalValue(int16_t value)
    {
        lv_lmeter_set_value(m_this, value);
    }

    /**
    * Set the scale settings of a gauge
    * @param gauge pointer to a gauge object
    * @param angle angle of the scale (0..360)
    * @param line_cnt count of scale lines.
    * The get a given "subdivision" lines between label, `line_cnt` = (sub_div + 1) * (label_cnt - 1) + 1
    * @param label_cnt count of scale labels.
    */
    void setScale(uint16_t angle, uint8_t line_cnt, uint8_t label_cnt)
    {
        lv_gauge_set_scale(m_this, angle, line_cnt, label_cnt);
    }

    /**
    * Set the styles of a gauge
    * @param gauge pointer to a gauge object
    * @param bg set the style of the gauge
    *  */
    //void setStyle(lv_style_t *bg)

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the value of a needle
    * @param gauge pointer to gauge object
    * @param needle the id of the needle
    * @return the value of the needle [min,max]
    */
    int16_t getValue( uint8_t needle)
    {
        return lv_gauge_get_value(m_this, needle);
    }

    /**
    * Get the count of needles on a gauge
    * @param gauge pointer to gauge
    * @return count of needles
    */
    uint8_t getNeedleCount()
    {
        return lv_gauge_get_needle_count(m_this);
    }

    /**
    * Get the minimum value of a gauge
    * @param gauge pointer to a gauge object
    * @return the minimum value of the gauge
    */
    //int16_t getMinValue()

    /**
    * Get the maximum value of a gauge
    * @param gauge pointer to a gauge object
    * @return the maximum value of the gauge
    */
    //int16_t getMaxValue()

    /**
    * Get a critical value on the scale.
    * @param gauge pointer to a gauge object
    * @return the critical value
    */
    int16_t getCriticalValue()
    {
        return lv_lmeter_get_value(m_this);
    }

    /**
    * Set the number of labels (and the thicker lines too)
    * @param gauge pointer to a gauge object
    * @return count of labels
    */
    uint8_t getLabelCount()
    {
        return lv_gauge_get_label_count(m_this);
    }

    /**
    * Get the scale number of a gauge
    * @param gauge pointer to a gauge object
    * @return number of the scale units
    */
    //uint8_t getLineCount()

    /**
    * Get the scale angle of a gauge
    * @param gauge pointer to a gauge object
    * @return angle of the scale
    */
    //uint16_t getScaleAngle()

    /**
    * Get the style of a gauge
    * @param gauge pointer to a gauge object
    * @return pointer to the gauge's style
    */
    //lv_style_t * getStyle()
};

#endif // LVGAUGE_H
