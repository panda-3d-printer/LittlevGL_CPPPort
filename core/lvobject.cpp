
#include "lvobject.hpp"
#include <lvtask.hpp>

lv_res_t lvobjectSignalFunc (struct _lv_obj_t * obj, lv_signal_t sign, void * param)
{

    LVObject * lvobject = static_cast<LVObject *>(obj->free_ptr);

    if(lvobject)
    {
        return lvobject->defaultSignal(obj,sign,param);
    }

    return LV_RES_OK;
}

LVObject::~LVObject()
{
    //NOTE: BUG记录
    //由于析构函数会先析构派生类,如果替换过默认的函数
    //最后回调时会造成非法野指针,因此恢复默认的回调函数
    //会造成 LV_SIGNAL_CLEANUP 信号无法处理

    if(m_this)
    {
        resetDesign();
        resetSignal();

        lv_obj_del(m_this);
    }

    LV_LOG_INFO("LVObject Delete");

}

void LVObject::defaultInit()
{
    //defaut save this in free ptr for recover class type
    //free ptr can be override for other using
    //NOTE: lv_tileview will override free_ptr
    setFreePtr(this);
    //setFreeNumber(MAX_FREENUMBER);

    m_defaultDesignFunc = getDesignFunc();
    m_defaultSignalFunc = getSignalFunc();

    //替换默认的信号函数
    setSignalFunc(::lvobjectSignalFunc);

    LV_LOG_INFO("LVObject Create");
}

void LVObject::deleteLater()
{
    //延时清理对象
    //只堆对对象有效
    LVTask::once(1,[this]()
    {
        delete this;
    });
}

void LVObject::align(const lv_obj_t *base, lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod)
{
    lv_obj_align(m_this,base,align,x_mod,y_mod);
}

void LVObject::align(const LVObject *base, lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod)
{
    lv_obj_align(m_this,base?(base->raw()):nullptr,align,x_mod,y_mod);
}

void LVObject::align(lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod)
{
    lv_obj_align(m_this,nullptr,align,x_mod,y_mod);
}

bool LVObject::defaultDesign(lv_obj_t *obj, const lv_area_t *mask_p, lv_design_mode_t mode)
{
    return m_defaultDesignFunc(obj,mask_p,mode);
}

void LVObject::resetDesign()
{
    setDesignFunc(m_defaultDesignFunc);
}

lv_res_t LVObject::defaultSignal(lv_obj_t *obj, lv_signal_t sign, void *param)
{
    //阻止LV_SIGNAL_CLEANUP信号的传递
    if(sign == LV_SIGNAL_CLEANUP)
    {
        //恢复默认的信号函数
        //对象在被删除时,将m_this重置
        resetSignal();
        m_this = nullptr;

        lv_res_t ret = m_defaultSignalFunc(obj,sign,param);

        delete this;

        return ret;
    }
    return m_defaultSignalFunc(obj,sign,param);
}

void LVObject::resetSignal()
{
    setSignalFunc(m_defaultSignalFunc);
}
