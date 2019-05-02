#include "lvapplication.h"
#include <lvgl/lv_core/lv_obj.h>
#include <lvgl/lv_misc/lv_task.h>
#include <stdlib.h>
#include <unistd.h>

bool LVApplication::is_lv_inited = false;
bool LVApplication::is_lv_halinited = false;

/**
 * @brief LVApplication::LVApplication
 * @param hal_init 硬件hal层初始化函数,需要用户实现
 */
LVApplication::LVApplication(void (*hal_init)(void))
{
    //初始化lvgl库
    if(!is_lv_inited)
    {
        lv_init();
    }
    //初始化hal层
    if(!is_lv_halinited)
    {
        hal_init();
    }
}

void LVApplication::exec()
{
    for (;;)
    {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();

        usleep(1000);       /*Just to let the system breath*/

        #ifdef SDL_APPLE
                SDL_Event event;

                while(SDL_PollEvent(&event)) {
        #if USE_MOUSE != 0
                    mouse_handler(&event);
        #endif

        #if USE_KEYBOARD
                    keyboard_handler(&event);
        #endif

        #if USE_ENCODER != 0
                    encoder_handler(&event);
        #endif
                }
        #endif
    }
}
