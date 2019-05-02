#ifndef LVIMAGE_H
#define LVIMAGE_H

#include <core/lvobject.hpp>
#include <lvgl/lv_objx/lv_img.h>

class LVImage : public LVObject
{
    LV_OBJECT
public:
    /**********************
    * GLOBAL PROTOTYPES
    **********************/

    /**
    * Create an image objects
    * @param par pointer to an object, it will be the parent of the new button
    * @param copy pointer to a image object, if not NULL then the new object will be copied from it
    * @return pointer to the created image
    */

    DEFINE_CONSTRUCTOR(LVImage,lv_img_create,LVObject)


    /*=====================
    * Setter functions
    *====================*/

    /**
    * Set the pixel map to display by the image
    * @param img pointer to an image object
    * @param data the image data
    */
    void setSrc(const void * src_img)
    {
        lv_img_set_src(m_this,src_img);
    }

    /**
    * Obsolete since v5.1. Just for compatibility with v5.0. Will be removed in v6.0.
    * Use 'lv_img_set_src()' instead.
    * @param img -
    * @param fn -
    */
    static inline void setFile(lv_obj_t * img, const char * fn)
    {
        (void) img;
        (void) fn;
    }

    /**
    * Enable the auto size feature.
    * If enabled the object size will be same as the picture size.
    * @param img pointer to an image
    * @param autosize_en true: auto size enable, false: auto size disable
    */
    void setAutoSize(bool autosize_en)
    {
        lv_img_set_auto_size(m_this, autosize_en);
    }

    /**
    * Set the style of an image
    * @param img pointer to an image object
    * @param style pointer to a style
    */
    //void setStyle(lv_obj_t *img, lv_style_t *style)

    /**
    * Obsolete since v5.1. Just for compatibility with v5.0. Will be removed in v6.0
    * @param img -
    * @param upscale -
    */
    static inline void setUpscale(lv_obj_t * img, bool upcale)
    {
        (void) img;
        (void) upcale;
    }

    /*=====================
    * Getter functions
    *====================*/

    /**
    * Get the source of the image
    * @param img pointer to an image object
    * @return the image source (symbol, file name or C array)
    */
    const void * getSrc()
    {
        return lv_img_get_src(m_this);
    }

    /**
    * Get the name of the file set for an image
    * @param img pointer to an image
    * @return file name
    */
    const char * getFileName()
    {
        return lv_img_get_file_name(m_this);
    }

    /**
    * Get the auto size enable attribute
    * @param img pointer to an image
    * @return true: auto size is enabled, false: auto size is disabled
    */
    bool getAutoSize()
    {
        return  lv_img_get_auto_size(m_this);
    }

    /**
    * Get the style of an image object
    * @param img pointer to an image object
    * @return pointer to the image's style
    */
    //lv_style_t* getStyle(const lv_obj_t *img)

    /**
    * Obsolete since v5.1. Just for compatibility with v5.0. Will be removed in v6.0
    * @param img -
    * @return false
    */
    bool getUpscale()
    {
        return false;
    }
};

#endif // LVIMAGE_H
