#ifndef LVLED_H
#define LVLED_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_led.h>

class LVLed :public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a led objects
    * @param par pointer to an object, it will be the parent of the new led
    * @param copy pointer to a led object, if not NULL then the new object will be copied from it
    * @return pointer to the created led
    */
    DEFINE_CONSTRUCTOR(LVLed,lv_led_create,LVObject)

    /**
    * Set the brightness of a LED object
    * @param led pointer to a LED object
    * @param bright 0 (max. dark) ... 255 (max. light)
    */
    void setBright(uint8_t bright)
    {
        lv_led_set_bright(m_this, bright);
    }

    /**
    * Light on a LED
    * @param led pointer to a LED object
    */
    void on()
    {
        lv_led_on(m_this);
    }

    /**
    * Light off a LED
    * @param led pointer to a LED object
    */
    void off()
    {
        lv_led_off(m_this);
    }

    /**
    * Toggle the state of a LED
    * @param led pointer to a LED object
    */
    void toggle()
    {
        lv_led_toggle(m_this);
    }

    /**
    * Set the style of a led
    * @param led pointer to a led object
    * @param style pointer to a style
    */
    //void setStyle(lv_style_t *style)

    /**
    * Get the brightness of a LEd object
    * @param led pointer to LED object
    * @return bright 0 (max. dark) ... 255 (max. light)
    */
    uint8_t getBright()
    {
        return lv_led_get_bright(m_this);
    }

    /**
    * Get the style of an led object
    * @param led pointer to an led object
    * @return pointer to the led's style
    */
    //lv_style_t* getStyle()
};

#endif // LVLED_H
