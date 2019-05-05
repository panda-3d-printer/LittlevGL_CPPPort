#include "lvbutton.hpp"

//按钮的动作代理器
static lv_res_t onButtonActionClicked (struct _lv_obj_t * obj)
{
    LVButton * but = static_cast<LVButton*>(obj->free_ptr);
    if(but)
    {
        but->onClicked(obj);
    }
    else
    {
        LV_LOG_WARN("_lv_obj_t * obj can not turn to type LVButton !!");
        return LV_RES_OK;
    }
}

static lv_res_t onButtonActionPressed (struct _lv_obj_t * obj)
{
    LVButton * but = static_cast<LVButton*>(obj->free_ptr);
    if(but)
    {
        but->onPressed(obj);
    }
    else
    {
        LV_LOG_WARN("_lv_obj_t * obj can not turn to type LVButton !!");
        return LV_RES_OK;
    }
}

static lv_res_t onButtonActionLongPressed (struct _lv_obj_t * obj)
{
    LVButton * but = static_cast<LVButton*>(obj->free_ptr);
    if(but)
    {
        but->onLongPressed(obj);
    }
    else
    {
        LV_LOG_WARN("_lv_obj_t * obj can not turn to type LVButton !!");
        return LV_RES_OK;
    }
}

static lv_res_t onButtonActionLongPressRepeat(struct _lv_obj_t * obj)
{
    LVButton * but = static_cast<LVButton*>(obj->free_ptr);
    if(but)
    {
        but->onLongPressRepeat(obj);
    }
    else
    {
        LV_LOG_WARN("_lv_obj_t * obj can not turn to type LVButton !!");
        return LV_RES_OK;
    }
}


void LVButton::setAction(LVButtonAction action,lv_btn_action_t type)
{
    switch (type)
    {
    case LV_BTN_ACTION_CLICK:          m_clickAction = action           ; lv_btn_set_action(m_this, type, onButtonActionClicked); break;
    case LV_BTN_ACTION_PR:             m_pressAction = action           ; lv_btn_set_action(m_this, type, onButtonActionPressed); break;
    case LV_BTN_ACTION_LONG_PR:        m_longPressAction = action       ; lv_btn_set_action(m_this, type, onButtonActionLongPressed); break;
    case LV_BTN_ACTION_LONG_PR_REPEAT: m_longPressRepeatAction = action ; lv_btn_set_action(m_this, type, onButtonActionLongPressRepeat); break;
    default:
        break;
    }
}

lv_res_t LVButton::onClicked(_lv_obj_t *obj)
{
    if(m_clickAction != nullptr)
        return m_clickAction(obj);
    else
    {
        LV_LOG_WARN("Please Implement this Function Or set Action !!")
                return LV_RES_OK;
    }
}

lv_res_t LVButton::onPressed(_lv_obj_t *obj)
{
    if(m_pressAction != nullptr)
        return m_pressAction(obj);
    else
    {
        LV_LOG_WARN("Please Implement this Function Or set Action !!")
                return LV_RES_OK;
    }
}

lv_res_t LVButton::onLongPressed(_lv_obj_t *obj)
{
    if(m_longPressAction != nullptr)
        return m_longPressAction(obj);
    else
    {
        LV_LOG_WARN("Please Implement this Function Or set Action !!")
                return LV_RES_OK;
    }
}

lv_res_t LVButton::onLongPressRepeat(_lv_obj_t *obj)
{
    if(m_longPressRepeatAction != nullptr)
        return m_longPressRepeatAction(obj);
    else
    {
        LV_LOG_WARN("Please Implement this Function Or set Action !!")
                return LV_RES_OK;
    }
}

void LVButton::setChecked(bool value)
{
    if(getToggle())
    {
        setState(value?LV_BTN_STATE_TGL_REL:LV_BTN_STATE_REL);
    }
}

bool LVButton::checked()
{
    if(getToggle())
    {
        return getState() == LV_BTN_STATE_TGL_REL;
    }
    else
    {
        return false;
    }
}
