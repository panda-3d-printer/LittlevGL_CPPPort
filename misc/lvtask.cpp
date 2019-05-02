#include "lvtask.hpp"


//#ifdef __cplusplus
//extern "C"
//{
//#endif

/**
 * @brief LVTask 任务的代理监护者
 * @param param
 */
    void taskGuardian(void * param)
    {
        LVTask * task = static_cast<LVTask *>(param);

        if(task)
        {
            task->checkAndRun();
        }
    }
//#ifdef __cplusplus
//}
//#endif

LVTask::LVTask(uint32_t period, LVPriority prio)
    :m_priority(prio)
{
    //默认任务停止
    m_this = lv_task_create(taskGuardian, period, LV_TASK_PRIO_OFF, this);
}

void LVTask::checkAndRun()
{
    //检查任务运行的条件

    //由于任务停止只是周期很大
    //这里检查一下防止伪停止任务超过最大延时后运行
    if(isRunning())
    {
        //检查可运行次数
        if(surplusTimes())
        {
            //统计任务运行次数
            ++m_count;
            run();
        }
        else
        {
            stop();
        }
    }
}
