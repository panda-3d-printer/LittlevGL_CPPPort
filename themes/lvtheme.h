#ifndef LVTHEME_H
#define LVTHEME_H

#include <misc/lvmemory.h>
#include <lvgl/lv_themes/lv_theme.h>
#include <lvgl/lv_themes/lv_theme_alien.h>
#include <lvgl/lv_themes/lv_theme_default.h>
#include <lvgl/lv_themes/lv_theme_material.h>
#include <lvgl/lv_themes/lv_theme_mono.h>
#include <lvgl/lv_themes/lv_theme_nemo.h>
#include <lvgl/lv_themes/lv_theme_night.h>
#include <lvgl/lv_themes/lv_theme_zen.h>

class LVTheme
{
    LV_MEMAORY_FUNC

private:
    lv_theme_t * m_this = nullptr;
public:

    /**
     * @brief 预设的主题类型
     */
    enum ThemeName
    {
        LVTheme_alien   ,
        LVTheme_default ,
        LVTheme_material,
        LVTheme_mono    ,
        LVTheme_nemo    ,
        LVTheme_night   ,
        LVTheme_zen
    };

    /**
     * Initialize the alien theme
     * @param theme which theme to creat
     * @param hue [0..360] hue value from HSV color space to define the theme's base color
     * @param font pointer to a font (NULL to use the default)
     * @return pointer to the initialized theme
     */

    LVTheme()
    {
    }

    LVTheme(ThemeName theme,uint16_t hue, lv_font_t * font)
    {
        switch (theme)
        {
#if USE_LV_THEME_ALIEN==1
            case LVTheme_alien    : m_this = lv_theme_alien_init(hue,font); break;
#endif
#if USE_LV_THEME_DEFAULT==1
            case LVTheme_default  : m_this = lv_theme_default_init(hue,font); break;
#endif
#if USE_LV_THEME_MATERIAL==1
            case LVTheme_material : m_this = lv_theme_material_init(hue,font); break;
#endif
#if USE_LV_THEME_MONO==1
            case LVTheme_mono     : m_this = lv_theme_mono_init(hue,font); break;
#endif
#if USE_LV_THEME_NEMO==1
            case LVTheme_nemo     : m_this = lv_theme_nemo_init(hue,font); break;
#endif
#if USE_LV_THEME_NIGHT==1
            case LVTheme_night    : m_this = lv_theme_night_init(hue,font); break;
#endif
#if USE_LV_THEME_ZEN==1
            case LVTheme_zen      : m_this = lv_theme_zen_init(hue,font); break;
#endif
            default: m_this = lv_theme_default_init(hue,font); break;
        }
    }

    LVTheme(lv_theme_t * theme)
    {
        m_this = theme;
    }

    LVTheme(LVTheme & theme)
    {
        m_this = theme.m_this;
    }

    lv_theme_t * operator ->()
    {
        return m_this;
    }

    //operator lv_theme_t *()
    //{
    //    return m_this;
    //}

    LVTheme & operator = (lv_theme_t * th)
    {
        m_this = th;
        return *this;
    }

    /**
    * Set a theme for the system.
    * From now, all the created objects will use styles from this theme by default
    * @param th pointer to theme (return value of: 'lv_theme_init_xxx()')
    */
    static void setCurrent(lv_theme_t *th)
    {
        lv_theme_set_current(th);
    }

    void setCurrent()
    {
        lv_theme_set_current(m_this);
    }

    /**
    * Get the current system theme.
    * @return pointer to the current system theme. NULL if not set.
    */
    static lv_theme_t * getCurrent(void)
    {
        return lv_theme_get_current();
    }
};

#endif // LVTHEME_H
