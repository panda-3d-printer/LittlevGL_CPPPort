#ifndef LVSIGNALSLOT_H
#define LVSIGNALSLOT_H

#include <lvlinklist.hpp>
#include <functional>
#include <misc/lvmemory.hpp>


class LVSignal;
class LVSlot;
class Connection;

/**
 * LVSignal 在链表中的节点对象
 */
using LVSignalNode = LVLLNodeMate<LVSignal>;

/**
 * LVSlot 在链表中的节点对象
 */
using LVSlotNode = LVLLNodeMate<LVSlot>;

/**
 * Connection 在链表中的节点对象
 */
using ConnectionNode = LVLLNodeMate<Connection>;

/**
 * 定义事件处理器
 * 可以是函数
 * 可以是成员函数
 * 可以是拉姆达表达式
 */
using SlotFunc = std::function<void(LVSignal*)>;

/**
 * @brief 代表一个信号与槽的连接
 */
class Connection
{
    LV_MEMAORY_FUNC
public:
    enum ConnectType : uint8_t
    {
        DirectConnect, //直接连接 立即调用槽对象
        QueueConnect, //队列连接 等待系统空闲时再来执行槽对象
    };

    friend class LVSignal;
    friend class LVSlot;
    friend Connection * connect(LVSignal *signal, LVSlot *slot, ConnectType type);
    friend Connection * connect(LVSignal *signal0, LVSignal *signal1, ConnectType type);

protected:
    ConnectType m_type; //!< 连接的类型
    LVSignal * m_signal0 = nullptr; //!< 信号1
    LVSignal * m_signal1 = nullptr; //!< 型号2
    LVSlot * m_slot = nullptr; //!< 槽
public:
    virtual ~Connection();
protected:

    Connection(LVSignal * signal,LVSlot * slot,ConnectType type);

    Connection(LVSignal * signal0,LVSignal * signal1,ConnectType type);

    /**
     * @brief 执行这个连接
     */
    void operator()();

    /**
     * @brief 检测信号是否是发送者
     * 如果是两个信号连接需要确定发送者和接收者
     * @param signal
     * @return
     */
    bool isSender(LVSignal * signal)
    {
        if(!signal) return false;
        return m_signal0 == signal;
    }

    bool isReceiver(LVSignal * signal)
    {
        if(!signal) return false;
        return m_signal1 == signal;
    }

    bool isSignalSlotConnect()
    {
        return  m_signal0 && m_slot;
    }

    bool isSignalSignalConnect()
    {
        return  m_signal0 && m_signal1;
    }

    bool isvaild()
    {
        return (m_signal0 && m_slot) || (m_signal0 && m_signal1);
    }
};


Connection *connect(LVSignal * signal,LVSlot * slot,Connection::ConnectType type = Connection::DirectConnect);
Connection *connect(LVSignal * signal0,LVSignal * signal1,Connection::ConnectType type = Connection::DirectConnect);

void disConnect(LVSignal * signal,LVSlot * slot);
void disConnect(LVSignal * signal0,LVSignal * signal1);

void disConnectAll(LVSignal * signal);
void disConnectAll(LVSlot * slot);


/**
 * @brief 信号对象
 * 代表一种信号,
 * 能够被传播
 * 能够被关联
 * 能够被断开
 * 能够被控制
 */
class LVSignal
{
    LV_MEMAORY_FUNC

    friend class Connection;
    friend class LVSlot;
protected:
    void * m_param = nullptr; //!< 信号的参数(一个对象指针)
    LVLinkList m_slotList; //!<与信号关联的槽对象列表
public:
    LVSignal()
        :m_slotList(sizeof (Connection*))
    {}

    virtual ~LVSignal()
    {
        disConnectAll();
    }

    Connection *  connect(LVSignal * signal,Connection::ConnectType type = Connection::DirectConnect)
    {
        return ::connect(this,signal,type);
    }
    Connection *  connect(LVSlot * slot,Connection::ConnectType type = Connection::DirectConnect)
    {
        return ::connect(this,slot,type);
    }
    void disConnect(LVSlot * slot);
    void disConnect(LVSignal * signal);
    void disConnectAll();

    void emit(void * param = nullptr);

    void operator()(LVSignal * signal = nullptr)
    {
        emit();
    }


    void * param()
    {
        return m_param;
    }

    bool isConnected()
    {
        return m_slotList.head();
    }

    bool isConnectedBy(LVSignal * signal);

    bool isConnectedTo(LVSignal * signal);

    bool isConnectedTo(LVSlot * slot);

protected:

    void setParam(void * param);

    void addConnection(Connection * connect);

    void removeConnection(Connection * connection);
};



/**
 * @brief 槽对象
 * 代表信号的处理器
 * 能够被传播
 * 能够被关联
 * 能够被断开
 */
class LVSlot
{
    LV_MEMAORY_FUNC

    friend class Connection;
    friend class LVSignal;
protected:
    LVLinkList m_signalList; //!<关联的信号列表
    SlotFunc m_slotFunc; //!< 具体执行的槽函数
public:
    LVSlot(SlotFunc slotFunc = SlotFunc())
        :m_signalList(sizeof (Connection*))
    {
        setSlotFunc(slotFunc);
    }

    ~LVSlot()
    {
        disConnectAll();
    }

    void setSlotFunc(SlotFunc slotFunc)
    {
        m_slotFunc = slotFunc;
    }

    Connection * connect(LVSignal * signal,Connection::ConnectType type = Connection::DirectConnect)
    {
        return ::connect(signal,this,type);
    }

    void disConnect(LVSignal * signal)
    {
        ::disConnect(signal,this);
    }

    void disConnectAll();

    void operator()(LVSignal * signal)
    {
        m_slotFunc(signal);
    }

    bool isConnected()
    {
        return m_signalList.head();
    }

    bool isConnectedBy(LVSignal * signal);

protected:
    void addConnection(Connection * connect);

    void removeConnection(Connection * connection);
};


#endif // LVSIGNALSLOT_H


