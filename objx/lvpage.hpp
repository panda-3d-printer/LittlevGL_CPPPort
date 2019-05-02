#ifndef LVPAGE_H
#define LVPAGE_H

#include "../core/lvobject.hpp"
#include "lvgl/lv_objx/lv_page.h"

class LVPage : public LVObject
{
    LV_OBJECT
public:
    /**********************
     * GLOBAL PROTOTYPES
     **********************/
    /**
    * Create a page objects
    * @param par pointer to an object, it will be the parent of the new page
    * @param copy pointer to a page object, if not NULL then the new object will be copied from it
    * @return pointer to the created page
    */

    DEFINE_CONSTRUCTOR(LVPage,lv_page_create,LVObject)

    /**
    * Delete all children of the scrl object, without deleting scrl child.
    * @param obj pointer to an object
    */
    void clean()
    {
        lv_page_clean(m_this);
    }

    /**
    * Get the press action of the page
    * @param page pointer to a page object
    * @return a function to call when the page is pressed
    */
    lv_action_t getPressAction()
    {
        return lv_page_get_pr_action(m_this);
    }

    /**
    * Get the release action of the page
    * @param page pointer to a page object
    * @return a function to call when the page is released
    */
    lv_action_t getReleaseAction()
    {
        return lv_page_get_rel_action(m_this);
    }

    /**
    * Get the scrollable object of a page
    * @param page pointer to a page object
    * @return pointer to a container which is the scrollable part of the page
    */
    lv_obj_t * getScrollArea()
    {
        return lv_page_get_scrl(m_this);
    }

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a release action for the page
    * @param page pointer to a page object
    * @param rel_action a function to call when the page is released
    */
    void setReleaseAction(lv_action_t rel_action)
    {
        lv_page_set_rel_action(m_this,rel_action);
    }

    /**
    * Set a press action for the page
    * @param page pointer to a page object
    * @param pr_action a function to call when the page is pressed
    */
    void setPressAction(lv_action_t pr_action)
    {
        lv_page_set_pr_action(m_this, pr_action);
    }

    /**
    * Set the scroll bar mode on a page
    * @param page pointer to a page object
    * @param sb_mode the new mode from 'lv_page_sb.mode_t' enum
    */
    void setScrollBarMode(lv_sb_mode_t sb_mode)
    {
        lv_page_set_sb_mode(m_this, sb_mode);
    }

    /**
    * Enable/Disable scrolling with arrows if the page is in group (arrows: LV_GROUP_KEY_LEFT/RIGHT/UP/DOWN)
    * @param page pointer to a page object
    * @param en true: enable scrolling with arrows
    */
    void setArrowScroll(bool en)
    {
        lv_page_set_arrow_scroll(m_this,en);
    }

    /**
    * Set the fit attribute of the scrollable part of a page.
    * It means it can set its size automatically to involve all children.
    * (Can be set separately horizontally and vertically)
    * @param page pointer to a page object
    * @param hor_en true: enable horizontal fit
    * @param ver_en true: enable vertical fit
    */
    inline void setScrllAreaFit(bool hor_en, bool ver_en)
    {
        lv_page_set_scrl_fit(m_this,hor_en,ver_en);
    }

    /**
    * Set width of the scrollable part of a page
    * @param page pointer to a page object
    * @param w the new width of the scrollable (it ha no effect is horizontal fit is enabled)
    */
    inline void setScrllAreaWidth(lv_coord_t w)
    {
        lv_page_set_scrl_width(getScrollArea(), w);
    }

    /**
    * Set height of the scrollable part of a page
    * @param page pointer to a page object
    * @param h the new height of the scrollable (it ha no effect is vertical fit is enabled)
    */
    inline void setScrllAreaHeight(lv_coord_t h)
    {
        lv_page_set_scrl_height(getScrollArea(), h);
    }

    /**
    * Set the layout of the scrollable part of the page
    * @param page pointer to a page object
    * @param layout a layout from 'lv_cont_layout_t'
    */
    inline void setScrllAreaLayout(lv_layout_t layout)
    {
        lv_page_set_scrl_layout(getScrollArea(), layout);
    }

    /**
    * Set a style of a page
    * @param page pointer to a page object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_page_style_t type, lv_style_t *style)
    {
        lv_page_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Set the scroll bar mode on a page
    * @param page pointer to a page object
    * @return the mode from 'lv_page_sb.mode_t' enum
    */
    lv_sb_mode_t getScrollBarMode()
    {
        return  lv_page_get_sb_mode(m_this);
    }


    /**
    * Get the the scrolling with arrows (LV_GROUP_KEY_LEFT/RIGHT/UP/DOWN) is enabled or not
    * @param page pointer to a page object
    * @return true: scrolling with arrows is enabled
    */
    bool getArrowScroll()
    {
        return lv_page_get_arrow_scroll(m_this);
    }


    /**
    * Get that width which can be set to the children to still not cause overflow (show scrollbars)
    * @param page pointer to a page object
    * @return the width which still fits into the page
    */
    lv_coord_t getFitWidth()
    {
        return lv_page_get_fit_width(m_this);
    }

    /**
    * Get that height which can be set to the children to still not cause overflow (show scrollbars)
    * @param page pointer to a page object
    * @return the height which still fits into the page
    */
    lv_coord_t getFitHeight()
    {
        return lv_page_get_fit_height(m_this);
    }

    /**
    * Get width of the scrollable part of a page
    * @param page pointer to a page object
    * @return the width of the scrollable
    */
    inline lv_coord_t getScrollAreaWidth()
    {
        return lv_page_get_scrl_width(getScrollArea());
    }

    /**
    * Get height of the scrollable part of a page
    * @param page pointer to a page object
    * @return the height of the scrollable
    */
    inline lv_coord_t getScrollAreaHeight()
    {
        return lv_page_get_scrl_height(getScrollArea());
    }

    /**
    * Get the layout of the scrollable part of a page
    * @param page pointer to page object
    * @return the layout from 'lv_cont_layout_t'
    */
    inline lv_layout_t getScrollAreaLayout()
    {
        return lv_page_get_scrl_layout(getScrollArea());
    }

    /**
    * Get horizontal fit attribute of the scrollable part of a page
    * @param page pointer to a page object
    * @return true: horizontal fit is enabled; false: disabled
    */
    inline bool getScrollAreaHorizontalFit()
    {
        return lv_page_get_scrl_hor_fit(getScrollArea());
    }

    /**
    * Get vertical fit attribute of the scrollable part of a page
    * @param page pointer to a page object
    * @return true: vertical fit is enabled; false: disabled
    */
    inline bool getScrollAreaVerticalFit()
    {
        return lv_page_get_scrl_fit_ver(getScrollArea());
    }

    /**
    * Get a style of a page
    * @param page pointer to page object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_page_style_t type)
    {
        return lv_page_get_style(m_this,type);
    }

    /*=====================
    * Other functions
    *====================*/

    /**
    * Glue the object to the page. After it the page can be moved (dragged) with this object too.
    * @param obj pointer to an object on a page
    * @param glue true: enable glue, false: disable glue
    */
    void glueObject(lv_obj_t * obj, bool glue)
    {
        lv_page_glue_obj(obj,glue);
    }

    /**
    * Focus on an object. It ensures that the object will be visible on the page.
    * @param page pointer to a page object
    * @param obj pointer to an object to focus (must be on the page)
    * @param anim_time scroll animation time in milliseconds (0: no animation)
    */
    void focus(const lv_obj_t * obj, uint16_t anim_time)
    {
        lv_page_focus(m_this,obj,anim_time);
    }

    /**
    * Scroll the page horizontally
    * @param page pointer to a page object
    * @param dist the distance to scroll (< 0: scroll left; > 0 scroll right)
    */
    void ScrollHorizontally(lv_coord_t dist)
    {
        lv_page_scroll_hor(m_this, dist);
    }

    /**
    * Scroll the page vertically
    * @param page pointer to a page object
    * @param dist the distance to scroll (< 0: scroll down; > 0 scroll up)
    */
    void scrollVertically(lv_coord_t dist)
    {
        lv_page_scroll_ver(m_this, dist);
    }

};

#endif // LVPAGE_H
