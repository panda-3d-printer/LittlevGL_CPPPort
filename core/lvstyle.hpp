#ifndef LVSTYLE_H
#define LVSTYLE_H

#include <lvgl/lv_core/lv_style.h>
#include <misc/lvmemory.h>

using LVStyleAnim = lv_style_anim_t;

//using LVStyle = lv_style_t;

/**
 * @brief LVGL样式库
 */
class LVStyle
{
    LV_MEMAORY_FUNC

private:
    lv_style_t m_this;
public:

    /**
     *  Init the basic styles
     */
    static void init()
    {
        lv_style_init();
    }

    LVStyle()
    {}

    /**
     * Copy a style to an other
     * @param dest pointer to the destination style
     * @param src pointer to the source style
     */
    LVStyle(lv_style_t * src)
    {
        lv_style_copy(&m_this,src);
    }

    LVStyle(const lv_style_t & src)
    {
        lv_style_copy(&m_this,&src);
    }

    LVStyle & operator=(lv_style_t * src)
    {
        lv_style_copy(&m_this,src);
        return *this;
    }

    LVStyle & operator=(const lv_style_t& src)
    {
        lv_style_copy(&m_this,&src);
        return *this;
    }

    lv_style_t * operator->()
    {
        return &m_this;
    }

    operator lv_style_t * ()
    {
        return &m_this;
    }


    /**
     * Mix two styles according to a given ratio
     * @param start start style
     * @param end end style
     * @param res store the result style here
     * @param ratio the ratio of mix [0..256]; 0: `start` style; 256: `end` style
     */
    void mix(const lv_style_t * end, lv_style_t * res, uint16_t ratio)
    {
        lv_style_mix(&m_this,end,res,ratio);
    }
};


class LVStyleAnimation
{
    LV_MEMAORY_FUNC

private:
    lv_style_anim_t m_this;
public:

    LVStyleAnimation ()
    {}

    lv_style_anim_t * operator ->()
    {
        return &m_this;
    }

    /**
     * Create an animation from a pre-configured 'lv_style_anim_t' variable
     * @param anim pointer to a pre-configured 'lv_style_anim_t' variable (will be copied)
     * @return pointer to a descriptor. Really this variable will be animated. (Can be used in `lv_anim_del(dsc, NULL)`)
     */
    void * create()
    {
        return lv_style_anim_create(&m_this);
    }
};

#endif // LVSTYLE_H
