#ifndef LVCONTAINER_H
#define LVCONTAINER_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_cont.h>

class LVContainer : public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a container objects
    * @param par pointer to an object, it will be the parent of the new container
    * @param copy pointer to a container object, if not NULL then the new object will be copied from it
    * @return pointer to the created container
    */
    DEFINE_CONSTRUCTOR(LVContainer,lv_cont_create,LVObject)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a layout on a container
    * @param cont pointer to a container object
    * @param layout a layout from 'lv_cont_layout_t'
    */
    void setLayout(lv_layout_t layout)
    {
        lv_cont_set_layout(m_this,layout);
    }


    /**
    * Enable the horizontal or vertical fit.
    * The container size will be set to involve the children horizontally or vertically.
    * @param cont pointer to a container object
    * @param hor_en true: enable the horizontal fit
    * @param ver_en true: enable the vertical fit
    */
    void setFit(bool hor_en, bool ver_en)
    {
        lv_cont_set_fit(m_this, hor_en, ver_en);
    }

    /**
    * Set the style of a container
    * @param cont pointer to a container object
    * @param style pointer to the new style
    */
    //void setStyle(lv_obj_t *cont, lv_style_t * style)

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the layout of a container
    * @param cont pointer to container object
    * @return the layout from 'lv_cont_layout_t'
    */
    lv_layout_t getLayout()
    {
        return lv_cont_get_layout(m_this);
    }

    /**
    * Get horizontal fit enable attribute of a container
    * @param cont pointer to a container object
    * @return true: horizontal fit is enabled; false: disabled
    */
    bool getHorizontalFit()
    {
        return lv_cont_get_hor_fit(m_this);
    }

    /**
    * Get vertical fit enable attribute of a container
    * @param cont pointer to a container object
    * @return true: vertical fit is enabled; false: disabled
    */
    bool getVerticalFit()
    {
        return lv_cont_get_ver_fit(m_this);
    }


    /**
    * Get that width reduced by the horizontal padding. Useful if a layout is used.
    * @param cont pointer to a container object
    * @return the width which still fits into the container
    */
    lv_coord_t getFitWidth()
    {
        return lv_cont_get_fit_width(m_this);
    }

    /**
    * Get that height reduced by the vertical padding. Useful if a layout is used.
    * @param cont pointer to a container object
    * @return the height which still fits into the container
    */
    lv_coord_t getFitHeight()
    {
        return lv_cont_get_fit_height(m_this);
    }

    /**
    * Get the style of a container
    * @param cont pointer to a container object
    * @return pointer to the container's style
    */
    //lv_style_t * getStyle(const lv_obj_t *cont)
};

#endif // LVCONTAINER_H
