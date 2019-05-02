#ifndef LVLANG_H
#define LVLANG_H

#include <lvgl/lv_core/lv_lang.h>
/**
 * @brief 多语言支持
 * 静态类
 */
class LVLang
{
protected:
    LVLang(){}
public:

    /**
     * Change the language
     * @param lang_id the id of the
     */
    static void langSet(uint8_t lang_id)
    {
        lv_lang_set(lang_id);
    }

    /**
     * Set a function to get the texts of the set languages from a `txt_id`
     * @param fp a function pointer to get the texts
     */
    static void setTextFunc(const void * (*fp)(uint16_t))
    {
        lv_lang_set_text_func(fp);
    }

    /**
     * Use the function set by `lv_lang_set_text_func` to get the `txt_id` text in the set language
     * @param txt_id an ID of the text to get
     * @return the `txt_id` txt on the set language
     */
    static const void * lv_lang_get_text(uint16_t txt_id)
    {
        return lv_lang_get_text(txt_id);
    }

    /**
     * Return with ID of the currently selected language
     * @return selected language id
     */
    static uint8_t langActived()
    {
        return lv_lang_act();
    }
};

#endif // LVLANG_H
