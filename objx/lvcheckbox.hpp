#ifndef LVCHECKBOX_H
#define LVCHECKBOX_H

#include <objx/lvbutton.hpp>
#include <lvgl/lv_objx/lv_cb.h>

class LVCheckBox : public LVButton
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a check box objects
    * @param par pointer to an object, it will be the parent of the new check box
    * @param copy pointer to a check box object, if not NULL then the new object will be copied from it
    * @return pointer to the created check box
    */
    DEFINE_CONSTRUCTOR(LVCheckBox,lv_cb_create,LVButton)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the text of a check box
    * @param cb pointer to a check box
    * @param txt the text of the check box
    */
    void setText(const char * txt)
    {
        lv_cb_set_text(m_this,txt);
    }

    /**
    * Set the state of the check box
    * @param cb pointer to a check box object
    * @param checked true: make the check box checked; false: make it unchecked
    */
    void setChecked(bool checked)
    {
        setState(checked ? LV_BTN_STATE_TGL_REL : LV_BTN_STATE_REL);
    }

    /**
    * Make the check box inactive (disabled)
    * @param cb pointer to a check box object
    */
    void set_inactive()
    {
        setState(LV_BTN_STATE_INA);
    }

    /**
    * Set a function to call when the check box is clicked
    * @param cb pointer to a check box object
    */
    void setAction(lv_action_t action)
    {
        LVButton::setAction(LV_BTN_ACTION_CLICK, action);
    }


    /**
    * Set a style of a check box
    * @param cb pointer to check box object
    * @param type which style should be set
    * @param style pointer to a style
    *  */
    void setStyle(lv_cb_style_t type, lv_style_t *style)
    {
        lv_cb_set_style(m_this,type,style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the text of a check box
    * @param cb pointer to check box object
    * @return pointer to the text of the check box
    */
    const char * getText()
    {
        return lv_cb_get_text(m_this);
    }

    /**
    * Get the current state of the check box
    * @param cb pointer to a check box object
    * @return true: checked; false: not checked
    */
    bool isChecked()
    {
        return getState() == LV_BTN_STATE_REL ? false : true;
    }

    /**
    * Get the action of a check box
    * @param cb pointer to a button object
    * @return pointer to the action function
    */
    lv_action_t getAction()
    {
        return LVButton::getAction(LV_BTN_ACTION_CLICK);
    }


    /**
    * Get a style of a button
    * @param cb pointer to check box object
    * @param type which style should be get
    * @return style pointer to the style
    *  */
    lv_style_t * getStyle(lv_cb_style_t type)
    {
        return lv_cb_get_style(m_this,type);
    }
};

#endif // LVCHECKBOX_H
