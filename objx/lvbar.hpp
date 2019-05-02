#ifndef LVBAR_H
#define LVBAR_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_bar.h>

class LVBar : public LVObject
{
    LV_OBJECT
public:

    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a bar objects
    * @param par pointer to an object, it will be the parent of the new bar
    * @param copy pointer to a bar object, if not NULL then the new object will be copied from it
    * @return pointer to the created bar
    */
    DEFINE_CONSTRUCTOR(LVBar,lv_bar_create,LVObject)


    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a new value on the bar
    * @param bar pointer to a bar object
    * @param value new value
    */
    void setValue(int16_t value)
    {
        lv_bar_set_value(m_this,value);
    }

    /**
    * Set a new value with animation on the bar
    * @param bar pointer to a bar object
    * @param value new value
    * @param anim_time animation time in milliseconds
    */
    void setValueAnim(int16_t value, uint16_t anim_time)
    {
        lv_bar_set_value_anim(m_this, value, anim_time);
    }


    /**
    * Set minimum and the maximum values of a bar
    * @param bar pointer to the bar object
    * @param min minimum value
    * @param max maximum value
    */
    void setRange(int16_t min, int16_t max)
    {
        lv_bar_set_range(m_this, min, max);
    }

    /**
    * Set a style of a bar
    * @param bar pointer to a bar object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_bar_style_t type, lv_style_t *style)
    {
        lv_bar_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the value of a bar
    * @param bar pointer to a bar object
    * @return the value of the bar
    */
    int16_t getValue()
    {
        return lv_bar_get_value(m_this);
    }

    /**
    * Get the minimum value of a bar
    * @param bar pointer to a bar object
    * @return the minimum value of the bar
    */
    int16_t getMinValue()
    {
        return lv_bar_get_min_value(m_this);
    }

    /**
    * Get the maximum value of a bar
    * @param bar pointer to a bar object
    * @return the maximum value of the bar
    */
    int16_t getMaxValue()
    {
        return lv_bar_get_max_value(m_this);
    }


    /**
    * Get a style of a bar
    * @param bar pointer to a bar object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_bar_style_t type)
    {
        return lv_bar_get_style(m_this,type);
    }

};

#endif // LVBAR_H
