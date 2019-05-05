#ifndef LVLINKLIST_H
#define LVLINKLIST_H

#include <lvgl/lv_misc/lv_ll.h>
#include <misc/lvmemory.hpp>

using LVLLNode = lv_ll_node_t;


/**
 * @brief 一个简单的指针封装及类型转换类,方便链表节点与原始数据之间的转换
 *
 * 例子:1 做结构对象用
 * struct Mate {
 * int i;
 * bool b;
 * float f;
 * }
 *
 * LVLLNodeMate<Mate> matePtr(note);
 * matePtr->i = 7
 *
 * 例子:2 做指针对象用
 * LVLLNodeMate<Mate> * matePtr = xxxptr;
 * (* matePtr)->i = 7;
 */
template< class T >
class LVLLNodeMate
{
    LV_MEMAORY_FUNC

public:
    T * m_mate;
    LVLLNodeMate(LVLLNode * note)
        :m_mate((T *)note)
    {}

    T * operator ->()
    {
        return m_mate;
    }

    LVLLNode * note() const
    {
        return (LVLLNode *)m_mate;
    }

    const T * mate() const
    {
        return m_mate;
    }

    T * &mate()
    {
        return m_mate;
    }
};



/**
 * @brief a linked list class
 */
class LVLinkList : public lv_ll_t
{
    LV_MEMAORY_FUNC

private:
    lv_ll_t * _this = nullptr;
public:
    /**
     * @brief Initialize linked list
     * @param node_size the size of 1 node in bytes
     */
    LVLinkList(uint32_t node_size)
    {
        _this = this;
        lv_ll_init(_this,node_size);
    }

    /**
     * @brief decoration linked list
     * @param ll_p 已经存在的链表
     */
    LVLinkList(lv_ll_t * ll_p)
    {
        _this = ll_p;
    }

    ~LVLinkList()
    {
        clear();
    }

//    LVLinkList(const LVLinkList & ll_p)
//        :LVLinkList(ll_p.n_size)
//    {
//        *_this = ll_p;
//    }

//    LVLinkList(const LVLinkList && ll_p)
//        :
//    {
//        _this = this;
//    }

//    ~LVLinkList()
//    {
//        if(_this == this)

//    }

    /**
     * Add a new head to linked list
     * @return pointer to the new head
     */
    LVLLNode * insertHead()
    {
        return (LVLLNode *)lv_ll_ins_head(_this);
    }

    /**
     * Insert a new node in front of the n_act node
     * @param n_act pointer a node
     * @return pointer to the new head
     */
    LVLLNode * insertPrev(LVLLNode * n_act)
    {
        return (LVLLNode *)lv_ll_ins_prev(_this ,n_act);
    }

    /**
     * Add a new tail to a linked list
     * @return pointer to the new tail
     */
    LVLLNode * insertTail()
    {
        return (LVLLNode *)lv_ll_ins_tail(_this);
    }

    /**
     * Remove the node 'node_p' from linked list.
     * It does not free the the memory of node.
     * @param node_p pointer to node in linked list
     */
    void remove(LVLLNode * node_p)
    {
        lv_ll_rem(_this,node_p);
    }

    /**
     * Remove and free all elements from a linked list. The list remain valid but become empty.
     * @param ll_p pointer to linked list
     */
    void clear()
    {
        lv_ll_clear(_this);
    }

    /**
     * Move a node to a new linked list
     * @param ll_new_p pointer to the new linked list
     * @param node pointer to a node
     */
    void changeList(LVLinkList * ll_new_p, LVLLNode * node)
    {
        lv_ll_chg_list(_this,ll_new_p, node);
    }

    /**
     * Return with head node of the linked list
     * @return pointer to the head of 'll_p'
     */
    LVLLNode * head()
    {
        return (LVLLNode *)lv_ll_get_head(_this);
    }

    /**
     * Return with tail node of the linked list
     * @return pointer to the head of 'll_p'
     */
    LVLLNode * tail()
    {
        return (LVLLNode *)lv_ll_get_tail(_this);
    }

    /**
     * Return with the pointer of the next node after 'n_act'
     * @param n_act pointer a node
     * @return pointer to the next node
     */
    LVLLNode * next(const LVLLNode * n_act)
    {
        return (LVLLNode *)lv_ll_get_next(_this ,n_act);
    }

    /**
     * Return with the pointer of the previous node after 'n_act'
     * @param ll_p pointer to linked list
     * @param n_act pointer a node
     * @return pointer to the previous node
     */
    LVLLNode * prev(const void * n_act)
    {
        return (LVLLNode *)lv_ll_get_prev(_this,n_act);
    }

    /**
     * Move a nodw before an other node in the same linked list
     * @param n_act pointer to node to move
     * @param n_after pointer to a node which should be after `n_act`
     */
    void moveBefore(void * n_act, void * n_after)
    {
        lv_ll_move_before(_this, n_act, n_after);
    }

};

#endif // LVLINKLIST_H
