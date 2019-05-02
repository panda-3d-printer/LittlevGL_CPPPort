#ifndef LVMEMORY_H
#define LVMEMORY_H

//#if LV_MEM_CUSTOM == 0

#include <stdlib.h>
#include <new>
#include <lvgl/lv_misc/lv_mem.h>

using namespace std;

//LVGL 内存管理实现
//自定义new 和 delete函数

#define LV_MEMAORY_FUNC \
public: \
    static void* operator new(size_t sz) \
    { \
        return lv_mem_alloc(sz); \
    } \
    static void operator delete(void* p) \
    { \
        lv_mem_free(p); \
    } \
    static void *operator new[](size_t sz) \
    { \
        return lv_mem_alloc(sz); \
    } \
    static void operator delete[](void *p) \
    { \
        lv_mem_free(p); \
    } \
private:

//#define LV_MEMAORY_FUNC

//#endif

#endif // LVMEMORY_H
