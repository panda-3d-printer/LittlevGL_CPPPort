#ifndef LVAPPLICATION_H
#define LVAPPLICATION_H

/**
 * @brief LVGL
 *
 * LVApplication app;
 *
 * user code
 *
 * app.exec();
 *
 */
class LVApplication
{
private:
    static bool is_lv_inited; //!<
    static bool is_lv_halinited; //!<
public:
    LVApplication(void (*hal_init)(void));

    //[[noreturn]]
    void exec() ;
};

#endif // LVAPPLICATION_H
