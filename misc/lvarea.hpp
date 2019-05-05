#ifndef LVAREA_H
#define LVAREA_H

#include <lvgl/lv_misc/lv_area.h>
#include <misc/lvmemory.hpp>

using Coord = lv_coord_t;

using LVPoint = lv_point_t;

//**
// * @brief lv point类型
// */
//class LVPoint : public lv_point_t
//{
//public:
//    LVPoint() {}
//    LVPoint(const LVPoint & p) {}
//    LVPoint(const lv_point_t & p) {}
//};


class LVArea : public lv_area_t
{
    LV_MEMAORY_FUNC

private:
    lv_area_t * _this = nullptr;
public:
    LVArea(const LVArea & a) {}

    /**
     * Initialize an area
     * @param area_p pointer to an area
     * @param x1 left coordinate of the area
     * @param y1 top coordinate of the area
     * @param x2 right coordinate of the area
     * @param y2 bottom coordinate of the area
     */
    LVArea(lv_coord_t x1, lv_coord_t y1, lv_coord_t x2, lv_coord_t y2)
    {
        _this = this;
        lv_area_set(_this,x1, y1, x2, y2);
    }

    /**
     * @brief LVArea 装饰
     * @param area
     */
    LVArea(lv_area_t * area)
    {
        _this = area;
    }

    /**
     * Copy an area
     * @param dest pointer to the destination area
     * @param src pointer to the source area
     */
    LVArea(const lv_area_t & src)
    {
        lv_area_copy(_this,&src);
    }

    /**
     * Get the width of an area
     * @return the width of the area (if x1 == x2 -> width = 1)
     */
    inline Coord width()
    {
        return lv_area_get_width(_this);
    }

    /**
     * Get the height of an area
     * @param area_p pointer to an area
     * @return the height of the area (if y1 == y2 -> height = 1)
     */
    inline Coord height()
    {
        return lv_area_get_height(_this);
    }

    /**
     * Set the width of an area
     * @param area_p pointer to an area
     * @param w the new width of the area (w == 1 makes x1 == x2)
     */
    inline void setWidth(Coord w)
    {
        lv_area_set_width(_this,w);
    }

    /**
     * Set the height of an area
     * @param area_p pointer to an area
     * @param h the new height of the area (h == 1 makes y1 == y2)
     */
    inline void setHeight(Coord h)
    {
        lv_area_set_height(_this,h);
    }

    /**
     * Set the position of an area (width and height will be kept)
     * @param area_p pointer to an area
     * @param x the new x coordinate of the area
     * @param y the new y coordinate of the area
     */
    void setPos(lv_coord_t x, lv_coord_t y)
    {
        lv_area_set_pos(_this,x,y);
    }

    /**
     * Return with area of an area (x * y)
     * @param area_p pointer to an area
     * @return size of area
     */
    uint32_t size()
    {
        return lv_area_get_size(_this);
    }

    /**
     * Get the common parts of two areas
     * @param res_p pointer to an area, the result will be stored her
     * @param a1_p pointer to the first area
     * @param a2_p pointer to the second area
     * @return false: the two area has NO common parts, res_p is invalid
     */
    bool intersect(lv_area_t * res_p,const LVArea * a2_p)
    {
        return lv_area_intersect(res_p,_this,a2_p);
    }

    /**
     * Join two areas into a third which involves the other two
     * @param res_p pointer to an area, the result will be stored here
     * @param a1_p pointer to the first area
     * @param a2_p pointer to the second area
     */
    void join(lv_area_t * a_res_p, const lv_area_t * a2_p)
    {
        lv_area_join(a_res_p, _this,a2_p);
    }

    /**
     * Check if a point is on an area
     * @param a_p pointer to an area
     * @param p_p pointer to a point
     * @return false:the point is out of the area
     */
    bool isPointOn(const LVPoint * p_p)
    {
        return lv_area_is_point_on(_this,p_p);
    }

    /**
     * Check if two area has common parts
     * @param a1_p pointer to an area.
     * @param a2_p pointer to an other area
     * @return false: a1_p and a2_p has no common parts
     */
    bool isOn(const lv_area_t * a2_p)
    {
        return lv_area_is_on(_this,a2_p);
    }

    /**
     * Check if an area is fully on an other
     * @param ain_p pointer to an area which could be on aholder_p
     * @param aholder pointer to an area which could involve ain_p
     * @return
     */
    bool isIn(const lv_area_t * aholder_p)
    {
        return lv_area_is_in(_this,aholder_p);
    }

};


#endif // LVAREA_H
