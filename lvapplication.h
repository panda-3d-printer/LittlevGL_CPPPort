#ifndef LVAPPLICATION_H
#define LVAPPLICATION_H

/**
 * @brief LVGL搴旂敤绋嬪簭
 * 涓昏鐩殑鏄垵濮嬪寲lvgl
 *
 * LVApplication app;
 *
 *
 *
 * app.exec();
 *
 */
class LVApplication
{
private:
    static bool is_lv_inited; //!< 鏍囪瘑lvgl搴撴槸鍚﹀垵濮嬪寲
    static bool is_lv_halinited; //!< 鏍囪瘑lvgl_hal鏄惁鍒濆鍖�
public:
    LVApplication(void (*hal_init)(void));

    //[[noreturn]]
    void exec() ;
};

#endif // LVAPPLICATION_H
