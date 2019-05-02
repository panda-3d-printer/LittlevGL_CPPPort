#ifndef LVARC_H
#define LVARC_H

#include <core/lvobject.hpp>
#include "lvgl/lv_objx/lv_arc.h"

class LVArc : public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a arc objects
    * @param par pointer to an object, it will be the parent of the new arc
    * @param copy pointer to a arc object, if not NULL then the new object will be copied from it
    * @return pointer to the created arc
    */
    DEFINE_CONSTRUCTOR(LVArc,lv_arc_create,LVObject)

    /*======================
    * Add/remove functions
    *=====================*/


    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the start and end angles of an arc. 0 deg: bottom, 90 deg: right etc.
    * @param arc pointer to an arc object
    * @param start the start angle [0..360]
    * @param end the end angle [0..360]
    */
    void setAngles(uint16_t start, uint16_t end)
    {
        lv_arc_set_angles(m_this, start, end);
    }

    /**
    * Set a style of a arc.
    * @param arc pointer to arc object
    * @param type which style should be set
    * @param style pointer to a style
    *  */
    void setStyle(lv_arc_style_t type, lv_style_t *style)
    {
        lv_arc_set_style( m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the start angles of an arc.
    * @param arc pointer to an arc object
    * @return the start angle [0..360]
    */
    uint16_t getAngleStart()
    {
        return lv_arc_get_angle_start(m_this);
    }

    /**
    * Get the end angles of an arc.
    * @param arc pointer to an arc object
    * @return the end angle [0..360]
    */
    uint16_t getAngleEnd()
    {
        return lv_arc_get_angle_end(m_this);
    }

    /**
    * Get style of a arc.
    * @param arc pointer to arc object
    * @param type which style should be get
    * @return style pointer to the style
    *  */
    lv_style_t * getStyle(lv_arc_style_t type)
    {
        return lv_arc_get_style(m_this,type);
    }
};

#endif // LVARC_H
