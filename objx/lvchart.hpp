#ifndef LVCHART_H
#define LVCHART_H

#include <lvgl/lv_objx/lv_chart.h>
#include <core/lvobject.hpp>

/**
 *  图表数据集合
 */
using LVSeries = lv_chart_series_t;


class LVChart : public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a chart background objects
    * @param par pointer to an object, it will be the parent of the new chart background
    * @param copy pointer to a chart background object, if not NULL then the new object will be copied from it
    * @return pointer to the created chart background
    */
    DEFINE_CONSTRUCTOR(LVChart,lv_chart_create,LVObject)

    /*======================
    * Add/remove functions
    *=====================*/

    /**
    * Allocate and add a data series to the chart
    * @param chart pointer to a chart object
    * @param color color of the data series
    * @return pointer to the allocated data series
    */
    lv_chart_series_t * addSeries(lv_color_t color)
    {
        return lv_chart_add_series(m_this,color);
    }

    /**
     * Clear the point of a serie
     * @param chart pointer to a chart object
     * @param serie pointer to the chart's serie to clear
     */
    void clearSerie(lv_chart_series_t * serie)
    {
        lv_chart_clear_serie(m_this, serie);
    }

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the number of horizontal and vertical division lines
    * @param chart pointer to a graph background object
    * @param hdiv number of horizontal division lines
    * @param vdiv number of vertical division lines
    */
    void setDivisionLineCount(uint8_t hdiv, uint8_t vdiv)
    {
        lv_chart_set_div_line_count(m_this, hdiv, vdiv);
    }

    /**
    * Set the minimal and maximal y values
    * @param chart pointer to a graph background object
    * @param ymin y minimum value
    * @param ymax y maximum value
    */
    void setRange(lv_coord_t ymin, lv_coord_t ymax)
    {
        lv_chart_set_range(m_this, ymin, ymax);
    }

    /**
    * Set a new type for a chart
    * @param chart pointer to a chart object
    * @param type new type of the chart (from 'lv_chart_type_t' enum)
    */
    void setType(lv_chart_type_t type)
    {
        lv_chart_set_type(m_this, type);
    }

    /**
    * Set the number of points on a data line on a chart
    * @param chart pointer r to chart object
    * @param point_cnt new number of points on the data lines
    */
    void setPointCount(uint16_t point_cnt)
    {
        lv_chart_set_point_count(m_this,point_cnt);
    }

    /**
    * Set the opacity of the data series
    * @param chart pointer to a chart object
    * @param opa opacity of the data series
    */
    void setSeriesOpacity(lv_opa_t opa)
    {
        lv_chart_set_series_opa(m_this, opa);
    }

    /**
    * Set the line width or point radius of the data series
    * @param chart pointer to a chart object
    * @param width the new width
    */
    void setSeriesWidth(lv_coord_t width)
    {
        lv_chart_set_series_width(m_this, width);
    }

    /**
    * Set the dark effect on the bottom of the points or columns
    * @param chart pointer to a chart object
    * @param dark_eff dark effect level (LV_OPA_TRANSP to turn off)
    */
    void setSeriesDarking(lv_opa_t dark_eff)
    {
        lv_chart_set_series_darking(m_this, dark_eff);
    }

    /**
    * Initialize all data points with a value
    * @param chart pointer to chart object
    * @param ser pointer to a data series on 'chart'
    * @param y the new value  for all points
    */
    void initPoints(lv_chart_series_t * ser, lv_coord_t y)
    {
        lv_chart_init_points(m_this,ser,y);
    }

    /**
    * Set the value s of points from an array
    * @param chart pointer to chart object
    * @param ser pointer to a data series on 'chart'
    * @param y_array array of 'lv_coord_t' points (with 'points count' elements )
    */
    void setPoints(lv_chart_series_t * ser, lv_coord_t * y_array)
    {
        lv_chart_set_points(m_this, ser,y_array);
    }

    /**
    * Shift all data right and set the most right data on a data line
    * @param chart pointer to chart object
    * @param ser pointer to a data series on 'chart'
    * @param y the new value of the most right data
    */
    void setNext(lv_chart_series_t * ser, lv_coord_t y)
    {
        lv_chart_set_next(m_this, ser, y);
    }

    /**
    * Set the style of a chart
    * @param chart pointer to a chart object
    * @param style pointer to a style
    */
    //inline void set_style(lv_style_t *style)

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the type of a chart
    * @param chart pointer to chart object
    * @return type of the chart (from 'lv_chart_t' enum)
    */
    lv_chart_type_t getType()
    {
        return lv_chart_get_type(m_this);
    }

    /**
    * Get the data point number per data line on chart
    * @param chart pointer to chart object
    * @return point number on each data line
    */
    uint16_t getPointCount()
    {
        return lv_chart_get_point_cnt(m_this);
    }

    /**
    * Get the opacity of the data series
    * @param chart pointer to chart object
    * @return the opacity of the data series
    */
    lv_opa_t getSeriesOpacity()
    {
        return lv_chart_get_series_opa(m_this);
    }

    /**
    * Get the data series width
    * @param chart pointer to chart object
    * @return the width the data series (lines or points)
    */
    lv_coord_t getSeriesWidth()
    {
        return lv_chart_get_series_width(m_this);
    }

    /**
    * Get the dark effect level on the bottom of the points or columns
    * @param chart pointer to chart object
    * @return dark effect level (LV_OPA_TRANSP to turn off)
    */
    lv_opa_t getSeriesDarking()
    {
        return lv_chart_get_series_darking(m_this);
    }

    /**
    * Get the style of an chart object
    * @param chart pointer to an chart object
    * @return pointer to the chart's style
    */
    //inline lv_style_t* getStyle();

    /*=====================
    * Other functions
    *====================*/

    /**
    * Refresh a chart if its data line has changed
    * @param chart pointer to chart object
    */
    void refresh()
    {
        lv_chart_refresh(m_this);
    }
};

#endif // LVCHART_H
