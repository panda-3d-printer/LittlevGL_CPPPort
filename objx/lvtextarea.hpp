#ifndef LVTEXTAREA_H
#define LVTEXTAREA_H

#include <objx/lvpage.hpp>
#include <lvgl/lv_objx/lv_ta.h>

class LVTextArea : public LVPage
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/


    /**
    * Create a text area objects
    * @param par pointer to an object, it will be the parent of the new text area
    * @param copy pointer to a text area object, if not NULL then the new object will be copied from it
    * @return pointer to the created text area
    */
    DEFINE_CONSTRUCTOR(LVTextArea,lv_ta_create,LVPage)


    /*======================
    * Add/remove functions
    *=====================*/

    /**
    * Insert a character to the current cursor position.
    * To add a wide char, e.g. 'Á' use `lv_txt_encoded_conv_wc('Á')`
    * @param ta pointer to a text area object
    * @param c a character (e.g. 'a')
    */
    void addChar(uint32_t c)
    {
        lv_ta_add_char(m_this, c);
    }

    /**
    * Insert a text to the current cursor position
    * @param ta pointer to a text area object
    * @param txt a '\0' terminated string to insert
    */
    void addText(const char * txt)
    {
        lv_ta_add_text(m_this,txt);
    }

    /**
    * Delete a the left character from the current cursor position
    * @param ta pointer to a text area object
    */
    void deleteChar()
    {
        lv_ta_del_char(m_this);
    }

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the text of a text area
    * @param ta pointer to a text area
    * @param txt pointer to the text
    */
    void setText(const char * txt)
    {
        lv_ta_set_text(m_this,txt);
    }

    /**
    * Set the cursor position
    * @param obj pointer to a text area object
    * @param pos the new cursor position in character index
    *             < 0 : index from the end of the text
    *             LV_TA_CURSOR_LAST: go after the last character
    */
    void setCursorPos(int16_t pos)
    {
        lv_ta_set_cursor_pos(m_this, pos);
    }

    /**
    * Set the cursor type.
    * @param ta pointer to a text area object
    * @param cur_type: element of 'lv_cursor_type_t'
    */
    void setCursorType(lv_cursor_type_t cur_type)
    {
        lv_ta_set_cursor_type(m_this, cur_type);
    }

    /**
    * Enable/Disable password mode
    * @param ta pointer to a text area object
    * @param pwd_en true: enable, false: disable
    */
    void setPasswordMode( bool pwd_en)
    {
        lv_ta_set_pwd_mode(m_this, pwd_en);
    }

    /**
    * Configure the text area to one line or back to normal
    * @param ta pointer to a Text area object
    * @param en true: one line, false: normal
    */
    void setOneLine( bool en)
    {
        lv_ta_set_one_line(m_this, en);
    }

    /**
    * Set the alignment of the text area.
    * In one line mode the text can be scrolled only with `LV_LABEL_ALIGN_LEFT`.
    * This function should be called if the size of text area changes.
    * @param ta pointer to a text are object
    * @param align the desired alignment from `lv_label_align_t`. (LV_LABEL_ALIGN_LEFT/CENTER/RIGHT)
    */
    void setTextAlign(lv_label_align_t align)
    {
        lv_ta_set_text_align(m_this, align);
    }

    /**
    * Set a list of characters. Only these characters will be accepted by the text area
    * @param ta pointer to  Text Area
    * @param list list of characters. Only the pointer is saved. E.g. "+-.,0123456789"
    */
    void setAcceptedChars(const char * list)
    {
        lv_ta_set_accepted_chars(m_this,list);
    }

    /**
    * Set max length of a Text Area.
    * @param ta pointer to  Text Area
    * @param num the maximal number of characters can be added (`lv_ta_set_text` ignores it)
    */
    void setMaxLength(uint16_t num)
    {
        lv_ta_set_max_length(m_this, num);
    }

    /**
    * Set an action to call when the Text area is clicked
    * @param ta pointer to a Text area
    * @param action a function pointer
    */
    void setAction(lv_action_t action)
    {
        lv_ta_set_action(m_this, action);
    }

    /**
    * Set the scroll bar mode of a text area
    * @param ta pointer to a text area object
    * @param sb_mode the new mode from 'lv_page_sb_mode_t' enum
    */
    //void setScrollBarMode(lv_sb_mode_t mode)

    /**
    * Set a style of a text area
    * @param ta pointer to a text area object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_ta_style_t type, lv_style_t *style)
    {
        lv_ta_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the text of a text area. In password mode it gives the real text (not '*'s).
    * @param ta pointer to a text area object
    * @return pointer to the text
    */
    const char * getText()
    {
        return lv_ta_get_text(m_this);
    }

    /**
    * Get the label of a text area
    * @param ta pointer to a text area object
    * @return pointer to the label object
    */
    lv_obj_t * getLabel()
    {
        return lv_ta_get_label(m_this);
    }

    /**
    * Get the current cursor position in character index
    * @param ta pointer to a text area object
    * @return the cursor position
    */
    uint16_t getCursorPos()
    {
        return lv_ta_get_cursor_pos(m_this);
    }

    /**
    * Get the current cursor visibility.
    * @param ta pointer to a text area object
    * @return true: the cursor is drawn, false: the cursor is hidden
    */
    bool getCursorShow()
    {
        // return lv_ta_get_cursor_show(m_this); //TODO: check
    }

    /**
    * Get the current cursor type.
    * @param ta pointer to a text area object
    * @return element of 'lv_cursor_type_t'
    */
    lv_cursor_type_t getCursorType()
    {
        return lv_ta_get_cursor_type(m_this);
    }

    /**
    * Get the password mode attribute
    * @param ta pointer to a text area object
    * @return true: password mode is enabled, false: disabled
    */
    bool getPasswordMode()
    {
        return lv_ta_get_pwd_mode(m_this);
    }

    /**
    * Get the one line configuration attribute
    * @param ta pointer to a text area object
    * @return true: one line configuration is enabled, false: disabled
    */
    bool getOneLine()
    {
        return lv_ta_get_one_line(m_this);
    }

    /**
    * Get a list of accepted characters.
    * @param ta pointer to  Text Area
    * @return list of accented characters.
    */
    const char * getAcceptedChars()
    {
        return lv_ta_get_accepted_chars(m_this);
    }

    /**
    * Set max length of a Text Area.
    * @param ta pointer to  Text Area
    * @return the maximal number of characters to be add
    */
    uint16_t getMaxLength()
    {
        return lv_ta_get_max_length(m_this);
    }

    /**
    * Set an action to call when the Text area is clicked
    * @param ta pointer to a Text area
    * @param action a function pointer
    */
    lv_action_t getAction()
    {
        return lv_ta_get_action(m_this);
    }

    /**
    * Get the scroll bar mode of a text area
    * @param ta pointer to a text area object
    * @return scrollbar mode from 'lv_page_sb_mode_t' enum
    */
    //lv_sb_mode_t getScrollBarMode()

    /**
    * Get a style of a text area
    * @param ta pointer to a text area object
    * @param type which style should be get
    * @return style pointer to a style
    */
    lv_style_t * getStyle(lv_ta_style_t type)
    {
        return lv_ta_get_style(m_this, type);
    }

    /*=====================
    * Other functions
    *====================*/

    /**
    * Move the cursor one character right
    * @param ta pointer to a text area object
    */
    void cursorRight()
    {
        lv_ta_cursor_right(m_this);
    }

    /**
    * Move the cursor one character left
    * @param ta pointer to a text area object
    */
    void cursorLeft()
    {
        lv_ta_cursor_left(m_this);
    }

    /**
    * Move the cursor one line down
    * @param ta pointer to a text area object
    */
    void cursorDown()
    {
        lv_ta_cursor_down(m_this);
    }

    /**
    * Move the cursor one line up
    * @param ta pointer to a text area object
    */
    void cursorUp()
    {
        lv_ta_cursor_up(m_this);
    }
};

#endif // LVTEXTAREA_H
