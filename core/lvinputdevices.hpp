#ifndef LVINPUTDEVICES_H
#define LVINPUTDEVICES_H

#include <lvgl/lv_core/lv_indev.h>
#include <misc/lvmemory.h>

/**
 * @brief 输入设备
 */
class LVInputDevices
{
    LV_MEMAORY_FUNC
private:
    lv_indev_t * m_this = nullptr;
public:
    LVInputDevices(){}
};

#endif // LVINPUTDEVICES_H
