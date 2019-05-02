#ifndef LVBUTTON_H
#define LVBUTTON_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_btn.h>
#include <functional>

class LVButton : public LVObject
{
    LV_OBJECT
public:
    /**
    * Create a button objects
    * @param par pointer to an object, it will be the parent of the new button
    * @param copy pointer to a button object, if not NULL then the new object will be copied from it
    * @return pointer to the created button
    */

    DEFINE_CONSTRUCTOR(LVButton,lv_btn_create,LVObject)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Enable the toggled states. On release the button will change from/to toggled state.
    * @param btn pointer to a button object
    * @param tgl true: enable toggled states, false: disable
    */
    void setToggle(bool tgl)
    {
        lv_btn_set_toggle(m_this,tgl);
    }

    /**
    * Set the state of the button
    * @param btn pointer to a button object
    * @param state the new state of the button (from lv_btn_state_t enum)
    */
    void setState(lv_btn_state_t state)
    {
        lv_btn_set_state(m_this, state);
    }

    /**
    * Toggle the state of the button (ON->OFF, OFF->ON)
    * @param btn pointer to a button object
    */
    void Toggle()
    {
        lv_btn_toggle(m_this);
    }

    /**
    * Set a function to call when a button event happens
    * @param btn pointer to a button object
    * @param action type of event form 'lv_action_t' (press, release, long press, long press repeat)
    */
    void setAction(lv_btn_action_t type, lv_action_t action)
    {
        lv_btn_set_action(m_this, type, action);
    }

    /**
    * Set the layout on a button
    * @param btn pointer to a button object
    * @param layout a layout from 'lv_cont_layout_t'
    */
    inline void setLayout(lv_layout_t layout)
    {
        lv_btn_set_layout(m_this, layout);
    }

    /**
    * Enable the horizontal or vertical fit.
    * The button size will be set to involve the children horizontally or vertically.
    * @param btn pointer to a button object
    * @param hor_en true: enable the horizontal fit
    * @param ver_en true: enable the vertical fit
    */
    inline void setFit(bool hor_en, bool ver_en)
    {
        lv_btn_set_fit(m_this, hor_en, ver_en);
    }

    /**
    * Set time of the ink effect (draw a circle on click to animate in the new state)
    * @param btn pointer to a button object
    * @param time the time of the ink animation
    */
    void setInkInTime(uint16_t time)
    {
        lv_btn_set_ink_in_time(m_this, time);
    }

    /**
    * Set the wait time before the ink disappears
    * @param btn pointer to a button object
    * @param time the time of the ink animation
    */
    void setInkWaitTime( uint16_t time)
    {
        lv_btn_set_ink_wait_time(m_this, time);
    }

    /**
    * Set time of the ink out effect (animate to the released state)
    * @param btn pointer to a button object
    * @param time the time of the ink animation
    */
    void setInkOutTime(uint16_t time)
    {
        lv_btn_set_ink_out_time(m_this, time);
    }

    /**
    * Set a style of a button.
    * @param btn pointer to button object
    * @param type which style should be set
    * @param style pointer to a style
    *  */
    void setStyle(lv_btn_style_t type, lv_style_t *style)
    {
        lv_btn_set_style(m_this,type,style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the current state of the button
    * @param btn pointer to a button object
    * @return the state of the button (from lv_btn_state_t enum)
    */
    lv_btn_state_t getState()
    {
        return lv_btn_get_state(m_this);
    }

    /**
    * Get the toggle enable attribute of the button
    * @param btn pointer to a button object
    * @return ture: toggle enabled, false: disabled
    */
    bool getToggle()
    {
        return lv_btn_get_toggle(m_this);
    }

    /**
    * Get the release action of a button
    * @param btn pointer to a button object
    * @return pointer to the release action function
    */
    lv_action_t getAction(lv_btn_action_t type)
    {
        return lv_btn_get_action(m_this, type);
    }

    /**
    * Get the layout of a button
    * @param btn pointer to button object
    * @return the layout from 'lv_cont_layout_t'
    */
    inline lv_layout_t getLayout()
    {
        return lv_btn_get_layout(m_this);
    }

    /**
    * Get horizontal fit enable attribute of a button
    * @param btn pointer to a button object
    * @return true: horizontal fit is enabled; false: disabled
    */
    inline bool getHorizontalFit()
    {
        return lv_cont_get_hor_fit(m_this);
    }

    /**
    * Get vertical fit enable attribute of a container
    * @param btn pointer to a button object
    * @return true: vertical fit is enabled; false: disabled
    */
    inline bool getVerticalFit()
    {
        return lv_cont_get_ver_fit(m_this);
    }

    /**
    * Get time of the ink in effect (draw a circle on click to animate in the new state)
    * @param btn pointer to a button object
    * @return the time of the ink animation
    */
    uint16_t getInkInTime()
    {
        return lv_btn_get_ink_in_time(m_this);
    }

    /**
    * Get the wait time before the ink disappears
    * @param btn pointer to a button object
    * @return the time of the ink animation
    */
    uint16_t getInkWaitTime()
    {
        return lv_btn_get_ink_wait_time(m_this);
    }

    /**
    * Get time of the ink out effect (animate to the releases state)
    * @param btn pointer to a button object
    * @return the time of the ink animation
    */
    uint16_t getInkOutTime()
    {
        return lv_btn_get_ink_out_time(m_this);
    }

    /**
    * Get style of a button.
    * @param btn pointer to button object
    * @param type which style should be get
    * @return style pointer to the style
    *  */
    lv_style_t * getStyle( lv_btn_style_t type)
    {
        return lv_btn_get_style(m_this,type);
    }
};

#endif // LVBUTTON_H
