#ifndef LVLIST_H
#define LVLIST_H

#include <objx/lvpage.hpp>
#include <lvgl/lv_objx/lv_list.h>

class LVList : public LVPage
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a list objects
    * @param par pointer to an object, it will be the parent of the new list
    * @param copy pointer to a list object, if not NULL then the new object will be copied from it
    * @return pointer to the created list
    */
    DEFINE_CONSTRUCTOR(LVList,lv_list_create,LVPage)

    /**
    * Delete all children of the scrl object, without deleting scrl child.
    * @param obj pointer to an object
    */
    void clean()
    {
        lv_list_clean(m_this);
    }

    /*======================
    * Add/remove functions
    *=====================*/

    /**
    * Add a list element to the list
    * @param list pointer to list object
    * @param img_fn file name of an image before the text (NULL if unused)
    * @param txt text of the list element (NULL if unused)
    * @param rel_action pointer to release action function (like with lv_btn)
    * @return pointer to the new list element which can be customized (a button)
    */
    lv_obj_t * add(const void * img_src, const char * txt, lv_action_t rel_action)
    {
        return lv_list_add(m_this,img_src,txt, rel_action);
    }

    /*=====================
    * Setter functions
    *====================*/
    #if USE_LV_GROUP

    /**
    * Make a button selected
    * @param list pointer to a list object
    * @param btn pointer to a button to select
    */
    void setButtonSelected( lv_obj_t * btn)
    {
        lv_list_set_btn_selected(m_this, btn);
    }
    #endif

    /**
    * Set scroll animation duration on 'list_up()' 'list_down()' 'list_focus()'
    * @param list pointer to a list object
    * @param anim_time duration of animation [ms]
    */
    void setAnimationTime(uint16_t anim_time)
    {
        lv_list_set_anim_time(m_this , anim_time);
    }

    /**
    * Set the scroll bar mode of a list
    * @param list pointer to a list object
    * @param sb_mode the new mode from 'lv_page_sb_mode_t' enum
    */
    //void setScrollBarMode(lv_sb_mode_t mode)

    /**
    * Set a style of a list
    * @param list pointer to a list object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_list_style_t type, lv_style_t *style)
    {
        lv_list_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the text of a list element
    * @param btn pointer to list element
    * @return pointer to the text
    */
    static const char * getButtonText(const lv_obj_t * btn)
    {
        return lv_list_get_btn_text(btn);
    }
    /**
    * Get the label object from a list element
    * @param btn pointer to a list element (button)
    * @return pointer to the label from the list element or NULL if not found
    */
    static lv_obj_t * getButtonLabel(const lv_obj_t * btn)
    {
        return lv_list_get_btn_label(btn);
    }

    /**
    * Get the image object from a list element
    * @param btn pointer to a list element (button)
    * @return pointer to the image from the list element or NULL if not found
    */
    static lv_obj_t * getButtonImage(const lv_obj_t * btn)
    {
        return lv_list_get_btn_img(btn);
    }

    /**
    * Get the next button from list. (Starts from the bottom button)
    * @param list pointer to a list object
    * @param prev_btn pointer to button. Search the next after it.
    * @return pointer to the next button or NULL when no more buttons
    */
    lv_obj_t * getPrevButton(lv_obj_t * prev_btn)
    {
        return lv_list_get_prev_btn(m_this, prev_btn);
    }

    /**
    * Get the previous button from list. (Starts from the top button)
    * @param list pointer to a list object
    * @param prev_btn pointer to button. Search the previous before it.
    * @return pointer to the previous button or NULL when no more buttons
    */
    lv_obj_t * getNextButton(lv_obj_t * prev_btn)
    {
        return lv_list_get_next_btn(m_this, prev_btn);
    }

    #if USE_LV_GROUP
    /**
    * Get the currently selected button
    * @param list pointer to a list object
    * @return pointer to the selected button
    */
    lv_obj_t * getButtonSelected()
    {
        return lv_list_get_btn_selected(m_this);
    }
    #endif


    /**
    * Get scroll animation duration
    * @param list pointer to a list object
    * @return duration of animation [ms]
    */
    uint16_t getAnimationTime()
    {
        return lv_list_get_anim_time(m_this);
    }


    /**
    * Get the scroll bar mode of a list
    * @param list pointer to a list object
    * @return scrollbar mode from 'lv_page_sb_mode_t' enum
    */
    //lv_sb_mode_t getScrollBarMode()

    /**
    * Get a style of a list
    * @param list pointer to a list object
    * @param type which style should be get
    * @return style pointer to a style
    *  */
    lv_style_t * getStyle(lv_list_style_t type)
    {
        return lv_list_get_style(m_this, type);
    }

    /*=====================
    * Other functions
    *====================*/

    /**
    * Move the list elements up by one
    * @param list pointer a to list object
    */
    void up()
    {
        lv_list_up(m_this);
    }
    /**
    * Move the list elements down by one
    * @param list pointer to a list object
    */
    void down()
    {
        lv_list_down(m_this);
    }

    /**
    * Focus on a list button. It ensures that the button will be visible on the list.
    * @param btn pointer to a list button to focus
    * @param anim_en true: scroll with animation, false: without animation
    */
    static void focus(const lv_obj_t *btn, bool anim_en)
    {
        lv_list_focus(btn, anim_en);
    }
};

#endif // LVLIST_H
