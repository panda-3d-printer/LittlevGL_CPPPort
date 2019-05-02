#ifndef LVIMAGEBUTTON_H
#define LVIMAGEBUTTON_H

#include <objx/lvbutton.hpp>
#include <lvgl/lv_objx/lv_imgbtn.h>

class LVImageButton : public LVButton
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a image button objects
    * @param par pointer to an object, it will be the parent of the new image button
    * @param copy pointer to a image button object, if not NULL then the new object will be copied from it
    * @return pointer to the created image button
    */
    DEFINE_CONSTRUCTOR(LVImageButton,lv_imgbtn_create,LVButton)

    /*======================
    * Add/remove functions
    *=====================*/


    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set images for a state of the image button
    * @param imgbtn pointer to an image button object
    * @param state for which state set the new image (from `lv_btn_state_t`) `
    * @param src pointer to an image source (a C array or path to a file)
    */
    void setSrc(lv_btn_state_t state, const void * src)
    {
        lv_imgbtn_set_src(m_this, state, src);
    }

    /**
    * Enable the toggled states. On release the button will change from/to toggled state.
    * @param imgbtn pointer to an image button object
    * @param tgl true: enable toggled states, false: disable
    */
    //void setToggle()

    /**
    * Set the state of the image button
    * @param imgbtn pointer to an image button object
    * @param state the new state of the button (from lv_btn_state_t enum)
    */
    //void setState(lv_btn_state_t state)

    /**
    * Toggle the state of the image button (ON->OFF, OFF->ON)
    * @param imgbtn pointer to a image button object
    */
    //void toggle()

    /**
    * Set a function to call when a button event happens
    * @param imgbtn pointer to an image button object
    * @param action type of event form 'lv_action_t' (press, release, long press, long press repeat)
    */
    //void setSction(lv_btn_action_t type, lv_action_t action)

    /**
    * Set a style of a image button.
    * @param imgbtn pointer to image button object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_imgbtn_style_t type, lv_style_t *style)
    {
        lv_imgbtn_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the images in a  given state
    * @param imgbtn pointer to an image button object
    * @param state the state where to get the image (from `lv_btn_state_t`) `
    * @return pointer to an image source (a C array or path to a file)
    */
    const void * getSrc(lv_btn_state_t state)
    {
        return lv_imgbtn_get_src(m_this, state);
    }

    /**
    * Get the current state of the image button
    * @param imgbtn pointer to a image button object
    * @return the state of the button (from lv_btn_state_t enum)
    */
    //lv_btn_state_t getState()

    /**
    * Get the toggle enable attribute of the image button
    * @param imgbtn pointer to a image button object
    * @return ture: toggle enabled, false: disabled
    */
    //bool getToggle()

    /**
    * Get the release action of a image button
    * @param imgbtn pointer to a image button object
    * @return pointer to the release action function
    */
    //lv_action_t getAction(lv_btn_action_t type)

    /**
    * Get style of a image button.
    * @param imgbtn pointer to image button object
    * @param type which style should be get
    * @return style pointer to the style
    */
    lv_style_t * getStyle(lv_imgbtn_style_t type)
    {
        return lv_imgbtn_get_style(m_this, type);
    }
};

#endif // LVIMAGEBUTTON_H
