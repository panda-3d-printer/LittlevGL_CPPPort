#ifndef LVCALENDAR_H
#define LVCALENDAR_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_calendar.h>

class LVCalendar : public LVObject
{
    LV_OBJECT
public:

    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a calendar objects
    * @param par pointer to an object, it will be the parent of the new calendar
    * @param copy pointer to a calendar object, if not NULL then the new object will be copied from it
    * @return pointer to the created calendar
    */
    DEFINE_CONSTRUCTOR(LVCalendar,lv_calendar_create,LVObject)

    /*======================
    * Add/remove functions
    *=====================*/


    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the today's date
    * @param calendar pointer to a calendar object
    * @param today pointer to an `lv_calendar_date_t` variable containing the date of today. The value will be saved it can be local variable too.
    */
    void setTodayDate(lv_calendar_date_t * today)
    {
        lv_calendar_set_today_date(m_this, today);
    }

    /**
    * Set the currently showed
    * @param calendar pointer to a calendar object
    * @param showed pointer to an `lv_calendar_date_t` variable containing the date to show. The value will be saved it can be local variable too.
    */
    void setShowedDate(lv_calendar_date_t * showed)
    {
        lv_calendar_set_showed_date(m_this, showed);
    }

    /**
    * Set the the highlighted dates
    * @param calendar pointer to a calendar object
    * @param highlighted pointer to an `lv_calendar_date_t` array containing the dates. ONLY A POINTER WILL BE SAVED! CAN'T BE LOCAL ARRAY.
    * @param date_num number of dates in the array
    */
    void setHighlightedDates(lv_calendar_date_t * highlighted, uint16_t date_num)
    {
        lv_calendar_set_highlighted_dates(m_this, highlighted, date_num);
    }


    /**
    * Set the name of the days
    * @param calendar pointer to a calendar object
    * @param day_names pointer to an array with the names. E.g. `const char * days[7] = {"Sun", "Mon", ...}`
    *                  Only the pointer will be saved so this variable can't be local which will be destroyed later.
    */
    void setDayNames(const char ** day_names)
    {
        lv_calendar_set_day_names(m_this, day_names);
    }

    /**
    * Set the name of the month
    * @param calendar pointer to a calendar object
    * @param day_names pointer to an array with the names. E.g. `const char * days[12] = {"Jan", "Feb", ...}`
    *                  Only the pointer will be saved so this variable can't be local which will be destroyed later.
    */
    void setMonthNames(const char ** day_names)
    {
        lv_calendar_set_month_names(m_this,day_names);
    }

    /**
    * Set a style of a calendar.
    * @param calendar pointer to calendar object
    * @param type which style should be set
    * @param style pointer to a style
    *  */
    void setStyle( lv_calendar_style_t type, lv_style_t *style)
    {
        lv_calendar_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the today's date
    * @param calendar pointer to a calendar object
    * @return return pointer to an `lv_calendar_date_t` variable containing the date of today.
    */
    lv_calendar_date_t * getTodayDate()
    {
        return lv_calendar_get_today_date(m_this);
    }

    /**
    * Get the currently showed
    * @param calendar pointer to a calendar object
    * @return pointer to an `lv_calendar_date_t` variable containing the date is being shown.
    */
    lv_calendar_date_t * getShowedDate()
    {
        return lv_calendar_get_showed_date(m_this);
    }

    /**
    * Get the the highlighted dates
    * @param calendar pointer to a calendar object
    * @return pointer to an `lv_calendar_date_t` array containing the dates.
    */
    lv_calendar_date_t * getHighlightedDates()
    {
        return lv_calendar_get_highlighted_dates(m_this);
    }

    /**
    * Get the number of the highlighted dates
    * @param calendar pointer to a calendar object
    * @return number of highlighted days
    */
    uint16_t getHighlightedDatesNum()
    {
        return lv_calendar_get_highlighted_dates_num(m_this);
    }


    /**
    * Get the name of the days
    * @param calendar pointer to a calendar object
    * @return pointer to the array of day names
    */
    const char ** getDayNames()
    {
        return lv_calendar_get_day_names(m_this);
    }

    /**
    * Get the name of the month
    * @param calendar pointer to a calendar object
    * @return pointer to the array of month names
    */
    const char ** getMonthNames()
    {
        return lv_calendar_get_month_names(m_this);
    }

    /**
    * Get style of a calendar.
    * @param calendar pointer to calendar object
    * @param type which style should be get
    * @return style pointer to the style
    *  */
    lv_style_t * getStyle(lv_calendar_style_t type)
    {
        return lv_calendar_get_style(m_this, type);
    }
};

#endif // LVCALENDAR_H
