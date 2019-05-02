#ifndef LVTABVIEW_H
#define LVTABVIEW_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_tabview.h>

class LVTabView : public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/


    /**
    * Create a Tab view object
    * @param par pointer to an object, it will be the parent of the new tab
    * @param copy pointer to a tab object, if not NULL then the new object will be copied from it
    * @return pointer to the created tab
    */
    DEFINE_CONSTRUCTOR(LVTabView,lv_tabview_create,LVObject)

    /**
    * Delete all children of the scrl object, without deleting scrl child.
    * @param obj pointer to an object
    */
    void clean()
    {
        lv_tabview_clean(m_this);
    }

    /*======================
    * Add/remove functions
    *=====================*/

    /**
    * Add a new tab with the given name
    * @param tabview pointer to Tab view object where to ass the new tab
    * @param name the text on the tab button
    * @return pointer to the created page object (lv_page). You can create your content here
    */
    lv_obj_t * addTab(const char * name)
    {
        return lv_tabview_add_tab(m_this,name);
    }

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a new tab
    * @param tabview pointer to Tab view object
    * @param id index of a tab to load
    * @param anim_en true: set with sliding animation; false: set immediately
    */
    void setTabActive(uint16_t id, bool anim_en)
    {
        lv_tabview_set_tab_act(m_this, id, anim_en);
    }

    /**
    * Set an action to call when a tab is loaded (Good to create content only if required)
    * lv_tabview_get_act() still gives the current (old) tab (to remove content from here)
    * @param tabview pointer to a tabview object
    * @param action pointer to a function to call when a tab is loaded
    */
    void setTabLoadAction(lv_tabview_action_t action)
    {
        lv_tabview_set_tab_load_action(m_this, action);
    }

    /**
    * Enable horizontal sliding with touch pad
    * @param tabview pointer to Tab view object
    * @param en true: enable sliding; false: disable sliding
    */
    void setSliding(bool en)
    {
        lv_tabview_set_sliding(m_this, en);
    }

    /**
    * Set the animation time of tab view when a new tab is loaded
    * @param tabview pointer to Tab view object
    * @param anim_time time of animation in milliseconds
    */
    void setAnimationTime( uint16_t anim_time)
    {
        lv_tabview_set_anim_time(m_this, anim_time);
    }

    /**
    * Set the style of a tab view
    * @param tabview pointer to a tan view object
    * @param type which style should be set
    * @param style pointer to the new style
    */
    void setStyle(lv_tabview_style_t type, lv_style_t *style)
    {
        lv_tabview_set_style(m_this, type, style);
    }

    /**
    * Set the position of tab select buttons
    * @param tabview pointer to a tan view object
    * @param btns_pos which button position
    */
    void setButtonsPos(lv_tabview_btns_pos_t btns_pos)
    {
        lv_tabview_set_btns_pos(m_this, btns_pos);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the index of the currently active tab
    * @param tabview pointer to Tab view object
    * @return the active tab index
    */
    uint16_t getTabActive()
    {
        return lv_tabview_get_tab_act(m_this);
    }

    /**
    * Get the number of tabs
    * @param tabview pointer to Tab view object
    * @return tab count
    */
    uint16_t getTabCount()
    {
        return lv_tabview_get_tab_count(m_this);
    }
    /**
    * Get the page (content area) of a tab
    * @param tabview pointer to Tab view object
    * @param id index of the tab (>= 0)
    * @return pointer to page (lv_page) object
    */
    lv_obj_t * getTab( uint16_t id)
    {
        return lv_tabview_get_tab(m_this, id);
    }

    /**
    * Get the tab load action
    * @param tabview pointer to a tabview object
    * @param return the current tab load action
    */
    lv_tabview_action_t getTabLoadAction()
    {
        return lv_tabview_get_tab_load_action(m_this);
    }

    /**
    * Get horizontal sliding is enabled or not
    * @param tabview pointer to Tab view object
    * @return true: enable sliding; false: disable sliding
    */
    bool getSliding()
    {
        return lv_tabview_get_sliding(m_this);
    }

    /**
    * Get the animation time of tab view when a new tab is loaded
    * @param tabview pointer to Tab view object
    * @return time of animation in milliseconds
    */
    uint16_t getAnimationTime()
    {
        return lv_tabview_get_anim_time(m_this);
    }

    /**
    * Get a style of a tab view
    * @param tabview pointer to a ab view object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_tabview_style_t type)
    {
        return lv_tabview_get_style(m_this, type);
    }

    /**
    * Get position of tab select buttons
    * @param tabview pointer to a ab view object
    */
    lv_tabview_btns_pos_t getButtonsPos()
    {
        return lv_tabview_get_btns_pos(m_this);
    }
};

#endif // LVTABVIEW_H
