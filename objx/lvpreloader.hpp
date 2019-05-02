#ifndef LVPRELOADER_H
#define LVPRELOADER_H

#include <objx/lvarc.hpp>
#include <lvgl/lv_objx/lv_preload.h>

class LVPreloader: public LVArc
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a pre loader objects
    * @param par pointer to an object, it will be the parent of the new pre loader
    * @param copy pointer to a pre loader object, if not NULL then the new object will be copied from it
    * @return pointer to the created pre loader
    */
    DEFINE_CONSTRUCTOR(LVPreloader,lv_preload_create,LVArc)

    /*======================
    * Add/remove functions
    *=====================*/

    /**
    * Set the length of the spinning  arc in degrees
    * @param preload pointer to a preload object
    * @param deg length of the arc
    */
    void setArcLength(uint16_t deg)
    {
        lv_preload_set_arc_length(m_this,deg);
    }

    /**
    * Set the spin time of the arc
    * @param preload pointer to a preload object
    * @param time time of one round in milliseconds
    */
    void setSpinTime(uint16_t time)
    {
        lv_preload_set_spin_time(m_this, time);
    }

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a style of a pre loader.
    * @param preload pointer to pre loader object
    * @param type which style should be set
    * @param style pointer to a style
    *  */
    void setStyle(lv_preload_style_t type, lv_style_t *style)
    {
        lv_preload_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the arc length [degree] of the a pre loader
    * @param preload pointer to a pre loader object
    */
    uint16_t getArcLength()
    {
        return lv_preload_get_arc_length(m_this);
    }

    /**
    * Get the spin time of the arc
    * @param preload pointer to a pre loader object [milliseconds]
    */
    uint16_t getSpinTime()
    {
        return lv_preload_get_spin_time(m_this);
    }

    /**
    * Get style of a pre loader.
    * @param preload pointer to pre loader object
    * @param type which style should be get
    * @return style pointer to the style
    *  */
    lv_style_t * getStyle(lv_preload_style_t type)
    {
        return lv_preload_get_style(m_this, type);
    }

    /*=====================
    * Other functions
    *====================*/

    /**
     * Automatically in an animation to rotate the arc of spinner.
     * @param ptr pointer to preloader
     * @param val the current desired value [0..360]
     */
    void spinnerAnimation(int32_t val)
    {
        lv_preload_spinner_animation(m_this,val);
    }
};

#endif // LVPRELOADER_H
