#ifndef LVSWITCH_H
#define LVSWITCH_H

#include <lvgl/lv_objx/lv_sw.h>
#include <objx/lvslider.hpp>

class LVSwitch : public LVSlider
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a switch objects
    * @param par pointer to an object, it will be the parent of the new switch
    * @param copy pointer to a switch object, if not NULL then the new object will be copied from it
    * @return pointer to the created switch
    */
    DEFINE_CONSTRUCTOR(LVSwitch,lv_sw_create,LVSlider)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Turn ON the switch
    * @param sw pointer to a switch object
    */
    void on()
    {
        lv_sw_on(m_this);
    }

    /**
    * Turn OFF the switch
    * @param sw pointer to a switch object
    */
    void off()
    {
        lv_sw_off(m_this);
    }

    /**
    * Set a function which will be called when the switch is toggled by the user
    * @param sw pointer to switch object
    * @param action a callback function
    */
    //void setAction(lv_action_t action)

    /**
    * Set a style of a switch
    * @param sw pointer to a switch object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_sw_style_t type, lv_style_t *style)
    {
        lv_sw_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the state of a switch
    * @param sw pointer to a switch object
    * @return false: OFF; true: ON
    */
    bool getState()
    {
        return lv_sw_get_state(m_this);
    }

    /**
    * Get the switch action function
    * @param slider pointer to a switch object
    * @return the callback function
    */
    lv_action_t getAction()
    {
        return lv_slider_get_action(m_this);
    }

    /**
    * Get a style of a switch
    * @param sw pointer to a  switch object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_sw_style_t type)
    {
        return lv_sw_get_style(m_this, type);
    }
};

#endif // LVSWITCH_H
