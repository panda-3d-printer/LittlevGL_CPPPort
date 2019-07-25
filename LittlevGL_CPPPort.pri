INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/lv_examples

DEFINES += LV_CPP_PORT

DEFINES += LV_CONF_INCLUDE_SIMPLE

INCLUDEPATH += $$PWD/core \
    $$PWD/objx \
    $$PWD/misc \
    $$PWD/themes

HEADERS += \
    $$PWD/lvapplication.h \
    $$PWD/misc/lvmath.h \
    $$PWD/misc/lvmemory.hpp \
    $$PWD/themes/lvtheme.h \
    $$PWD/lvgl \
    $$PWD/core/lvgroup.hpp \
    $$PWD/core/lvinputdevices.hpp \
    $$PWD/core/lvlang.hpp \
    $$PWD/core/lvobject.hpp \
    $$PWD/core/lvsignal.hpp \
    $$PWD/core/lvsignalSlot.hpp \
    $$PWD/core/lvslot.hpp \
    $$PWD/core/lvstyle.hpp \
    $$PWD/misc/lvanimation.hpp \
    $$PWD/misc/lvarea.hpp \
    $$PWD/misc/lvcolor.hpp \
    $$PWD/misc/lvlinklist.hpp \
    $$PWD/misc/lvtask.hpp \
    $$PWD/objx/lvbutton.hpp \
    $$PWD/objx/lvimage.hpp \
    $$PWD/objx/lvarc.hpp \
    $$PWD/objx/lvbar.hpp \
    $$PWD/objx/lvwindow.hpp \
    $$PWD/objx/lvtileview.hpp \
    $$PWD/objx/lvtextarea.hpp \
    $$PWD/objx/lvtabview.hpp \
    $$PWD/objx/lvtable.hpp \
    $$PWD/objx/lvswitch.hpp \
    $$PWD/objx/lvspinbox.hpp \
    $$PWD/objx/lvslider.hpp \
    $$PWD/objx/lvroller.hpp \
    $$PWD/objx/lvpreloader.hpp \
    $$PWD/objx/lvpage.hpp \
    $$PWD/objx/lvmessagebox.hpp \
    $$PWD/objx/lvlist.hpp \
    $$PWD/objx/lvlinemeter.hpp \
    $$PWD/objx/lvline.hpp \
    $$PWD/objx/lvled.hpp \
    $$PWD/objx/lvlabel.hpp \
    $$PWD/objx/lvkeyboard.hpp \
    $$PWD/objx/lvgauge.hpp \
    $$PWD/objx/lvimagebutton.hpp \
    $$PWD/objx/lvdropdownlist.hpp \
    $$PWD/objx/lvcontainer.hpp \
    $$PWD/objx/lvcheckbox.hpp \
    $$PWD/objx/lvchart.hpp \
    $$PWD/objx/lvcanvas.hpp \
    $$PWD/objx/lvcalendar.hpp \
    $$PWD/objx/lvbuttonmatrix.hpp

SOURCES += \
    $$PWD/lvapplication.cpp \
    $$PWD/fonts/LVFontChinese.c \
    $$PWD/misc/lvmath.cpp \
    $$PWD/misc/lvtask.cpp \
    $$PWD/core/lvobject.cpp \
    $$PWD/core/lvsignalslot.cpp \
    $$PWD/objx/lvbutton.cpp \
    $$PWD/objx/lvlabel.cpp \
    $$PWD/misc/lvmemory.cpp

#################### examples ###############################################################

#HEADERS += \
#    $$PWD/lv_examples/lv_tutorial/1_hello_world/lv_tutorial_hello_world.h \
#    $$PWD/lv_examples/lv_tutorial/5_antialiasing/lv_tutorial_antialiasing.h \
#    $$PWD/lv_examples/lv_tutorial/6_images/lv_tutorial_images.h \
#    $$PWD/lv_examples/lv_tutorial/7_fonts/lv_tutorial_fonts.h \
#    $$PWD/lv_examples/lv_tutorial/8_animations/lv_tutorial_animations.h \
#    $$PWD/lv_examples/lv_tutorial/9_responsive/lv_tutorial_responsive.h \
#    $$PWD/lv_examples/lv_tutorial/10_keyboard/lv_tutorial_keyboard.h \
#    $$PWD/lv_examples/lv_tests/lv_test_group/lv_test_group.h \
#    $$PWD/lv_examples/lv_tutorial/2_objects/lv_tutorial_objects.h \
#    $$PWD/lv_examples/lv_tutorial/3_styles/lv_tutorial_styles.h \
#    $$PWD/lv_examples/lv_tutorial/4_themes/lv_tutorial_themes.h \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_arc/lv_test_arc.h \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_bar/lv_test_bar.h \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_btn/lv_test_btn.h \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_btnm/lv_test_btnm.h \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_cb/lv_test_cb.h \
#    $$PWD/lv_examples/lv_apps/benchmark/benchmark.h \
#    $$PWD/lv_examples/lv_apps/demo/demo.h \
#    $$PWD/lv_examples/lv_apps/sysmon/sysmon.h \
#    $$PWD/lv_examples/lv_apps/terminal/terminal.h \
#    $$PWD/lv_examples/lv_apps/tpcal/tpcal.h \
#    $$PWD/lv_examples/lv_tests/lv_test_theme/lv_test_theme_1.h \
#    $$PWD/lv_examples/lv_tests/lv_test_theme/lv_test_theme_2.h \

#SOURCES += \
#    $$PWD/lv_examples/lv_tutorial/1_hello_world/lv_tutorial_hello_world.cpp \
#    $$PWD/lv_examples/lv_tutorial/2_objects/lv_tutorial_objects.cpp \
#    $$PWD/lv_examples/lv_tutorial/3_styles/lv_tutorial_styles.cpp \
#    $$PWD/lv_examples/lv_tutorial/4_themes/lv_tutorial_themes.cpp \
#    $$PWD/lv_examples/lv_tutorial/5_antialiasing/apple_icon_alpha.c \
#    $$PWD/lv_examples/lv_tutorial/5_antialiasing/apple_icon_chroma.c \
#    $$PWD/lv_examples/lv_tutorial/5_antialiasing/lv_tutorial_antialiasing.cpp \
#    $$PWD/lv_examples/lv_tutorial/6_images/red_flower.c \
#    $$PWD/lv_examples/lv_tutorial/6_images/lv_tutorial_images.cpp \
#    $$PWD/lv_examples/lv_tutorial/7_fonts/arial_ascii_20.c \
#    $$PWD/lv_examples/lv_tutorial/7_fonts/arial_cyrillic_20.c \
#    $$PWD/lv_examples/lv_tutorial/7_fonts/arial_math_20.c \
#    $$PWD/lv_examples/lv_tutorial/7_fonts/lv_tutorial_fonts.cpp \
#    $$PWD/lv_examples/lv_tutorial/8_animations/lv_tutorial_animations.cpp \
#    $$PWD/lv_examples/lv_tutorial/9_responsive/lv_tutorial_responsive.cpp \
#    $$PWD/lv_examples/lv_tutorial/10_keyboard/lv_tutorial_keyboard.cpp \
#    $$PWD/lv_examples/lv_tests/lv_test_group/lv_test_group.cpp \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_arc/lv_test_arc.cpp \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_bar/lv_test_bar.cpp \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_btn/lv_test_btn.cpp \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_btnm/lv_test_btnm.cpp \
#    $$PWD/lv_examples/lv_tests/lv_test_objx/lv_test_cb/lv_test_cb.cpp \
#    $$PWD/lv_examples/lv_apps/benchmark/benchmark.cpp \
#    $$PWD/lv_examples/lv_apps/benchmark/benchmark_bg.c \
#    $$PWD/lv_examples/lv_apps/demo/demo.cpp \
#    $$PWD/lv_examples/lv_apps/demo/img_bubble_pattern.c \
#    $$PWD/lv_examples/lv_apps/sysmon/sysmon.cpp \
#    $$PWD/lv_examples/lv_apps/terminal/terminal.cpp \
#    $$PWD/lv_examples/lv_apps/tpcal/tpcal.cpp \
#    $$PWD/lv_examples/lv_tests/lv_test_theme/lv_test_theme_1.cpp \
#    $$PWD/lv_examples/lv_tests/lv_test_theme/lv_test_theme_2.cpp \

#DISTFILES += \
#    $$PWD/lv_examples/lv_tutorial/5_antialiasing/apple.png \
#    $$PWD/lv_examples/lv_tutorial/5_antialiasing/apple_chroma.png \
#    $$PWD/lv_examples/lv_tutorial/6_images/red_flower.png
