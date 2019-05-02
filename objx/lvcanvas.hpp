#ifndef LVCANVAS_H
#define LVCANVAS_H

#include <objx/lvimage.hpp>
#include <lvgl/lv_objx/lv_canvas.h>

class LVCanvas : public LVImage
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create a canvas object
    * @param par pointer to an object, it will be the parent of the new canvas
    * @param copy pointer to a canvas object, if not NULL then the new object will be copied from it
    * @return pointer to the created canvas
    */
    DEFINE_CONSTRUCTOR(LVCanvas,lv_canvas_create,LVImage)

    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set a buffer for the canvas.
    * @param buf a buffer where the content of the canvas will be.
    * The required size is (lv_img_color_format_get_px_size(cf) * w * h) / 8)
    * It can be allocated with `lv_mem_alloc()` or
    * it can be statically allocated array (e.g. static lv_color_t buf[100*50]) or
    * it can be an address in RAM or external SRAM
    * @param canvas pointer to a canvas object
    * @param w width of the canvas
    * @param h height of the canvas
    * @param cf color format. The following formats are supported:
    *      LV_IMG_CF_TRUE_COLOR, LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED, LV_IMG_CF_INDEXES_1/2/4/8BIT
    */
    void setBuffer( void * buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf)
    {
        lv_canvas_set_buffer(m_this, buf, w, h, cf);
    }

    /**
    * Set the color of a pixel on the canvas
    * @param canvas
    * @param x x coordinate of the point to set
    * @param y x coordinate of the point to set
    * @param c color of the point
    */
    void setPixel(lv_coord_t x, lv_coord_t y, lv_color_t c)
    {
        lv_canvas_set_px(m_this, x, y, c);
    }

    /**
    * Set a style of a canvas.
    * @param canvas pointer to canvas object
    * @param type which style should be set
    * @param style pointer to a style
    */
    void setStyle(lv_canvas_style_t type, lv_style_t * style)
    {
        lv_canvas_set_style(m_this, type, style);
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the color of a pixel on the canvas
    * @param canvas
    * @param x x coordinate of the point to set
    * @param y x coordinate of the point to set
    * @return color of the point
    */
    lv_color_t getPixel(lv_coord_t x, lv_coord_t y)
    {
        return lv_canvas_get_px(m_this, x, y);
    }

    /**
    * Get style of a canvas.
    * @param canvas pointer to canvas object
    * @param type which style should be get
    * @return style pointer to the style
    */
    lv_style_t * getStyle(lv_canvas_style_t type)
    {
        return lv_canvas_get_style(m_this, type);
    }

    /*=====================
    * Other functions
    *====================*/

    /**
    * Copy a buffer to the canvas
    * @param canvas pointer to a canvas object
    * @param to_copy buffer to copy. The color format has to match with the canvas's buffer color format
    * @param w width of the buffer to copy
    * @param h height of the buffer to copy
    * @param x left side of the destination position
    * @param y top side of the destination position
    */
    void copyBuf( const void * to_copy, lv_coord_t w, lv_coord_t h, lv_coord_t x, lv_coord_t y)
    {
        lv_canvas_copy_buf(m_this, to_copy, w, h, x, y);
    }

    /**
    * Multiply a buffer with the canvas
    * @param canvas pointer to a canvas object
    * @param to_copy buffer to copy (multiply). LV_IMG_CF_TRUE_COLOR_ALPHA is not supported
    * @param w width of the buffer to copy
    * @param h height of the buffer to copy
    * @param x left side of the destination position
    * @param y top side of the destination position
    */
    void multiplyBuffer( void * to_copy, lv_coord_t w, lv_coord_t h, lv_coord_t x, lv_coord_t y)
    {
        lv_canvas_mult_buf(m_this,to_copy, w, h, x, y);
    }

    /**
    * Draw circle function of the canvas
    * @param canvas pointer to a canvas object
    * @param x0 x coordinate of the circle
    * @param y0 y coordinate of the circle
    * @param radius radius of the circle
    * @param color border color of the circle
    */
    void drawCircle(lv_coord_t x0, lv_coord_t y0, lv_coord_t radius, lv_color_t color)
    {
        lv_canvas_draw_circle(m_this, x0, y0, radius, color);
    }

    /**
    * Draw line function of the canvas
    * @param canvas pointer to a canvas object
    * @param point1 start point of the line
    * @param point2 end point of the line
    * @param color color of the line
    *
    * NOTE: The lv_canvas_draw_line function originates from https://github.com/jb55/bresenham-line.c.
    */
    void drawLine(lv_point_t point1, lv_point_t point2, lv_color_t color)
    {
        lv_canvas_draw_line(m_this, point1, point2, color);
    }

    /**
    * Draw triangle function of the canvas
    * @param canvas pointer to a canvas object
    * @param points edge points of the triangle
    * @param color line color of the triangle
    */
    void drawTriangle(lv_point_t * points, lv_color_t color)
    {
        lv_canvas_draw_triangle(m_this, points, color);
    }

    /**
    * Draw rectangle function of the canvas
    * @param canvas pointer to a canvas object
    * @param points edge points of the rectangle
    * @param color line color of the rectangle
    */
    void drawRectangle(lv_point_t * points, lv_color_t color)
    {
        lv_canvas_draw_rect(m_this, points, color);
    }

    /**
    * Draw polygon function of the canvas
    * @param canvas pointer to a canvas object
    * @param points edge points of the polygon
    * @param size edge count of the polygon
    * @param color line color of the polygon
    */
    void drawPolygon(lv_point_t * points, size_t size, lv_color_t color)
    {
        lv_canvas_draw_polygon(m_this, points, size, color);
    }

    /**
    * Fill polygon function of the canvas
    * @param canvas pointer to a canvas object
    * @param points edge points of the polygon
    * @param size edge count of the polygon
    * @param boundary_color line color of the polygon
    * @param fill_color fill color of the polygon
    */
    void fillPolygon(lv_point_t * points, size_t size, lv_color_t boundary_color, lv_color_t fill_color)
    {
        lv_canvas_fill_polygon(m_this,  points, size, boundary_color, fill_color);
    }

    /**
    * Boundary fill function of the canvas
    * @param canvas pointer to a canvas object
    * @param x x coordinate of the start position (seed)
    * @param y y coordinate of the start position (seed)
    * @param boundary_color edge/boundary color of the area
    * @param fill_color fill color of the area
    */
    void boundaryFill4(lv_coord_t x, lv_coord_t y, lv_color_t boundary_color, lv_color_t fill_color)
    {
        lv_canvas_boundary_fill4(m_this, x, y, boundary_color, fill_color);
    }

    /**
    * Flood fill function of the canvas
    * @param canvas pointer to a canvas object
    * @param x x coordinate of the start position (seed)
    * @param y y coordinate of the start position (seed)
    * @param fill_color fill color of the area
    * @param bg_color background color of the area
    */
    void floodFill(lv_coord_t x, lv_coord_t y, lv_color_t fill_color, lv_color_t bg_color)
    {
        lv_canvas_flood_fill(m_this, x, y, fill_color, bg_color);
    }

};

#endif // LVCANVAS_H
