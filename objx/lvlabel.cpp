#include "lvlabel.hpp"
#include "../misc/lvmath.h"

void LVLabel::setText(const char *text)
{
    lv_label_set_text(m_this,text);
    setTextID(NONETEXT);//表示无语言文本设置
}

void LVLabel::setText(const char *text, uint16_t textId)
{
    lv_label_set_text(m_this,text);
    setTextID(textId);
}

void LVLabel::setValue(int32_t value)
{
    setText(itos(value));
}

void LVLabel::setValue(float value)
{
    setText(itos(value));
}

int32_t LVLabel::getIntValue()
{
    return stoi(getText());
}

float LVLabel::getFloatValue()
{
    return stof(getText());
}
