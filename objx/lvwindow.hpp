#ifndef LVWINDOW_H
#define LVWINDOW_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_win.h>

class LVWindow : public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a window objects
    * @param par pointer to an object, it will be the parent of the new window
    * @param copy pointer to a window object, if not NULL then the new object will be copied from it
    * @return pointer to the created window
    */
    DEFINE_CONSTRUCTOR(LVWindow,lv_win_create,LVObject)

    /**
    * Delete all children of the scrl object, without deleting scrl child.
    * @param obj pointer to an object
    */
    void clean()
    {
        lv_win_clean(m_this);
    }

    /*======================
    * Add/remove functions
    *=====================*/

    /**
    * Add control button to the header of the window
    * @param win pointer to a window object
    * @param img_src an image source ('lv_img_t' variable, path to file or a symbol)
    * @param rel_action a function pointer to call when the button is released
    * @return pointer to the created button object
    */
    lv_obj_t * addButton(const void * img_src, lv_action_t rel_action)
    {
        return lv_win_add_btn(m_this, img_src, rel_action);
    }

    /*=====================
    * Setter functions
    *====================*/

    /**
    * A release action which can be assigned to a window control button to close it
    * @param btn pointer to the released button
    * @return always LV_ACTION_RES_INV because the button is deleted with the window
    */
    lv_res_t closeAction()
    {
        return lv_win_close_action(m_this);
    }

    /**
    * Set the title of a window
    * @param win pointer to a window object
    * @param title string of the new title
    */
    void setTitle(const char * title)
    {
        lv_win_set_title(m_this,title);
    }

    /**
    * Set the control button size of a window
    * @param win pointer to a window object
    * @return control button size
    */
    void setButtonSize(lv_coord_t size)
    {
        lv_win_set_btn_size(m_this, size);
    }

    /**
    * Set the layout of the window
    * @param win pointer to a window object
    * @param layout the layout from 'lv_layout_t'
    */
    void setLayout(lv_layout_t layout)
    {
        lv_win_set_layout(m_this, layout);
    }

    /**
    * Set the scroll bar mode of a window
    * @param win pointer to a window object
    * @param sb_mode the new scroll bar mode from  'lv_sb_mode_t'
    */
    void setScrollBarMode(lv_sb_mode_t sb_mode)
    {
        lv_win_set_sb_mode(m_this, sb_mode);
    }

    /**
    * Set a style of a window
    * @param win pointer to a window object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_win_style_t type, lv_style_t *style)
    {
        lv_win_set_style(m_this, type, style);
    }


    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the title of a window
    * @param win pointer to a window object
    * @return title string of the window
    */
    const char * getTitle()
    {
        return lv_win_get_title(m_this);
    }

    /**
    * Get the content holder object of window (`lv_page`) to allow additional customization
    * @param win pointer to a window object
    * @return the Page object where the window's content is
    */
    lv_obj_t * getContent()
    {
        return lv_win_get_content(m_this);
    }

    /**
    * Get the control button size of a window
    * @param win pointer to a window object
    * @return control button size
    */
    lv_coord_t getButtonSize()
    {
        return lv_win_get_btn_size(m_this);
    }

    /**
    * Get the pointer of a widow from one of  its control button.
    * It is useful in the action of the control buttons where only button is known.
    * @param ctrl_btn pointer to a control button of a window
    * @return pointer to the window of 'ctrl_btn'
    */
    lv_obj_t * getFromButton(const lv_obj_t * ctrl_btn)
    {
        return lv_win_get_from_btn(ctrl_btn);
    }

    /**
    * Get the layout of a window
    * @param win pointer to a window object
    * @return the layout of the window (from 'lv_layout_t')
    */
    lv_layout_t getLayout()
    {
        return lv_win_get_layout(m_this);
    }

    /**
    * Get the scroll bar mode of a window
    * @param win pointer to a window object
    * @return the scroll bar mode of the window (from 'lv_sb_mode_t')
    */
    lv_sb_mode_t getScrollBarMode()
    {
        return lv_win_get_sb_mode(m_this);
    }

    /**
    * Get width of the content area (page scrollable) of the window
    * @param win pointer to a window object
    * @return the width of the content area
    */
    lv_coord_t getWidth()
    {
        return lv_win_get_width(m_this);
    }

    /**
    * Get a style of a window
    * @param win pointer to a button object
    * @param type which style window be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle( lv_win_style_t type)
    {
        return lv_win_get_style(m_this, type);
    }

    /*=====================
    * Other functions
    *====================*/

    /**
    * Focus on an object. It ensures that the object will be visible in the window.
    * @param win pointer to a window object
    * @param obj pointer to an object to focus (must be in the window)
    * @param anim_time scroll animation time in milliseconds (0: no animation)
    */
    void focus(lv_obj_t * obj, uint16_t anim_time)
    {
        lv_win_focus(m_this,obj,anim_time);
    }

    /**
    * Scroll the window horizontally
    * @param win pointer to a window object
    * @param dist the distance to scroll (< 0: scroll right; > 0 scroll left)
    */
    void scrollHor(lv_coord_t dist)
    {
        lv_win_scroll_hor(m_this, dist);
    }
    /**
    * Scroll the window vertically
    * @param win pointer to a window object
    * @param dist the distance to scroll (< 0: scroll down; > 0 scroll up)
    */
    void scrollVer(lv_coord_t dist)
    {
        lv_win_scroll_ver(m_this, dist);
    }
};

#endif // LVWINDOW_H
