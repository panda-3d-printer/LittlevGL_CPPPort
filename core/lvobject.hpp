#ifndef LVOBJECT_H
#define LVOBJECT_H

#include <stdlib.h>
#include <new>
#include <lvgl/lv_core/lv_obj.h>
#include <misc/lvmemory.h>

//#define MAX_FREENUMBER 0XFFFFFFFF

// 定义LVObject子类的构造函数
#define DEFINE_CONSTRUCTOR(CLASS,FUNC,ANCESTOR) \
 \
explicit CLASS() \
    :ANCESTOR(FUNC(nullptr,nullptr)) \
{} \
 \
explicit CLASS(lv_obj_t * par, const lv_obj_t * copy) \
    :ANCESTOR(FUNC(par,copy)) \
{} \
 \
explicit CLASS(LVObject * parent ,const  LVObject * copy) \
    :ANCESTOR(FUNC( \
          parent?(parent->raw()):nullptr, \
          copy?(copy->raw()):nullptr)) \
{} \
 \
protected: \
explicit CLASS(lv_obj_t * obj) \
    :ANCESTOR(obj) \
{} \
public:

//定义些LVOBJECT派生类应该有的属性和方法
//所有继承与LVObject的类型都要将该宏放置于类声明的最前面
#define LV_OBJECT \
    LV_MEMAORY_FUNC

/**
 * @brief LVGL的基类对象
 * 除了基本的功能外,
 * 增加额外的信号和事件处理功能
 */
class LVObject
{
    LV_OBJECT

    friend lv_res_t lvobjectSignalFunc (struct _lv_obj_t * obj, lv_signal_t sign, void * param);
protected:
    lv_obj_t * m_this = nullptr;  //!< 类所代表的类型
    //bool m_decorate = false; //!< 类实例否只是装饰用,决定析构时是否清理obj对象
    lv_signal_func_t m_defaultSignalFunc = nullptr; //默认的信号函数
    lv_design_func_t m_defaultDesignFunc = nullptr; //默认的设计函数
public:

    /**
     * Create a basic object
     * @param parent pointer to a parent object.
     *                  If NULL then a screen will be created
     * @param copy pointer to a base object, if not NULL then the new object will be copied from it
     * @return pointer to the new object
     */

    explicit LVObject()
        :m_this(lv_obj_create(nullptr,nullptr))
    {
        defaultInit();
    }

    explicit LVObject(lv_obj_t * parent ,const  lv_obj_t * copy)
        :m_this(lv_obj_create(parent,copy))
    {
        defaultInit();
    }

    explicit LVObject(LVObject * parent ,const  LVObject * copy)
        :m_this(lv_obj_create(
              parent?(parent->raw()):nullptr,
              copy?(copy->raw()):nullptr))
    {
        defaultInit();
    }

    /**
     * @brief LVObject 装饰构造函数
     * @param obj 装饰的对象
     * @param decorate true:只做装饰用,对obj没有清理动作
     */
    explicit LVObject(lv_obj_t * obj)
        :m_this(obj)
    {
        defaultInit();
    }

    explicit LVObject(LVObject & raw) = delete;

    virtual ~LVObject();

    void defaultInit();

    //operator lv_obj_t * ()
    //{
    //    return m_this;
    //}

    lv_obj_t * operator->()
    {
        return m_this;
    }

    lv_obj_t * raw()
    {
        return m_this;
    }

    lv_obj_t * raw() const
    {
        return m_this;
    }

    void setRaw(lv_obj_t * obj)
    {
        if(m_this)
        {
            lv_obj_del(m_this);
            m_this = nullptr;
        }
        m_this = obj;
    }

    template<class T>
    T decorate(lv_obj_t * obj)
    {
        return new T(obj,true);
    }

    template<class T>
    static T * realType(lv_obj_t * obj)
    {
        return static_cast<T *>(lv_obj_get_free_ptr(obj));
    }

    /**
     * Delete 'obj' and all of its children
     * @param obj pointer to an object to delete
     * @return LV_RES_INV because the object is deleted
     */
    void delete_()
    {
        lv_obj_del(m_this);
        m_this = nullptr;
    }

    /**
     * @brief 延后清理屏幕
     */
    void deleteLater();

    /**
     * Delete all children of an object
     * @param obj pointer to an object
     */
    void clean()
    {
        lv_obj_clean(m_this);
        //BUG: 实际的LVObject对象并没有清除掉
        //已经实现LVObject对象自动清理
    }

    /**
     * Mark the object as invalid therefore its current position will be redrawn by 'lv_refr_task'
     * @param obj pointer to an object
     */
    void invalidate()
    {
        lv_obj_invalidate(m_this);
    }

    /*=====================
     * Setter functions
     *====================*/

    /*--------------
     * Screen set
     *--------------*/

    /**
     * Load a new screen
     * @param scr pointer to a screen
     */
    void screenLoad()
    {
        lv_scr_load(m_this);
    }

    /*--------------------
     * Parent/children set
     *--------------------*/

    /**
     * Set a new parent for an object. Its relative position will be the same.
     * @param obj pointer to an object. Can't be a screen.
     * @param parent pointer to the new parent object. (Can't be NULL)
     */
    void setParent(lv_obj_t * parent)
    {
        lv_obj_set_parent(m_this,parent);
    }

    void setParent(LVObject * parent)
    {
        lv_obj_set_parent(m_this,parent->m_this);
    }

    /*--------------------
     * Coordinate set
     * ------------------*/

    /**
     * Set relative the position of an object (relative to the parent)
     * @param obj pointer to an object
     * @param x new distance from the left side of the parent
     * @param y new distance from the top of the parent
     */
    void setPos(lv_coord_t x, lv_coord_t y)
    {
        lv_obj_set_pos(m_this,x,y);
    }

    /**
     * Set the x coordinate of a object
     * @param obj pointer to an object
     * @param x new distance from the left side from the parent
     */
    void setX(lv_coord_t x)
    {
        lv_obj_set_x(m_this,x);
    }

    /**
     * Set the y coordinate of a object
     * @param obj pointer to an object
     * @param y new distance from the top of the parent
     */
    void setY(lv_coord_t y)
    {
        lv_obj_set_y(m_this,y);
    }

    /**
     * Set the size of an object
     * @param obj pointer to an object
     * @param w new width
     * @param h new height
     */
    void setSize(lv_coord_t w, lv_coord_t h)
    {
        lv_obj_set_size(m_this,w,h);
    }

    /**
     * Set the width of an object
     * @param obj pointer to an object
     * @param w new width
     */
    void setWidth(lv_coord_t w)
    {
        lv_obj_set_width(m_this,w);
    }

    /**
     * Set the height of an object
     * @param obj pointer to an object
     * @param h new height
     */
    void setHeight(lv_coord_t h)
    {
        lv_obj_set_height(m_this, h);
    }

    /**
     * Align an object to an other object.
     * @param obj pointer to an object to align
     * @param base pointer to an object (if NULL the parent is used). 'obj' will be aligned to it.
     * @param align type of alignment (see 'lv_align_t' enum)
     * @param x_mod x coordinate shift after alignment
     * @param y_mod y coordinate shift after alignment
     */
    void align(const lv_obj_t * base, lv_align_t align, lv_coord_t x_mod = 0, lv_coord_t y_mod = 0);

    void align(const LVObject * base, lv_align_t align, lv_coord_t x_mod = 0, lv_coord_t y_mod = 0);

    void align(lv_align_t align, lv_coord_t x_mod = 0, lv_coord_t y_mod = 0);

    /**
    * Align an object to an other object.
    * @param obj pointer to an object to align
    * @param base pointer to an object (if NULL the parent is used). 'obj' will be aligned to it.
    * @param align type of alignment (see 'lv_align_t' enum)
    * @param x_mod x coordinate shift after alignment
    * @param y_mod y coordinate shift after alignment
    */
    void alignOrigo(const lv_obj_t * base, lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod)
    {
        lv_obj_align_origo(m_this,base, align, x_mod, y_mod);
    }

    void alignOrigo(const LVObject * base, lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod)
    {
        lv_obj_align_origo(m_this,base?(base->raw()):nullptr, align, x_mod, y_mod);
    }

    void alignOrigo(lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod)
    {
        lv_obj_align_origo(m_this,nullptr, align, x_mod, y_mod);
    }

    /**
    * Realign the object based on the last `lv_obj_align` parameters.
    * @param obj pointer to an object
    */
    void realign()
    {
        lv_obj_realign(m_this);
    }

    /**
    * Enable the automatic realign of the object when its size has changed based on the last `lv_obj_align` parameters.
    * @param obj pointer to an object
    * @param en true: enable auto realign; false: disable auto realign
    */
    void setAutoRealign(bool en)
    {
        lv_obj_set_auto_realign(m_this, en);
    }

    /*---------------------
     * Appearance set
     *--------------------*/

    /**
     * Set a new style for an object
     * @param obj pointer to an object
     * @param style_p pointer to the new style
     */
    void setStyle(lv_style_t * style)
    {
        lv_obj_set_style(m_this,style);
    }

    /**
     * Notify an object about its style is modified
     * @param obj pointer to an object
     */
    void refreshStyle()
    {
        lv_obj_refresh_style(m_this);
    }

    /**
     * Notify all object if a style is modified
     * @param style pointer to a style. Only the objects with _this style will be notified
     *               (NULL to notify all objects)
     */
    void reportStyleMod(lv_style_t * style)
    {
        lv_obj_report_style_mod(style);
    }

    /*-----------------
     * Attribute set
     *----------------*/

    /**
     * Hide an object. It won't be visible and clickable.
     * @param obj pointer to an object
     * @param en true: hide the object
     */
    void setHidden(bool en)
    {
        lv_obj_set_hidden(m_this,en);
    }

    /**
     * Enable or disable the clicking of an object
     * @param obj pointer to an object
     * @param en true: make the object clickable
     */
    void setClick(bool en)
    {
        lv_obj_set_click(m_this,en);
    }

    /**
     * Enable to bring _this object to the foreground if it
     * or any of its children is clicked
     * @param obj pointer to an object
     * @param en true: enable the auto top feature
     */
    void setTop(bool en)
    {
        lv_obj_set_top(m_this,en);
    }

    /**
     * Enable the dragging of an object
     * @param obj pointer to an object
     * @param en true: make the object dragable
     */
    void setDrag(bool en)
    {
        lv_obj_set_drag(m_this, en);
    }

    /**
     * Enable the throwing of an object after is is dragged
     * @param obj pointer to an object
     * @param en true: enable the drag throw
     */
    void setDragThrow(bool en)
    {
        lv_obj_set_drag_throw(m_this,en);
    }

    /**
     * Enable to use parent for drag related operations.
     * If trying to drag the object the parent will be moved instead
     * @param obj pointer to an object
     * @param en true: enable the 'drag parent' for the object
     */
    void setDragParent(bool en)
    {
        lv_obj_set_drag_parent(m_this,en);
    }

    /**
     * Set editable parameter Used by groups and keyboard/encoder control.
     * Editable object has something inside to choose (the elements of a list)
     * @param obj pointer to an object
     * @param en true: enable editing
     */
    void setEditable(bool en)
    {
        //lv_obj_set_editable(m_this, en); //TODO: check
    }

    /**
     * Set the opa scale enable parameter (required to set opa_scale with `lv_obj_set_opa_scale()`)
     * @param obj pointer to an object
     * @param en true: opa scaling is enabled for _this object and all children; false: no opa scaling
     */
    void setOpaScaleEnable(bool en)
    {
        lv_obj_set_opa_scale_enable(m_this,en);
    }

    /**
     * Set the opa scale of an object
     * @param obj pointer to an object
     * @param opa_scale a factor to scale down opacity [0..255]
     */
    void setOpaScale(lv_opa_t opa_scale)
    {
        lv_obj_set_opa_scale(m_this, opa_scale);
    }

    /**
     * Set a bit or bits in the protect filed
     * @param obj pointer to an object
     * @param prot 'OR'-ed values from `lv_protect_t`
     */
    void setProtect(uint8_t prot)
    {
        lv_obj_set_protect(m_this,prot);
    }

    /**
     * Clear a bit or bits in the protect filed
     * @param obj pointer to an object
     * @param prot 'OR'-ed values from `lv_protect_t`
     */
    void clearProtect(uint8_t prot)
    {
        lv_obj_clear_protect(m_this,prot);
    }

    /**
     * Set the signal function of an object.
     * Always call the previous signal function in the new.
     * @param obj pointer to an object
     * @param fp the new signal function
     */
    void setSignalFunc(lv_signal_func_t fp)
    {
        lv_obj_set_signal_func(m_this,fp);
    }

    /**
     * Set a new design function for an object
     * @param obj pointer to an object
     * @param fp the new design function
     */
    void setDesignFunc(lv_design_func_t fp)
    {
        lv_obj_set_design_func(m_this,fp);
    }

    /*----------------
     * Other set
     *--------------*/

    /**
     * Allocate a new ext. data for an object
     * @param obj pointer to an object
     * @param ext_size the size of the new ext. data
     * @return pointer to the allocated ext
     */
    void * allocateExtAttr(uint16_t ext_size)
    {
        return lv_obj_allocate_ext_attr(m_this,ext_size);
    }

    /**
     * Send a 'LV_SIGNAL_REFR_EXT_SIZE' signal to the object
     * @param obj pointer to an object
     */
    void refreshExtSize()
    {
        lv_obj_refresh_ext_size(m_this);
    }

#ifdef LV_OBJ_FREE_NUM_TYPE
    /**
     * Set an application specific number for an object.
     * It can help to identify objects in the application.
     * @param obj pointer to an object
     * @param free_num the new free number
     */
    void setFreeNumber(LV_OBJ_FREE_NUM_TYPE free_num)
    {
        lv_obj_set_free_num(m_this,free_num);
    }
#endif

#if LV_OBJ_FREE_PTR != 0
    /**
     * Set an application specific  pointer for an object.
     * It can help to identify objects in the application.
     * @param obj pointer to an object
     * @param free_p the new free pinter
     */
    void setFreePtr(void * free_p)
    {
        lv_obj_set_free_ptr(m_this,free_p);
    }

#endif

#if USE_LV_ANIMATION
    /**
     * Animate an object
     * @param obj pointer to an object to animate
     * @param type type of animation from 'lv_anim_builtin_t'. 'OR' it with ANIM_IN or ANIM_OUT
     * @param time time of animation in milliseconds
     * @param delay delay before the animation in milliseconds
     * @param cb a function to call when the animation is ready
     */
    void animate(lv_anim_builtin_t type, uint16_t time, uint16_t delay, void (*cb) (lv_obj_t *))
    {
        lv_obj_animate(m_this, type, time, delay, cb);
    }
#endif

    /*=======================
     * Getter functions
     *======================*/

    /*------------------
     * Screen get
     *-----------------*/

    /**
     * Return with a pointer to the active screen
     * @return pointer to the active screen object (loaded by 'lv_scr_load()')
     */
    static lv_obj_t * screenActived(void)
    {
        return lv_scr_act();
    }

    /**
     * Return with the top layer. (Same on every screen and it is above the normal screen layer)
     * @return pointer to the top layer object  (transparent screen sized lv_obj)
     */
    static lv_obj_t * layerTop(void)
    {
        return lv_layer_top();
    }

    /**
     * Return with the system layer. (Same on every screen and it is above the all other layers)
     * It is used for example by the cursor
     * @return pointer to the system layer object (transparent screen sized lv_obj)
     */
    static lv_obj_t * layerSys(void)
    {
        return lv_layer_sys();
    }

    /**
     * Return with the screen of an object
     * @param obj pointer to an object
     * @return pointer to a screen (top parent)
     */
    lv_obj_t * getScreen()
    {
        return  lv_obj_get_screen(m_this);
    }

    /*---------------------
     * Parent/children get
     *--------------------*/

    /**
     * Returns with the parent of an object
     * @param obj pointer to an object
     * @return pointer to the parent of  'obj'
     */
    lv_obj_t * getParent() const
    {
        return lv_obj_get_parent(m_this);
    }

    /**
     * Iterate through the children of an object (start from the "youngest, lastly created")
     * @param obj pointer to an object
     * @param child NULL at first call to get the next children
     *                  and the previous return value later
     * @return the child after 'act_child' or NULL if no more child
     */
    lv_obj_t * getChild(const lv_obj_t * child = nullptr)
    {
        return lv_obj_get_child(m_this,child);
    }

    /**
     * Iterate through the children of an object (start from the "oldest", firstly created)
     * @param obj pointer to an object
     * @param child NULL at first call to get the next children
     *                  and the previous return value later
     * @return the child after 'act_child' or NULL if no more child
     */
    lv_obj_t * getChildBack(const lv_obj_t * child = nullptr)
    {
        return lv_obj_get_child_back(m_this,child);
    }

    /**
     * Count the children of an object (only children directly on 'obj')
     * @param obj pointer to an object
     * @return children number of 'obj'
     */
    uint16_t countChildren()
    {
        return lv_obj_count_children(m_this);
    }

    /*---------------------
     * Coordinate get
     *--------------------*/

    /**
     * Copy the coordinates of an object to an area
     * @param obj pointer to an object
     * @param cords_p pointer to an area to store the coordinates
     */
    void getCoords(lv_area_t * cords_p)
    {
        lv_obj_get_coords(m_this,cords_p);
    }

    lv_area_t getCoords()
    {
        lv_area_t cords_p;
        lv_obj_get_coords(m_this,&cords_p);
        return cords_p;
    }

    /**
     * Get the x coordinate of object
     * @param obj pointer to an object
     * @return distance of 'obj' from the left side of its parent
     */
    lv_coord_t getX()
    {
        return lv_obj_get_x(m_this);
    }

    /**
     * Get the y coordinate of object
     * @param obj pointer to an object
     * @return distance of 'obj' from the top of its parent
     */
    lv_coord_t getY()
    {
        return lv_obj_get_y(m_this);
    }

    /**
     * Get the width of an object
     * @param obj pointer to an object
     * @return the width
     */
    lv_coord_t getWidth()
    {
        return lv_obj_get_width(m_this);
    }

    /**
     * Get the height of an object
     * @param obj pointer to an object
     * @return the height
     */
    lv_coord_t getHeight()
    {
        return lv_obj_get_height(m_this);
    }

    /**
     * Get the extended size attribute of an object
     * @param obj pointer to an object
     * @return the extended size attribute
     */
    lv_coord_t getextendedSize()
    {
        return lv_obj_get_ext_size(m_this);
    }

    /*-----------------
     * Appearance get
     *---------------*/

    /**
     * Get the style pointer of an object (if NULL get style of the parent)
     * @param obj pointer to an object
     * @return pointer to a style
     */
    lv_style_t * getStyle()
    {
        return lv_obj_get_style(m_this);
    }

    /**
     * Get the automatic realign property of the object.
     * @param obj pointer to an object
     * @return  true: auto realign is enabled; false: auto realign is disabled
     */
    bool getAutoRealign()
    {
        return lv_obj_get_auto_realign(m_this);
    }

    /*-----------------
     * Attribute get
     *----------------*/

    /**
     * Get the hidden attribute of an object
     * @param obj pointer to an object
     * @return true: the object is hidden
     */
    bool getHidden()
    {
        return lv_obj_get_hidden(m_this);
    }

    /**
     * Get the click enable attribute of an object
     * @param obj pointer to an object
     * @return true: the object is clickable
     */
    bool getClick()
    {
        return lv_obj_get_click(m_this);
    }

    /**
     * Get the top enable attribute of an object
     * @param obj pointer to an object
     * @return true: the auto top feture is enabled
     */
    bool getTop()
    {
        return lv_obj_get_top(m_this);
    }

    /**
     * Get the drag enable attribute of an object
     * @param obj pointer to an object
     * @return true: the object is dragable
     */
    bool getDrag()
    {
        return lv_obj_get_drag(m_this);
    }

    /**
     * Get the drag thow enable attribute of an object
     * @param obj pointer to an object
     * @return true: drag throw is enabled
     */
    bool getDragThrow()
    {
        return lv_obj_get_drag_throw(m_this);
    }

    /**
     * Get the drag parent attribute of an object
     * @param obj pointer to an object
     * @return true: drag parent is enabled
     */
    bool getDragParent()
    {
        return lv_obj_get_drag_parent(m_this);
    }

    /**
     * Get the opa scale parameter of an object
     * @param obj pointer to an object
     * @return opa scale [0..255]
     */
    lv_opa_t getOpaScale()
    {
        return lv_obj_get_opa_scale(m_this);
    }

    /**
     * Get the protect field of an object
     * @param obj pointer to an object
     * @return protect field ('OR'ed values of `lv_protect_t`)
     */
    uint8_t getProtect()
    {
        return lv_obj_get_protect(m_this);
    }

    /**
     * Check at least one bit of a given protect bitfield is set
     * @param obj pointer to an object
     * @param prot protect bits to test ('OR'ed values of `lv_protect_t`)
     * @return false: none of the given bits are set, true: at least one bit is set
     */
    bool isProtected(uint8_t prot)
    {
        return lv_obj_is_protected(m_this,prot);
    }

    /**
     * Get the signal function of an object
     * @param obj pointer to an object
     * @return the signal function
     */
    lv_signal_func_t   getSignalFunc()
    {
        return lv_obj_get_signal_func(m_this);
    }

    /**
     * Get the design function of an object
     * @param obj pointer to an object
     * @return the design function
     */
    lv_design_func_t getDesignFunc()
    {
        return lv_obj_get_design_func(m_this);
    }

    /*------------------
     * Other get
     *-----------------*/

    /**
     * Get the ext pointer
     * @param obj pointer to an object
     * @return the ext pointer but not the dynamic version
     *         Use it as ext->data1, and NOT da(ext)->data1
     */
    void * getExtAttr()
    {
        return lv_obj_get_ext_attr(m_this);
    }

    /**
     * Get object's and its ancestors type. Put their name in `type_buf` starting with the current type.
     * E.g. buf.type[0]="lv_btn", buf.type[1]="lv_cont", buf.type[2]="lv_obj"
     * @param obj pointer to an object which type should be get
     * @param buf pointer to an `lv_obj_type_t` buffer to store the types
     */
    void getType(lv_obj_type_t * buf)
    {
        lv_obj_get_type(m_this,buf);
    }

#ifdef LV_OBJ_FREE_NUM_TYPE
    /**
     * Get the free number
     * @param obj pointer to an object
     * @return the free number
     */
    LV_OBJ_FREE_NUM_TYPE getFreeNumber()
    {
        return lv_obj_get_free_num(m_this);
    }
#endif

#if LV_OBJ_FREE_PTR != 0
    /**
     * Get the free pointer
     * @param obj pointer to an object
     * @return the free pointer
     */
    void * getFreePtr()
    {
        return lv_obj_get_free_ptr(m_this);
    }
#endif

#if USE_LV_GROUP
    /**
     * Get the group of the object
     * @param obj pointer to an object
     * @return the pointer to group of the object
     */
    void * getGroup()
    {
        return lv_obj_get_group(m_this);
    }


    /**
     * Tell whether the ohe object is the focused object of a group or not.
     * @param obj pointer to an object
     * @return true: the object is focused, false: the object is not focused or not in a group
     */
    bool isFocused()
    {
        return lv_obj_is_focused(m_this);
    }

#endif


    //////////////////// 增强功能  //////////////////////////////////

//protected:
    /**
     * @brief 默认的设计函数
     * @param obj
     * @param mask_p
     * @param mode
     * @return
     */
    bool defaultDesign(lv_obj_t * obj, const  lv_area_t * mask_p, lv_design_mode_t mode);

    /**
     * @brief 恢复默认的设计函数
     */
    void resetDesign();

    /**
     * @brief 默认的信号函数
     * @param obj
     * @param sign
     * @param param
     * @return
     */
    lv_res_t defaultSignal(lv_obj_t * obj, lv_signal_t sign, void * param);

    /**
     * @brief 恢复默认的信号函数
     */
    void resetSignal();

};

#endif // LVOBJECT_H
