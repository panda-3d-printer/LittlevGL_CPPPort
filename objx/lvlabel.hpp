#ifndef LVLABEL_H
#define LVLABEL_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_label.h>
#include <lvgl/lv_core/lv_lang.h>

//无效文本
#define NONETEXT LV_LANG_TXT_ID_NONE

/**
 * @brief LVGL 标签对象
 *
 * BUG:析构时不会释放文本数据
 *
 */
class LVLabel : public LVObject
{
    LV_OBJECT
public:
    /**
    * Create a label objects
    * @param par pointer to an object, it will be the parent of the new label
    * @param copy pointer to a label object, if not NULL then the new object will be copied from it
    * @return pointer to the created button
    */

    DEFINE_CONSTRUCTOR(LVLabel,lv_label_create,LVObject)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a new text for a label. Memory will be allocated to store the text by the label.
    * @param label pointer to a label object
    * @param text '\0' terminated character string. NULL to refresh with the current text.
    */
    void setText(const char * text);

#if USE_LV_MULTI_LANG

    /**
     * @brief 设置文本内容及其ID
     * @param text
     * @param textId
     */
    void setText(const char * text,uint16_t textId);


    void setText(uint16_t textId)
    {
        setText((const char *)lv_lang_get_text(textId),textId);
    }

    void setTextID(uint16_t textId)
    {
        lv_label_set_text_id(m_this,textId);
    }

#endif

    /**
    * Set a new text for a label from a character array. The array don't has to be '\0' terminated.
    * Memory will be allocated to store the array by the label.
    * @param label pointer to a label object
    * @param array array of characters or NULL to refresh the label
    * @param size the size of 'array' in bytes
    */
    void setArrayText(const char * array, uint16_t size)
    {
        lv_label_set_array_text(m_this,array,size);
    }

    /**
    * Set a static text. It will not be saved by the label so the 'text' variable
    * has to be 'alive' while the label exist.
    * @param label pointer to a label object
    * @param text pointer to a text. NULL to refresh with the current text.
    */
    void setStaticText(const char * text)
    {
        lv_label_set_static_text(m_this,text);
    }

    /**
    * Set the behavior of the label with longer text then the object size
    * @param label pointer to a label object
    * @param long_mode the new mode from 'lv_label_long_mode' enum.
    *                  In LV_LONG_BREAK/LONG/ROLL the size of the label should be set AFTER this function
    */
    void setLongMode(lv_label_long_mode_t long_mode)
    {
        lv_label_set_long_mode(m_this,long_mode);
    }

    /**
    * Set the align of the label (left or center)
    * @param label pointer to a label object
    * @param align 'LV_LABEL_ALIGN_LEFT' or 'LV_LABEL_ALIGN_LEFT'
    */
    void setAlign(lv_label_align_t align)
    {
        lv_label_set_align(m_this,align);
    }

    /**
    * Enable the recoloring by in-line commands
    * @param label pointer to a label object
    * @param recolor_en true: enable recoloring, false: disable
    */
    void setRecolor(bool recolor_en)
    {
        lv_label_set_recolor(m_this,recolor_en);
    }

    /**
    * Set the label to draw (or not draw) background specified in its style's body
    * @param label pointer to a label object
    * @param body_en true: draw body; false: don't draw body
    */
    void SetBodyDraw(bool body_en)
    {
        lv_label_set_body_draw(m_this,body_en);
    }

    /**
    * Set the label's animation speed in LV_LABEL_LONG_ROLL and SCROLL modes
    * @param label pointer to a label object
    * @param anim_speed speed of animation in px/sec unit
    */
    void setAnimSpeed(uint16_t anim_speed)
    {
        lv_label_set_anim_speed(m_this,anim_speed);
    }

    /**
    * Set the style of an label
    * @param label pointer to an label object
    * @param style pointer to a style
    */
    //inline void setStyle(lv_style_t *style)

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the text of a label
    * @param label pointer to a label object
    * @return the text of the label
    */
    char * getText()
    {
        return lv_label_get_text(m_this);
    }

    uint16_t getTextID()
    {
        lv_label_ext_t * ext = static_cast<lv_label_ext_t*>(lv_obj_get_ext_attr(m_this));
        return ext->lang_txt_id;
    }

    /**
    * Get the long mode of a label
    * @param label pointer to a label object
    * @return the long mode
    */
    lv_label_long_mode_t getLongMode()
    {
        return lv_label_get_long_mode(m_this);
    }

    /**
    * Get the align attribute
    * @param label pointer to a label object
    * @return LV_LABEL_ALIGN_LEFT or LV_LABEL_ALIGN_CENTER
    */
    lv_label_align_t getAlign()
    {
        return lv_label_get_align(m_this);
    }

    /**
    * Get the recoloring attribute
    * @param label pointer to a label object
    * @return true: recoloring is enabled, false: disable
    */
    bool getRecolor()
    {
        return lv_label_get_recolor(m_this);
    }

    /**
    * Get the body draw attribute
    * @param label pointer to a label object
    * @return true: draw body; false: don't draw body
    */
    bool getBodyDraw()
    {
        return lv_label_get_body_draw(m_this);
    }

    /**
    * Get the label's animation speed in LV_LABEL_LONG_ROLL and SCROLL modes
    * @param label pointer to a label object
    * @return speed of animation in px/sec unit
    */
    uint16_t getAnimSpeed()
    {
        return lv_label_get_anim_speed(m_this);
    }

    /**
    * Get the relative x and y coordinates of a letter
    * @param label pointer to a label object
    * @param index index of the letter [0 ... text length]. Expressed in character index, not byte index (different in UTF-8)
    * @param pos store the result here (E.g. index = 0 gives 0;0 coordinates)
    */
    void getLetterPos(uint16_t index, lv_point_t * pos)
    {
        lv_label_get_letter_pos(m_this,index,pos);
    }

    lv_point_t * getLetterPos(uint16_t index)
    {
        lv_point_t * pos = nullptr;
        lv_label_get_letter_pos(m_this,index,pos);
        return pos;
    }

    /**
    * Get the index of letter on a relative point of a label
    * @param label pointer to label object
    * @param pos pointer to point with coordinates on a the label
    * @return the index of the letter on the 'pos_p' point (E.g. on 0;0 is the 0. letter)
    * Expressed in character index and not byte index (different in UTF-8)
    */
    uint16_t getLetterOn(lv_point_t * pos)
    {
        return lv_label_get_letter_on(m_this, pos);
    }

    /**
    * Get the style of an label object
    * @param label pointer to an label object
    * @return pointer to the label's style
    */
    static inline lv_style_t* getStyle(const lv_obj_t *label)
    {
        return lv_label_get_style(label);
    }

    /*=====================
    * Other functions
    *====================*/

    /**
    * Insert a text to the label. The label text can not be static.
    * @param label pointer to a label object
    * @param pos character index to insert. Expressed in character index and not byte index (Different in UTF-8)
    *            0: before first char.
    *            LV_LABEL_POS_LAST: after last char.
    * @param txt pointer to the text to insert
    */
    void insertText(uint32_t pos,  const char * txt)
    {
        lv_label_ins_text(m_this, pos, txt);
    }

    /**
    * Delete characters from a label. The label text can not be static.
    * @param label pointer to a label object
    * @param pos character index to insert. Expressed in character index and not byte index (Different in UTF-8)
    *            0: before first char.
    * @param cnt number of characters to cut
    */
    void cutText(uint32_t pos,  uint32_t cnt)
    {
        lv_label_cut_text(m_this, pos, cnt);
    }

//protected:
    ////////////////// 增强功能 ////////////////////////

//    lv_res_t onLangChanged(struct _lv_obj_t * obj, lv_signal_t sign, void * param);

    void setValue(int32_t value);
    void setValue(float value);
    int32_t getIntValue();
    float getFloatValue();

};


#endif // LVLABEL_H
