#ifndef LVLINE_H
#define LVLINE_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_line.h>

class LVLine : public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/


    /**
    * Create a line objects
    * @param par pointer to an object, it will be the parent of the new line
    * @return pointer to the created line
    */
    DEFINE_CONSTRUCTOR(LVLine,lv_line_create,LVObject)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set an array of points. The line object will connect these points.
    * @param line pointer to a line object
    * @param point_a an array of points. Only the address is saved,
    * so the array can NOT be a local variable which will be destroyed
    * @param point_num number of points in 'point_a'
    */
    void setPoints(const lv_point_t * point_a, uint16_t point_num)
    {
        lv_line_set_points(m_this, point_a, point_num);
    }

    /**
    * Enable (or disable) the auto-size option. The size of the object will fit to its points.
    * (set width to x max and height to y max)
    * @param line pointer to a line object
    * @param autosize_en true: auto size is enabled, false: auto size is disabled
    */
    void setAutoSize(bool autosize_en)
    {
        lv_line_set_auto_size(m_this, autosize_en);
    }

    /**
    * Enable (or disable) the y coordinate inversion.
    * If enabled then y will be subtracted from the height of the object,
    * therefore the y=0 coordinate will be on the bottom.
    * @param line pointer to a line object
    * @param yinv_en true: enable the y inversion, false:disable the y inversion
    */
    void setYInvert(bool yinv_en)
    {
        lv_line_set_y_invert(m_this, yinv_en);
    }

    /**
    * Set the style of a line
    * @param line pointer to a line object
    * @param style pointer to a style
    */
    //void setStyle(lv_style_t *style)

    /**
    * Obsolete since v5.1. Just for compatibility with v5.0. Will be removed in v6.0
    * @param line -
    * @param upscale -
    */
    void setUpscale(bool upcale)
    {
        (void) upcale;
    }
    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the auto size attribute
    * @param line pointer to a line object
    * @return true: auto size is enabled, false: disabled
    */
    bool getAutoSize()
    {
        return lv_line_get_auto_size(m_this);
    }

    /**
    * Get the y inversion attribute
    * @param line pointer to a line object
    * @return true: y inversion is enabled, false: disabled
    */
    bool getYInvert()
    {
        //return lv_line_get_y_inv(m_this); //TODO: check
    }

    /**
    * Get the style of an line object
    * @param line pointer to an line object
    * @return pointer to the line's style
    */
    //lv_style_t* getStyle()

    /**
    * Obsolete since v5.1. Just for compatibility with v5.0. Will be removed in v6.0
    * @param line -
    * @return false
    */
    bool getUpscale()
    {
        return false;
    }
};

#endif // LVLINE_H
