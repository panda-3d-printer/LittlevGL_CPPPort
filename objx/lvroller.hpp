#ifndef LVROLLER_H
#define LVROLLER_H

#include <objx/lvdropdownlist.hpp>
#include <lvgl/lv_objx/lv_roller.h>

class LVRoller : public LVDropDownList
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a roller object
    * @param par pointer to an object, it will be the parent of the new roller
    * @param copy pointer to a roller object, if not NULL then the new object will be copied from it
    * @return pointer to the created roller
    */
    DEFINE_CONSTRUCTOR(LVRoller,lv_roller_create,LVDropDownList)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the options on a roller
    * @param roller pointer to roller object
    * @param options a string with '\n' separated options. E.g. "One\nTwo\nThree"
    */
    //void setOptions(const char * options)

    /**
    * Set the selected option
    * @param roller pointer to a roller object
    * @param sel_opt id of the selected option (0 ... number of option - 1);
    * @param anim_en true: set with animation; false set immediately
    */
    void setSelected(uint16_t sel_opt, bool anim_en)
    {
        lv_roller_set_selected(m_this, sel_opt, anim_en);
    }


    /**
    * Set a function to call when a new option is chosen
    * @param roller pointer to a roller
    * @param action pointer to a callback function
    */
    //void setAction(lv_action_t action)

    /**
    * Set the height to show the given number of rows (options)
    * @param roller pointer to a roller object
    * @param row_cnt number of desired visible rows
    */
    void setVisibleRowCount(uint8_t row_cnt)
    {
        lv_roller_set_visible_row_count(m_this, row_cnt);
    }

    /**
    * Enable or disable the horizontal fit to the content
    * @param roller pointer to a roller
    * @param fit en true: enable auto fit; false: disable auto fit
    */
    //void setHorizontalFit(bool fit_en)

    /**
    * Set the open/close animation time.
    * @param roller pointer to a roller object
    * @param anim_time: open/close animation time [ms]
    */
    //void setAnimationTime(uint16_t anim_time)


    /**
    * Set a style of a roller
    * @param roller pointer to a roller object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_roller_style_t type, lv_style_t *style)
    {
        lv_roller_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the options of a roller
    * @param roller pointer to roller object
    * @return the options separated by '\n'-s (E.g. "Option1\nOption2\nOption3")
    */
    //const char * getOptions()

    /**
    * Get the id of the selected option
    * @param roller pointer to a roller object
    * @return id of the selected option (0 ... number of option - 1);
    */
    //uint16_t getSelected()

    /**
    * Get the current selected option as a string
    * @param roller pointer to roller object
    * @param buf pointer to an array to store the string
    */
    //void getSelectedStr(char * buf)

    /**
    * Get the "option selected" callback function
    * @param roller pointer to a roller
    * @return  pointer to the call back function
    */
    //lv_action_t getAction()

    /**
    * Get the open/close animation time.
    * @param roller pointer to a roller
    * @return open/close animation time [ms]
    */
    //uint16_t getAnimationTime()

    /**
    * Get the auto width set attribute
    * @param roller pointer to a roller object
    * @return true: auto size enabled; false: manual width settings enabled
    */
    bool getHorizontalFit()
    {
        return lv_roller_get_hor_fit(m_this);
    }

    /**
    * Get a style of a roller
    * @param roller pointer to a roller object
    * @param type which style should be get
    * @return style pointer to a style
    *  */
    lv_style_t * getStyle(lv_roller_style_t type)
    {
        return lv_roller_get_style(m_this, type);
    }
};

#endif // LVROLLER_H
