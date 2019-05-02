#ifndef LVSPINBOX_H
#define LVSPINBOX_H

#include <objx/lvtextarea.hpp>
#include <lvgl/lv_objx/lv_spinbox.h>

class LVSpinbox : public LVTextArea
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a spinbox objects
    * @param par pointer to an object, it will be the parent of the new spinbox
    * @param copy pointer to a spinbox object, if not NULL then the new object will be copied from it
    * @return pointer to the created spinbox
    */
    DEFINE_CONSTRUCTOR(LVSpinbox,lv_spinbox_create,LVTextArea)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a style of a spinbox.
    * @param templ pointer to template object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_spinbox_style_t type, lv_style_t *style)
    {
        lv_spinbox_set_style(m_this, type, style);
    }

    /**
    * Set spinbox value
    * @param spinbox pointer to spinbox
    * @param i value to be set
    */
    void setValue(int32_t i)
    {
        lv_spinbox_set_value(m_this, i);
    }

    /**
    * Set spinbox digit format (digit count and decimal format)
    * @param spinbox pointer to spinbox
    * @param digit_count number of digit excluding the decimal separator and the sign
    * @param separator_position number of digit before the decimal point. If 0, decimal point is not shown
    */
    void setDigitFormat(uint8_t digit_count, uint8_t separator_position)
    {
        lv_spinbox_set_digit_format(m_this, digit_count, separator_position);
    }

    /**
    * Set spinbox step
    * @param spinbox pointer to spinbox
    * @param step steps on increment/decrement
    */
    void setStep(uint32_t step)
    {
        lv_spinbox_set_step(m_this, step);
    }

    /**
    * Set spinbox value range
    * @param spinbox pointer to spinbox
    * @param range_min maximum value, inclusive
    * @param range_max minimum value, inclusive
    */
    void setRange(int32_t range_min, int32_t range_max)
    {
        lv_spinbox_set_range(m_this, range_min, range_max);
    }

    /**
    * Set spinbox callback on calue change
    * @param spinbox pointer to spinbox
    * @param cb Callback function called on value change event
    */
    void setValueChangedCallBack( lv_spinbox_value_changed_cb_t cb)
    {
        lv_spinbox_set_value_changed_cb(m_this, cb);
    }

    /**
    * Set spinbox left padding in digits count (added between sign and first digit)
    * @param spinbox pointer to spinbox
    * @param cb Callback function called on value change event
    */
    void setPaddingLeft(uint8_t padding)
    {
        lv_spinbox_set_padding_left(m_this, padding);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get style of a spinbox.
    * @param templ pointer to template object
    * @param type which style should be get
    * @return style pointer to the style
    */
    lv_style_t * getStyle(lv_spinbox_style_t type)
    {
        return lv_spinbox_get_style(m_this, type);
    }

    /**
    * Get the spinbox numeral value (user has to convert to float according to its digit format)
    * @param spinbox pointer to spinbox
    * @return value integer value of the spinbox
    */
    int32_t getValue()
    {
        return lv_spinbox_get_value(m_this);
    }

    /*=====================
    * Other functions
    *====================*/

    /**
    * Select next lower digit for edition by dividing the step by 10
    * @param spinbox pointer to spinbox
    */
    void stepNext()
    {
        lv_spinbox_step_next(m_this);
    }

    /**
    * Select next higher digit for edition by multiplying the step by 10
    * @param spinbox pointer to spinbox
    */
    void stepPrevious()
    {
        lv_spinbox_step_previous(m_this);
    }

    /**
    * Increment spinbox value by one step
    * @param spinbox pointer to spinbox
    */
    void increment()
    {
        lv_spinbox_increment(m_this);
    }

    /**
    * Decrement spinbox value by one step
    * @param spinbox pointer to spinbox
    */
    void decrement()
    {
        lv_spinbox_decrement(m_this);
    }
};

#endif // LVSPINBOX_H
