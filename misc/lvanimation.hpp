#ifndef LVANIMATION_H
#define LVANIMATION_H

#include <lvgl/lv_misc/lv_anim.h>
#include <misc/lvmemory.h>

class LVAnimation
{
    LV_MEMAORY_FUNC

private:
    lv_anim_t m_this;
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Init. the animation module
    */
    static void init(void)
    {
        lv_anim_init();
    }

    LVAnimation()
    {
    }

    /**
    * Create an animation
    * @param anim_p an initialized 'anim_t' variable. Not required after call.
    */
    void create()
    {
        lv_anim_create(&m_this);
    }

    lv_anim_t * operator ->()
    {
        return &m_this;
    }

    /**
    * Delete an animation for a variable with a given animatior function
    * @param var pointer to variable
    * @param fp a function pointer which is animating 'var',
    *           or NULL to ignore it and delete all animation with 'var
    * @return true: at least 1 animation is deleted, false: no animation is deleted
    */
    bool delete_(void * var, lv_anim_fp_t fp)
    {
        return lv_anim_del(var, fp);
    }

    /**
    * Calculate the time of an animation with a given speed and the start and end values
    * @param speed speed of animation in unit/sec
    * @param start start value of the animation
    * @param end end value of the animation
    * @return the required time [ms] for the animation with the given parameters
    */
    static uint16_t speedToTime(uint16_t speed, int32_t start, int32_t end)
    {
        return lv_anim_speed_to_time(speed, start, end);
    }

    /**
    * Calculate the current value of an animation applying linear characteristic
    * @param a pointer to an animation
    * @return the current value to set
    */
    int32_t pathLinear()
    {
        return lv_anim_path_linear(&m_this);
    }


    /**
    * Calculate the current value of an animation applying an "S" characteristic (cosine)
    * @param a pointer to an animation
    * @return the current value to set
    */
    int32_t pathEaseInOut()
    {
        return  lv_anim_path_ease_in_out(&m_this);
    }

    /**
    * Calculate the current value of an animation applying step characteristic.
    * (Set end value on the end of the animation)
    * @param a pointer to an animation
    * @return the current value to set
    */
    int32_t pathStep()
    {
        return lv_anim_path_step(&m_this);
    }

};

#endif // LVANIMATION_H
