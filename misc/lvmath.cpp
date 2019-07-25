#include "lvmath.h"
#include <cstdio>

static char tempStr[10]; //!<转换用到的零时变量

//整数转字符串
char * itos(int32_t value)
{
    sprintf(tempStr,"%d",value);
    return tempStr;
}

char * ftos(float value , uint32_t precision)
{
    int vv = value*1000;
     if(vv%10 && precision >= 3)
         sprintf(tempStr, "%.3f", value);
     else if(vv%100 && precision >= 2)
             sprintf(tempStr, "%.2f", value);
     else if(vv%1000 && precision >= 1)
             sprintf(tempStr, "%.1f", value);
     else
         sprintf(tempStr, "%.0f", value);
     return tempStr;
}

int32_t stoi(char * str)
{
    int32_t value;
    sscanf(str,"%d",&value);
    return value;
}

float stof(char * str)
{
    float value;
    sscanf(str,"%f",&value);
    return value;
}

char *lvNumberToString(int32_t num, char *buf)
{
    return lv_math_num_to_str(num,buf);
}

int16_t lvTrigoSin(int16_t angle)
{
    return lv_trigo_sin(angle);
}

int32_t lvBezier3(uint32_t t, int32_t u0, int32_t u1, int32_t u2, int32_t u3)
{
    return lv_bezier3(t,u0,u1,u2,u3);
}
