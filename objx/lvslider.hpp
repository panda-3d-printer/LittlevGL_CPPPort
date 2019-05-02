#ifndef LVSLIDER_H
#define LVSLIDER_H

#include <objx/lvbar.hpp>
#include <lvgl/lv_objx/lv_slider.h>

class LVSlider : public LVBar
{
    LV_OBJECT
public:

    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a slider objects
    * @param par pointer to an object, it will be the parent of the new slider
    * @param copy pointer to a slider object, if not NULL then the new object will be copied from it
    * @return pointer to the created slider
    */

    DEFINE_CONSTRUCTOR(LVSlider,lv_slider_create,LVBar)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a new value on the slider
    * @param slider pointer to a slider object
    * @param value new value
    */
    inline void setValue(int16_t value)
    {
        lv_slider_set_value(m_this, value);
    }

    /**
    * Set a new value with animation on a slider
    * @param slider pointer to a slider object
    * @param value new value
    * @param anim_time animation time in milliseconds
    */
    //inline void setValueAnim(int16_t value, uint16_t anim_time);

    /**
    * Set minimum and the maximum values of a bar
    * @param slider pointer to the slider object
    * @param min minimum value
    * @param max maximum value
    */
    //inline void setRange(int16_t min, int16_t max);

    /**
    * Set a function which will be called when a new value is set on the slider
    * @param slider pointer to slider object
    * @param action a callback function
    */
    void setAction(lv_action_t action)
    {
        lv_slider_set_action(m_this,action);
    }

    /**
    * Set the 'knob in' attribute of a slider
    * @param slider pointer to slider object
    * @param in true: the knob is drawn always in the slider;
    *           false: the knob can be out on the edges
    */
    void setKnobIn(bool in)
    {
        lv_slider_set_knob_in(m_this, in);
    }

    /**
    * Set a style of a slider
    * @param slider pointer to a slider object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_slider_style_t type, lv_style_t *style)
    {
        lv_slider_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the value of a slider
    * @param slider pointer to a slider object
    * @return the value of the slider
    */
    int16_t getValue()
    {
        return lv_slider_get_value(m_this);
    }

    /**
    * Get the minimum value of a slider
    * @param slider pointer to a slider object
    * @return the minimum value of the slider
    */
    //inline int16_t getMinValue();

    /**
    * Get the maximum value of a slider
    * @param slider pointer to a slider object
    * @return the maximum value of the slider
    */
    //inline int16_t getMaxValue();

    /**
    * Get the slider action function
    * @param slider pointer to slider object
    * @return the callback function
    */
    lv_action_t getAction()
    {
        return lv_slider_get_action(m_this);
    }

    /**
    * Give the slider is being dragged or not
    * @param slider pointer to a slider object
    * @return true: drag in progress false: not dragged
    */
    bool isDragged()
    {
        return lv_slider_is_dragged(m_this);
    }

    /**
    * Get the 'knob in' attribute of a slider
    * @param slider pointer to slider object
    * @return true: the knob is drawn always in the slider;
    *         false: the knob can be out on the edges
    */
    bool getKnobIn()
    {
        return lv_slider_get_knob_in(m_this);
    }


    /**
    * Get a style of a slider
    * @param slider pointer to a slider object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_slider_style_t type)
    {
        return lv_slider_get_style(m_this, type);
    }
};

#endif // LVSLIDER_H
