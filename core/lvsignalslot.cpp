#include "lvsignalSlot.hpp"
#include <lvtask.hpp>


Connection * connect(LVSignal *signal, LVSlot *slot, Connection::ConnectType type)
{
    return  new Connection(signal,slot,type);
}
Connection * connect(LVSignal *signal0, LVSignal *signal1, Connection::ConnectType type)
{
    return new Connection(signal0,signal1,type);
}

void disConnect(LVSignal *signal, LVSlot *slot)
{
    if(signal && slot)
    {
        signal->disConnect(slot);
    }

}
void disConnect(LVSignal *signal0, LVSignal *signal1)
{
    if(signal0 && signal1)
    {
        signal0->disConnect(signal1);
    }
}

void disConnectAll(LVSlot *slot)
{
    if(slot)
        slot->disConnectAll();
}
void disConnectAll(LVSignal *signal)
{
    if(signal)
        signal->disConnectAll();
}

Connection::~Connection()
{
    if(m_signal0)
        m_signal0->removeConnection(this);
    if(m_signal1)
        m_signal1->removeConnection(this);
    if(m_slot)
        m_slot->removeConnection(this);
}

Connection::Connection(LVSignal *signal, LVSlot *slot, ConnectType type)
    :m_signal0(signal)
    ,m_slot(slot)
    ,m_type(type)
{
    if(isSignalSlotConnect())
    {
        m_signal0->addConnection(this);
        m_slot->addConnection(this);
    }
}

Connection::Connection(LVSignal *signal0, LVSignal *signal1, ConnectType type)
    :m_signal0(signal0)
    ,m_signal1(signal1)
    ,m_type(type)
{
    if(isSignalSignalConnect())
    {
        m_signal0->addConnection(this);
        m_signal1->addConnection(this);
    }
}

void Connection::operator()()
{
    if(isvaild())
    {
        if(isSignalSlotConnect())
        {
            if(m_type == DirectConnect)
                (*m_slot)(m_signal0);
            else if(m_type == QueueConnect)
                LVTask::once(1,[=](){ (*m_slot)(m_signal0); });
        }
        else if(isSignalSignalConnect())
        {
            if(m_type == DirectConnect)
                (*m_signal1)(m_signal0);
            else if(m_type == QueueConnect)
                LVTask::once(1,[=](){ (*m_signal1)(m_signal0); });
        }
    }
}



void LVSignal::disConnect(LVSlot *slot)
{
    if(slot)
    {
        LVLLNode * node = m_slotList.head();
        while (node)
        {
            ConnectionNode & connecttion = *((ConnectionNode*)node);
            if(connecttion->m_slot == slot) //connecttion &&
            {
                connecttion->m_slot->removeConnection(connecttion.mate());
                connecttion->m_slot = nullptr;
                connecttion->m_signal0 = nullptr;
                m_slotList.remove(node);
                delete connecttion.mate();
                return;
            }
            //执行连接
            node = m_slotList.next(node);
        }
    }
}

void LVSignal::disConnect(LVSignal *signal)
{
    if(signal)
    {
        LVLLNode * node = m_slotList.head();
        while (node)
        {
            ConnectionNode & connecttion = *((ConnectionNode*)node);
            //if(connecttion)
            //{
                if(connecttion->m_signal1 == signal)
                {
                    connecttion->m_signal1->removeConnection(connecttion.mate());
                    connecttion->m_signal1 = nullptr;
                    connecttion->m_signal0 = nullptr;
                    m_slotList.remove(node);
                    delete connecttion.mate();
                }
                else if(connecttion->m_signal0 == signal)
                {
                    connecttion->m_signal0->removeConnection(connecttion.mate());
                    connecttion->m_signal1 = nullptr;
                    connecttion->m_signal0 = nullptr;
                    m_slotList.remove(node);
                    delete connecttion.mate();
                }
                return;
            //}
            //执行连接
            node = m_slotList.next(node);
        }
    }
}

void LVSignal::disConnectAll()
{
    LVLLNode * node = m_slotList.head();
    while (node)
    {
        ConnectionNode & connect = *((ConnectionNode*)node);
        //if(connect)
        //{
            if(connect->isSignalSlotConnect())
            {
                connect->m_slot->removeConnection(connect.mate());
                connect->m_signal0 = nullptr;
                connect->m_slot = nullptr;
            }
            else if(connect->isSignalSignalConnect())
            {
                if(connect->isSender(this))
                {
                    connect->m_signal1->removeConnection(connect.mate());
                    connect->m_signal0 = nullptr;
                    connect->m_signal1 = nullptr;
                }
                else
                {
                    connect->m_signal0->removeConnection(connect.mate());
                    connect->m_signal0 = nullptr;
                    connect->m_signal1 = nullptr;
                }
            }
            delete connect.mate();
        //}
        node = m_slotList.next(node);
    }
    m_slotList.clear();
}

void LVSignal::emit(void * param)
{
    setParam(param);
    LVLLNode * node = m_slotList.head();
    while (node)
    {
        ConnectionNode & connecttion = *((ConnectionNode*)node);
        if(connecttion.mate())
            (*connecttion.mate())();
        //执行连接
        node = m_slotList.next(node);
    }
}

bool LVSignal::isConnectedBy(LVSignal *signal)
{
    LVLLNode * node = m_slotList.head();
    while (node)
    {
        ConnectionNode & connect = *((ConnectionNode*)node);
        if(signal == connect->m_signal0 && this == connect->m_signal1 )
            return true;
        node = m_slotList.next(node);
    }
    return false;
}

bool LVSignal::isConnectedTo(LVSignal *signal)
{
    LVLLNode * node = m_slotList.head();
    while (node)
    {
        ConnectionNode & connect = *((ConnectionNode*)node);
        if(signal == connect->m_signal1 && this == connect->m_signal0 )
            return true;
        node = m_slotList.next(node);
    }
    return false;
}

bool LVSignal::isConnectedTo(LVSlot *slot)
{
    LVLLNode * node = m_slotList.head();
    while (node)
    {
        ConnectionNode & connect = *((ConnectionNode*)node);
        if(slot == connect->m_slot && this == connect->m_signal0 )
            return true;
        node = m_slotList.next(node);
    }
    return false;
}

void LVSignal::setParam(void *param)
{
    m_param = param;
}

void LVSignal::addConnection(Connection *connect)
{
    ConnectionNode * newNode = (ConnectionNode *)m_slotList.insertTail();
    newNode->mate() = connect;
}

void LVSignal::removeConnection(Connection *connection)
{
    LVLLNode * node = m_slotList.head();
    while (node)
    {
        ConnectionNode & connect = *((ConnectionNode*)node);
        if(connect.mate() == connection)
        {
            m_slotList.remove(node);
            return;
        }
        node = m_slotList.next(node);
    }
}

void LVSlot::disConnectAll()
{
    LVLLNode * node = m_signalList.head();
    while (node)
    {
        ConnectionNode & connect = *((ConnectionNode*)node);
        if(connect.mate() && connect->isSignalSlotConnect())
        {
            connect->m_signal0->removeConnection(connect.mate());
            connect->m_signal0 = nullptr;
            connect->m_slot = nullptr;
            delete connect.mate();
        }
        node = m_signalList.next(node);
    }
    m_signalList.clear();
}

bool LVSlot::isConnectedBy(LVSignal *signal)
{
    LVLLNode * node = m_signalList.head();
    while (node)
    {
        ConnectionNode & connect = *((ConnectionNode*)node);
        if(signal == connect->m_signal0 && this == connect->m_slot)
            return true;
        node = m_signalList.next(node);
    }
    return false;
}

void LVSlot::addConnection(Connection *connect)
{
    ConnectionNode * newNode = (ConnectionNode *)m_signalList.insertTail();
    newNode->mate() = connect;
    //memcpy(newNode,connect,sizeof(Connection *));
}

void LVSlot::removeConnection(Connection *connection)
{
    LVLLNode * node = m_signalList.head();
    while (node)
    {
        ConnectionNode & connect = *((ConnectionNode*)node);
        if(connect.mate() == connection)
        {
            m_signalList.remove(node);
            return;
        }
        node = m_signalList.next(node);
    }
}
