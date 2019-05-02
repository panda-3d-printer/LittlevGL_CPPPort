#ifndef LVGROUP_H
#define LVGROUP_H

#include <lvgl/lv_core/lv_group.h>
#include <core/lvobject.hpp>

class LVGroup
{
    LV_MEMAORY_FUNC
private:
    lv_group_t * m_this = nullptr;
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a new object group
    * @return pointer to the new object group
    */
    LVGroup()
        :m_this(lv_group_create())
    {}

    /**
    * Delete a group object
    * @param group pointer to a group
    */
    ~ LVGroup()
    {
        lv_group_del(m_this);
    }

    lv_group_t * operator->()
    {
        return m_this;
    }

    //operator lv_group_t * ()
    //{
    //    return m_this;
    //}

    lv_group_t * raw()
    {
        return m_this;
    }

    lv_group_t * raw() const
    {
        return m_this;
    }

    /**
    * Add an object to a group
    * @param group pointer to a group
    * @param obj pointer to an object to add
    */
    void addObject(lv_obj_t * obj)
    {
        lv_group_add_obj(m_this,obj);
    }

    void addObject(LVObject * obj)
    {
        lv_group_add_obj(m_this,obj?(obj->raw()):nullptr);
    }

    /**
    * Remove an object from its group
    * @param obj pointer to an object to remove
    */
    static void removeObject(lv_obj_t * obj)
    {
        lv_group_remove_obj(obj);
    }

    static void removeObject(LVObject * obj)
    {
        lv_group_remove_obj(obj?(obj->raw()):nullptr);
    }

    /**
    * Focus on an object (defocus the current)
    * @param obj pointer to an object to focus on
    */
    void focusObject(lv_obj_t * obj)
    {
        lv_group_focus_obj(obj);
    }

    void focusObject(LVObject * obj)
    {
        lv_group_focus_obj(obj?(obj->raw()):nullptr);
    }

    /**
    * Focus the next object in a group (defocus the current)
    * @param group pointer to a group
    */
    void focusNext()
    {
        lv_group_focus_next(m_this);
    }

    /**
    * Focus the previous object in a group (defocus the current)
    * @param group pointer to a group
    */
    void focusPrev()
    {
        lv_group_focus_prev(m_this);
    }

    /**
    * Do not let to change the focus from the current object
    * @param group pointer to a group
    * @param en true: freeze, false: release freezing (normal mode)
    */
    void focusFreeze(bool en)
    {
        lv_group_focus_freeze(m_this , en);
    }

    /**
    * Send a control character to the focuses object of a group
    * @param group pointer to a group
    * @param c a character (use LV_GROUP_KEY_.. to navigate)
    */
    void sendData(uint32_t c)
    {
        lv_group_send_data(m_this, c);
    }

    /**
    * Set a function for a group which will modify the object's style if it is in focus
    * @param group pointer to a group
    * @param style_mod_func the style modifier function pointer
    */
    void setStyleModifyCallBack(lv_group_style_mod_func_t style_mod_func)
    {
        lv_group_set_style_mod_cb(m_this,style_mod_func);
    }

    /**
    * Set a function for a group which will modify the object's style if it is in focus in edit mode
    * @param group pointer to a group
    * @param style_mod_func the style modifier function pointer
    */
    void setStyleModifyEditCallBack(lv_group_style_mod_func_t style_mod_func)
    {
        lv_group_set_style_mod_edit_cb(m_this, style_mod_func);
    }

    /**
    * Set a function for a group which will be called when a new object is focused
    * @param group pointer to a group
    * @param focus_cb the call back function or NULL if unused
    */
    void setFocusCallBack(lv_group_focus_cb_t focus_cb)
    {
        lv_group_set_focus_cb(m_this,focus_cb);
    }

    /**
    * Manually set the current mode (edit or navigate).
    * @param group pointer to group
    * @param edit: true: edit mode; false: navigate mode
    */
    void setEditing(bool edit)
    {
        lv_group_set_editing(m_this,edit);
    }

    /**
    * Set the `click_focus` attribute. If enabled then the object will be focused then it is clicked.
    * @param group pointer to group
    * @param en: true: enable `click_focus`
    */
    void setClickFocus(bool en)
    {
        lv_group_set_click_focus(m_this, en);
    }

    /**
    * Modify a style with the set 'style_mod' function. The input style remains unchanged.
    * @param group pointer to group
    * @param style pointer to a style to modify
    * @return a copy of the input style but modified with the 'style_mod' function
    */
    lv_style_t * modifyStyle(const lv_style_t * style)
    {
        return lv_group_mod_style(m_this, style);
    }

    /**
    * Get the focused object or NULL if there isn't one
    * @param group pointer to a group
    * @return pointer to the focused object
    */
    lv_obj_t * getFocused()
    {
        return lv_group_get_focused(m_this);
    }

    /**
    * Get a the style modifier function of a group
    * @param group pointer to a group
    * @return pointer to the style modifier function
    */
    lv_group_style_mod_func_t getStyleModifyCallBack()
    {
        return lv_group_get_style_mod_cb(m_this);
    }

    /**
    * Get a the style modifier function of a group in edit mode
    * @param group pointer to a group
    * @return pointer to the style modifier function
    */
    lv_group_style_mod_func_t getStyleModifyEditCallBack()
    {
        return lv_group_get_style_mod_edit_cb(m_this);
    }

    /**
    * Get the focus callback function of a group
    * @param group pointer to a group
    * @return the call back function or NULL if not set
    */
    lv_group_focus_cb_t getFocusCallBack()
    {
        return lv_group_get_focus_cb(m_this);
    }

    /**
    * Get the current mode (edit or navigate).
    * @param group pointer to group
    * @return true: edit mode; false: navigate mode
    */
    bool getEditing()
    {
        return lv_group_get_editing(m_this);
    }

    /**
    * Get the `click_focus` attribute.
    * @param group pointer to group
    * @return true: `click_focus` is enabled; false: disabled
    */
    bool getClickFocus()
    {
        return lv_group_get_click_focus(m_this);
    }

};

#endif // LVGROUP_H
