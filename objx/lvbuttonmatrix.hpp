#ifndef LVBUTTONMATRIX_H
#define LVBUTTONMATRIX_H

#include "core/lvobject.hpp"
#include "lvgl/lv_objx/lv_btnm.h"

class LVButtonMatrix : public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a button matrix objects
    * @param par pointer to an object, it will be the parent of the new button matrix
    * @param copy pointer to a button matrix object, if not NULL then the new object will be copied from it
    * @return pointer to the created button matrix
    */
    DEFINE_CONSTRUCTOR(LVButtonMatrix,lv_btnm_create,LVObject)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a new map. Buttons will be created/deleted according to the map.
    * @param btnm pointer to a button matrix object
    * @param map pointer a string array. The last string has to be: "".
    *            Use "\n" to begin a new line.
    *            The first byte can be a control data:
    *             - bit 7: always 1
    *             - bit 6: always 0
    *             - bit 5: inactive (disabled)
    *             - bit 4: no repeat (on long press)
    *             - bit 3: hidden
    *             - bit 2..0: button relative width
    *             Example (practically use octal numbers): "\224abc": "abc" text with 4 width and no long press
    */
    void setMap(const char ** map)
    {
        lv_btnm_set_map(m_this, map);
    }

    /**
    * Set a new callback function for the buttons (It will be called when a button is released)
    * @param btnm: pointer to button matrix object
    * @param action pointer to a callback function
    */
    void setAction(lv_btnm_action_t action)
    {
        lv_btnm_set_action(m_this, action);
    }

    /**
    * Enable or disable button toggling
    * @param btnm pointer to button matrix object
    * @param en true: enable toggling; false: disable toggling
    * @param id index of the currently toggled button (ignored if 'en' == false)
    */
    void setToggle(bool en, uint16_t id)
    {
        lv_btnm_set_toggle(m_this, en, id);
    }

    /**
    * Set a style of a button matrix
    * @param btnm pointer to a button matrix object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_btnm_style_t type, lv_style_t *style)
    {
        lv_btnm_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the current map of a button matrix
    * @param btnm pointer to a button matrix object
    * @return the current map
    */
    const char ** getMap()
    {
        return lv_btnm_get_map(m_this);
    }

    /**
    * Get a the callback function of the buttons on a button matrix
    * @param btnm: pointer to button matrix object
    * @return pointer to the callback function
    */
    lv_btnm_action_t getAction()
    {
        return lv_btnm_get_action(m_this);
    }


    /**
    * Get the toggled button
    * @param btnm pointer to button matrix object
    * @return  index of the currently toggled button (0: if unset)
    */
    uint16_t getToggled()
    {
        return lv_btnm_get_toggled(m_this);
    }

    /**
    * Get a style of a button matrix
    * @param btnm pointer to a button matrix object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_btnm_style_t type)
    {
        return lv_btnm_get_style(m_this, type);
    }
};

#endif // LVBUTTONMATRIX_H
