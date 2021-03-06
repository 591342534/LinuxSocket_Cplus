#pragma once
#include "base/noncopyable.h"
#include "EventLoopThread.h"
#include "base/Logging.h"
#include <memory>
#include <vector>
class EventLoopThreadPool : noncopyable
{
public:
    EventLoopThreadPool(EventLoop* baseloop, int numThreads);
    ~EventLoopThreadPool()
    {
        LOG << "~EventLoopThreadPool()" ;
    }
    void start();
    EventLoop *getNextLoop();

private:
    EventLoop* baseloop_;
    bool started_;
    int numThreads_;
    int next_;
    std::vector<std::shared_ptr<EventLoopThread>> threads_;
    std::vector<EventLoop*> loops_;
};