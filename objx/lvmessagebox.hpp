#ifndef LVMESSAGEBOX_H
#define LVMESSAGEBOX_H

#include <objx/lvcontainer.hpp>
#include <lvgl/lv_objx/lv_mbox.h>

class LVMessageBox : public LVContainer
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a message box objects
    * @param par pointer to an object, it will be the parent of the new message box
    * @param copy pointer to a message box object, if not NULL then the new object will be copied from it
    * @return pointer to the created message box
    */
    DEFINE_CONSTRUCTOR(LVMessageBox, lv_mbox_create,LVContainer)

    /*======================
    * Add/remove functions
    *=====================*/

    /**
    * Add button to the message box
    * @param mbox pointer to message box object
    * @param btn_map button descriptor (button matrix map).
    *                E.g.  a const char *txt[] = {"ok", "close", ""} (Can not be local variable)
    * @param action a function which will be called when a button is released
    */
    void addButton(const char **btn_map, lv_btnm_action_t action)
    {
        lv_mbox_add_btns(m_this,btn_map, action);
    }

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the text of the message box
    * @param mbox pointer to a message box
    * @param txt a '\0' terminated character string which will be the message box text
    */
    void setText( const char * txt)
    {
        lv_mbox_set_text(m_this, txt);
    }

    /**
    * Stop the action to call when button is released
    * @param mbox pointer to a message box object
    * @param pointer to an 'lv_btnm_action_t' action. In the action you need to use `lv_mbox_get_from_btn()` to get the `mbox`.
    */
    void setAction(lv_btnm_action_t action)
    {
        lv_mbox_set_action(m_this,action);
    }

    /**
    * Set animation duration
    * @param mbox pointer to a message box object
    * @param anim_time animation length in  milliseconds (0: no animation)
    */
    void setAnimationTime(uint16_t anim_time)
    {
        lv_mbox_set_anim_time(m_this, anim_time);
    }

    /**
    * Automatically delete the message box after a given time
    * @param mbox pointer to a message box object
    * @param delay a time (in milliseconds) to wait before delete the message box
    */
    void startAutoClose(uint16_t delay)
    {
        lv_mbox_start_auto_close(m_this, delay);
    }

    /**
    * Stop the auto. closing of message box
    * @param mbox pointer to a message box object
    */
    void stopAutoClose()
    {
        lv_mbox_stop_auto_close(m_this);
    }

    /**
    * Set a style of a message box
    * @param mbox pointer to a message box object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_mbox_style_t type, lv_style_t *style)
    {
        lv_mbox_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the text of the message box
    * @param mbox pointer to a message box object
    * @return pointer to the text of the message box
    */
    const char * getText()
    {
        return lv_mbox_get_text(m_this);
    }

    /**
    * Get the message box object from one of its button.
    * It is useful in the button release actions where only the button is known
    * @param btn pointer to a button of a message box
    * @return pointer to the button's message box
    */
    static lv_obj_t * getFromButton(const lv_obj_t * btn)
    {
        return lv_mbox_get_from_btn(btn);
    }

    static lv_obj_t * getFromButton(const LVObject * btn)
    {
        return lv_mbox_get_from_btn(btn?(btn->raw()):nullptr);
    }

    /**
    * Get the animation duration (close animation time)
    * @param mbox pointer to a message box object
    * @return animation length in  milliseconds (0: no animation)
    */
    uint16_t getAnimationTime()
    {
        return lv_mbox_get_anim_time(m_this);
    }


    /**
    * Get a style of a message box
    * @param mbox pointer to a message box object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_mbox_style_t type)
    {
        return lv_mbox_get_style(m_this, type);
    }
};

#endif // LVMESSAGEBOX_H
