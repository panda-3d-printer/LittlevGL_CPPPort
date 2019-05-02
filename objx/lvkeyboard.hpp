#ifndef LVKEYBOARD_H
#define LVKEYBOARD_H

#include <objx/lvbuttonmatrix.hpp>
#include <lvgl/lv_objx/lv_kb.h>

class LVkeyboard : public LVButtonMatrix
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a keyboard objects
    * @param par pointer to an object, it will be the parent of the new keyboard
    * @param copy pointer to a keyboard object, if not NULL then the new object will be copied from it
    * @return pointer to the created keyboard
    */
    DEFINE_CONSTRUCTOR(LVkeyboard,lv_kb_create,LVButtonMatrix)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Assign a Text Area to the Keyboard. The pressed characters will be put there.
    * @param kb pointer to a Keyboard object
    * @param ta pointer to a Text Area object to write there
    */
    void setTextArea(lv_obj_t * ta)
    {
        lv_kb_set_ta(m_this, ta);
    }

    /**
    * Set a new a mode (text or number map)
    * @param kb pointer to a Keyboard object
    * @param mode the mode from 'lv_kb_mode_t'
    */
    void setMode(lv_kb_mode_t mode)
    {
        lv_kb_set_mode(m_this, mode);
    }

    /**
    * Automatically hide or show the cursor of the current Text Area
    * @param kb pointer to a Keyboard object
    * @param en true: show cursor on the current text area, false: hide cursor
    */
    void setCursorManage(bool en)
    {
        lv_kb_set_cursor_manage(m_this,en);
    }

    /**
    * Set call back to call when the "Ok" button is pressed
    * @param kb pointer to Keyboard object
    * @param action a callback with 'lv_action_t' type
    */
    void setOkAction(lv_action_t action)
    {
        lv_kb_set_ok_action(m_this , action);
    }

    /**
    * Set call back to call when the "Hide" button is pressed
    * @param kb pointer to Keyboard object
    * @param action a callback with 'lv_action_t' type
    */
    void setHideAction(lv_action_t action)
    {
        lv_kb_set_hide_action(m_this, action);
    }

    /**
    * Set a new map for the keyboard
    * @param kb pointer to a Keyboard object
    * @param map pointer to a string array to describe the map.
    *            See 'lv_btnm_set_map()' for more info.
    */
    //void setMap( const char ** map)

    /**
    * Set a style of a keyboard
    * @param kb pointer to a keyboard object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_kb_style_t type, lv_style_t *style)
    {
        lv_kb_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Assign a Text Area to the Keyboard. The pressed characters will be put there.
    * @param kb pointer to a Keyboard object
    * @return pointer to the assigned Text Area object
    */
    lv_obj_t * getTextArea()
    {
        return lv_kb_get_ta(m_this);
    }

    /**
    * Set a new a mode (text or number map)
    * @param kb pointer to a Keyboard object
    * @return the current mode from 'lv_kb_mode_t'
    */
    lv_kb_mode_t getMode()
    {
        return lv_kb_get_mode(m_this);
    }

    /**
    * Get the current cursor manage mode.
    * @param kb pointer to a Keyboard object
    * @return true: show cursor on the current text area, false: hide cursor
    */
    bool getCursorManage()
    {
        return lv_kb_get_cursor_manage(m_this);
    }

    /**
    * Get the callback to call when the "Ok" button is pressed
    * @param kb pointer to Keyboard object
    * @return the ok callback
    */
    lv_action_t getOkAction()
    {
        return lv_kb_get_ok_action(m_this);
    }

    /**
    * Get the callback to call when the "Hide" button is pressed
    * @param kb pointer to Keyboard object
    * @return the close callback
    */
    lv_action_t getHideAction()
    {
        return lv_kb_get_hide_action(m_this);
    }

    /**
    * Get a style of a keyboard
    * @param kb pointer to a keyboard object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_kb_style_t type)
    {
        return lv_kb_get_style(m_this, type);
    }
};

#endif // LVKEYBOARD_H
