#ifndef LVDROPDOWNLIST_H
#define LVDROPDOWNLIST_H

#include <objx/lvpage.hpp>
#include <lvgl/lv_objx/lv_ddlist.h>

class LVDropDownList : public LVPage
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/
    /**
    * Create a drop down list objects
    * @param par pointer to an object, it will be the parent of the new drop down list
    * @param copy pointer to a drop down list object, if not NULL then the new object will be copied from it
    * @return pointer to the created drop down list
    */
    DEFINE_CONSTRUCTOR(LVDropDownList,lv_ddlist_create,LVPage)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the options in a drop down list from a string
    * @param ddlist pointer to drop down list object
    * @param options a string with '\n' separated options. E.g. "One\nTwo\nThree"
    */
    void setOptions(const char * options)
    {
        lv_ddlist_set_options(m_this,options);
    }

    /**
    * Set the selected option
    * @param ddlist pointer to drop down list object
    * @param sel_opt id of the selected option (0 ... number of option - 1);
    */
    void setSelected(uint16_t sel_opt)
    {
        lv_ddlist_set_selected(m_this, sel_opt);
    }

    /**
    * Set a function to call when a new option is chosen
    * @param ddlist pointer to a drop down list
    * @param action pointer to a call back function
    */
    void setAction(lv_action_t action)
    {
        lv_ddlist_set_action(m_this, action);
    }

    /**
    * Set the fix height for the drop down list
    * If 0 then the opened ddlist will be auto. sized else the set height will be applied.
    * @param ddlist pointer to a drop down list
    * @param h the height when the list is opened (0: auto size)
    */
    void setFixHeight(lv_coord_t h)
    {
        lv_ddlist_set_fix_height(m_this, h);
    }

    /**
    * Enable or disable the horizontal fit to the content
    * @param ddlist pointer to a drop down list
    * @param fit en true: enable auto fit; false: disable auto fit
    */
    void setHorFit(bool fit_en)
    {
        lv_ddlist_set_hor_fit(m_this, fit_en);
    }

    /**
    * Set the scroll bar mode of a drop down list
    * @param ddlist pointer to a drop down list object
    * @param sb_mode the new mode from 'lv_page_sb_mode_t' enum
    */
    //inline void setScrollBarMode(lv_sb_mode_t mode);

    /**
    * Set the open/close animation time.
    * @param ddlist pointer to a drop down list
    * @param anim_time: open/close animation time [ms]
    */
    void setAnimTime(uint16_t anim_time)
    {
        lv_ddlist_set_anim_time(m_this,anim_time);
    }


    /**
    * Set a style of a drop down list
    * @param ddlist pointer to a drop down list object
    * @param type which style should be set
    * @param style pointer to a style
    *  */
    void setStyle(lv_ddlist_style_t type, lv_style_t *style)
    {
        lv_ddlist_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the options of a drop down list
    * @param ddlist pointer to drop down list object
    * @return the options separated by '\n'-s (E.g. "Option1\nOption2\nOption3")
    */
    const char * getOptions()
    {
        return lv_ddlist_get_options(m_this);
    }

    /**
    * Get the selected option
    * @param ddlist pointer to drop down list object
    * @return id of the selected option (0 ... number of option - 1);
    */
    uint16_t getSelected()
    {
        return lv_ddlist_get_selected(m_this);
    }

    /**
    * Get the current selected option as a string
    * @param ddlist pointer to ddlist object
    * @param buf pointer to an array to store the string
    */
    void getSelectedString(char * buf)
    {
        lv_ddlist_get_selected_str(m_this,buf);
    }

    /**
    * Get the "option selected" callback function
    * @param ddlist pointer to a drop down list
    * @return  pointer to the call back function
    */
    lv_action_t getAction()
    {
        return lv_ddlist_get_action(m_this);
    }

    /**
    * Get the fix height value.
    * @param ddlist pointer to a drop down list object
    * @return the height if the ddlist is opened (0: auto size)
    */
    lv_coord_t getFixHeight()
    {
        return lv_ddlist_get_fix_height(m_this);
    }

    /**
    * Get the scroll bar mode of a drop down list
    * @param ddlist pointer to a  drop down list object
    * @return scrollbar mode from 'lv_page_sb_mode_t' enum
    */
    //inline lv_sb_mode_t getScrollBarMode();

    /**
    * Get the open/close animation time.
    * @param ddlist pointer to a drop down list
    * @return open/close animation time [ms]
    */
    uint16_t getAnimTime()
    {
        return lv_ddlist_get_anim_time(m_this);
    }

    /**
    * Get a style of a drop down list
    * @param ddlist pointer to a drop down list object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_ddlist_style_t type)
    {
        return lv_ddlist_get_style(m_this,type);
    }

    /*=====================
    * Other functions
    *====================*/

    /**
    * Open the drop down list with or without animation
    * @param ddlist pointer to drop down list object
    * @param anim_en true: use animation; false: not use animations
    */
    void open(bool anim)
    {
        lv_ddlist_open(m_this, anim);
    }

    /**
    * Close (Collapse) the drop down list
    * @param ddlist pointer to drop down list object
    * @param anim true: use animation; false: not use animations
    */
    void close(bool anim)
    {
        lv_ddlist_close(m_this,anim);
    }
};

#endif // LVDROPDOWNLIST_H
