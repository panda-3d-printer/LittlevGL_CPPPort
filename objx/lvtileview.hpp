#ifndef LVTILEVIEW_H
#define LVTILEVIEW_H

#include <objx/lvpage.hpp>
#include <lvgl/lv_objx/lv_tileview.h>

class LVTileView : public LVPage
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a tileview objects
    * @param par pointer to an object, it will be the parent of the new tileview
    * @param copy pointer to a tileview object, if not NULL then the new object will be copied from it
    * @return pointer to the created tileview
    */
    DEFINE_CONSTRUCTOR(LVTileView,lv_tileview_create,LVPage)

    /*======================
    * Add/remove functions
    *=====================*/

    /**
    * Register an object on the tileview. The register object will able to slide the tileview
    * @param element pointer to an object
    */
    static void addElement(lv_obj_t * element)
    {
        lv_tileview_add_element(element);
    }

    /*=====================
    * Setter functions
    *====================*/


    /**
    * Set the valid position's indices. The scrolling will be possible only to these positions.
    * @param tileview pointer to a Tileview object
    * @param valid_pos array width the indices. E.g. `lv_point_t p[] = {{0,0}, {1,0}, {1,1}, {LV_COORD_MIN, LV_COORD_MIN}};`
    * Must be closed with `{LV_COORD_MIN, LV_COORD_MIN}`. Only the pointer is saved so can't be a local variable.
    */
    void setValidPositions(const lv_point_t * valid_pos)
    {
        lv_tileview_set_valid_positions(m_this, valid_pos);
    }

    /**
    * Set the tile to be shown
    * @param tileview pointer to a tileview object
    * @param x column id (0, 1, 2...)
    * @param y line id (0, 1, 2...)
    * @param anim_en true: move with animation
    */
    void setTileActive(lv_coord_t x, lv_coord_t y, bool anim_en)
    {
        lv_tileview_set_tile_act(m_this, x, y, anim_en);
    }

    /**
    * Enable the edge flash effect. (Show an arc when the an edge is reached)
    * @param tileview pointer to a Tileview
    * @param en true or false to enable/disable end flash
    */
    void setEdgeFlash(bool en)
    {
        lv_tileview_set_edge_flash(m_this, en);
    }

    /**
    * Set a style of a tileview.
    * @param tileview pointer to tileview object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_tileview_style_t type, lv_style_t *style)
    {
        lv_tileview_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the scroll propagation property
    * @param tileview pointer to a Tileview
    * @return true or false
    */
    bool getEdgeFlash()
    {
        return lv_tileview_get_edge_flash(m_this);
    }

    /**
    * Get style of a tileview.
    * @param tileview pointer to tileview object
    * @param type which style should be get
    * @return style pointer to the style
    */
    lv_style_t * getStyle(lv_tileview_style_t type)
    {
        return lv_tileview_get_style(m_this , type);
    }
};

#endif // LVTILEVIEW_H
