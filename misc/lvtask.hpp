#ifndef LVTASK_H
#define LVTASK_H

#include <lvgl/lv_misc/lv_task.h>
#include <functional>
#include <misc/lvmemory.h>


/**
 * LVTask 可以接受的任务函数类型
 */
using LVTaskFunc = std::function<void(void)>;

using LVPriority = lv_task_prio_t;

/**
 * @brief LVGL中的任务类
 * 增加了以下功能:
 * 任务启停控制
 * 任务次数控制
 * 任务停止后自动清除
 * 快捷单次运行任务
 */
class LVTask
{
    LV_MEMAORY_FUNC
    //friend void taskGuardian(void * param);
protected:

    lv_task_t * m_this = nullptr; //!<类所代表的数据类型

    LVPriority m_priority; //!< 任务优先级
    int m_times = -1; //!< 任务需要运行的次数 0~0xEFFFFFFF ; -1 表示无次数限制
    uint32_t m_count = 0; //!< 记录任务的运行次数
    bool m_deleteAfterStop = false; //!< 任务停止时清除任务
    LVTaskFunc m_taskFunc;
public:

    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Init the lv_task module
    */
    static void init(void)
    {
        lv_task_init();
    }

    /**
    * Call it  periodically to handle lv_tasks.
    */
    //static LV_ATTRIBUTE_TASK_HANDLER void handler(void)
    //{
    //    lv_task_handler();
    //}

    /**
    * Create a new lv_task
    * 抛弃的函数, 兼容旧的API , 不建议使用
    * @param task a function which is the task itself
    * @param period call period in ms unit
    * @param prio priority of the task (LV_TASK_PRIO_OFF means the task is stopped)
    * @param param free parameter
    * @return pointer to the new task
    */
    LVTask(void (*task) (void *), uint32_t period, LVPriority prio = LV_TASK_PRIO_LOWEST, void * param = nullptr)
        :m_priority(prio)
    {
        //默认任务是停止的
        m_this = lv_task_create(task,period, LV_TASK_PRIO_OFF, param);
    }

    /**
    * Create a new lv_task
    * 默认任务创建后不会运行,直到调用了start().
    * @param period call period in ms unit
    * @param prio priority of the task (LV_TASK_PRIO_OFF means the task is stopped)
    */
    LVTask(uint32_t period, LVPriority prio = LV_TASK_PRIO_LOWEST);

    virtual ~LVTask()
    {
        if(m_this)
            delete_();
    }

    lv_task_t * operator ->()
    {
        return m_this;
    }

    //operator lv_task_t * ()
    //{
    //    return m_this;
    //}

    /**
    * Delete a lv_task
    * 比较危险的函数,建议如果要停止的话就用stop, 清理任务用析构函数
    * @param lv_task_p pointer to task created by lv_task_p
    */
    void delete_()
    {
        lv_task_del(m_this);
        m_this = nullptr;
    }

    /**
    * Set new priority for a lv_task
    * @param lv_task_p pointer to a lv_task
    * @param prio the new priority
    */
    void setpriority(LVPriority prio)
    {
        if(m_priority != prio)
        {
            m_priority = prio;

            if(isRunning()) //period != s_infinitePeriod
            {
                lv_task_set_prio(m_this, prio);
            }
        }
    }


    /**
    * Set new period for a lv_task
    * @param lv_task_p pointer to a lv_task
    * @param period the new period
    */
    void setPeriod(uint32_t period)
    {
        lv_task_set_period(m_this, period);
    }

    /**
    * Make a lv_task ready. It will not wait its period.
    * @param lv_task_p pointer to a lv_task.
    */
    void ready()
    {
        lv_task_ready(m_this);
    }


    /**
    * Delete the lv_task after one call
    * 比较危险的函数,建议如果只要执行一次任务的话,用start函数代替
    * @param lv_task_p pointer to a lv_task.
    */
    void once()
    {
        lv_task_once(m_this);
    }

    /**
    * Reset a lv_task.
    * It will be called the previously set period milliseconds later.
    * @param lv_task_p pointer to a lv_task.
    */
    void reset()
    {
        lv_task_reset(m_this);
    }

    /**
    * Enable or disable the whole  lv_task handling
    * @param en: true: lv_task handling is running, false: lv_task handling is suspended
    */
    static void enable(bool en)
    {
        lv_task_enable(en);
    }

    /**
    * Get idle percentage
    * @return the lv_task idle in percentage
    */
    static uint8_t getIdle()
    {
        return lv_task_get_idle();
    }

    /**********************
    *      MACROS
    **********************/


    //////////////////// 增强功能  //////////////////////////////////

    /**
     * @brief 开始任务
     */
    void start()
    {
        lv_task_set_prio(m_this, m_priority);
    }

    void start(LVPriority prio)
    {
        setpriority(prio);
        lv_task_set_prio(m_this, m_priority);
    }

    /**
     * @brief 开始任务
     * @param period 指定任务周期
     * @param times 指定任务次数
     */
    void start(uint32_t period,int times = -1)
    {
        setPeriod(period);
        setTimes(times);
        start();
    }

    /**
     * @brief 开始任务, 同时执行一遍任务
     */
    void startAndRun()
    {
        start();
        //不等待直接执行一遍任务
        checkAndRun();
    }

    /**
     * @brief 停止任务
     *
     */
    void stop()
    {
        lv_task_set_prio(m_this, LV_TASK_PRIO_OFF);
        resetCount();

        if(isDeleteAfterStop())
            delete this;
    }

    void restart()
    {
        if(!isDeleteAfterStop())
        {
           stop();
           start();
        }
        else
        {
           //FIXME:对于运行后清除的任务,无法再次启动
           stop();
        }
    }

    bool isRunning()
    {
        return  m_this->prio != LV_TASK_PRIO_OFF;
    }

    /**
     * @brief 任务的优先级
     * @return
     */
    LVPriority priority(){ return m_priority; }

    /**
     * @brief 任务运行的总次数
     * @return
     */
    int times(){ return m_times;  }

    /**
     * @brief 设置任务运行次数
     * 更改运行次数后,之前的运行次数统计需要手动清除
     * @param n 0~0xEFFFFFFF ; -1 表示无次数限制
     * @return
     */
    int setTimes(int n = -1){ m_times = n; }

    /**
     * @brief 任务的剩余运行次数
     * @return
     */
    int surplusTimes(){ return m_times == -1 ? -1: m_times - m_count; }

    /**
     * @brief 任务的从上一次运行后执行的次数
     * @return
     */
    uint32_t count(){ return m_count; }

    /**
     * @brief 重置任务计数
     */
    void resetCount(){ m_count = 0; }

    /**
     * @brief 是否停止后就清除任务
     * @return
     */
    bool isDeleteAfterStop(){ return  m_deleteAfterStop; }

    /**
     * @brief 设置停止后就清除任务
     * @param value
     */
    void setDeleteAfterStop(bool value){ m_deleteAfterStop = value; }

    /**
     * @brief 快捷方便的函数,执行一次任务函数
     * @param period 时间间隔
     * @param func 任务函数
     */
    static void once(uint32_t period ,LVTaskFunc func)
    {
        LVTask * onceTask = new LVTask(period);
        onceTask->setTaskFunc(func);
        onceTask->setDeleteAfterStop(true);
        onceTask->start(period,1);
    }

    /**
     * @brief 设置任务函数
     * @param func
     */
    void setTaskFunc(LVTaskFunc func)
    {
        m_taskFunc = func;
    }

    /**
     * @brief 当前任务的函数
     * @return
     */
    LVTaskFunc taskFunc()
    {
        return m_taskFunc;
    }

    /**
     * @brief 任务运行前的条件检查
     *
     * //NOTE: 应该将该函数保护起来的
     */
    virtual void checkAndRun();

protected:

    /**
     * @brief 具体的任务函数,需要子类去实现
     * 一定注意,函数内不能存在阻塞
     */
    virtual void run()
    {
        if(m_taskFunc)
            m_taskFunc();
    }

};

#endif // LVTASK_H
