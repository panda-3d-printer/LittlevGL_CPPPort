#include "lvlabel.hpp"

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
