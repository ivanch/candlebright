#pragma once
#include <pthread.h>
#include <iostream>

class Thread {
    private:
        pthread_t _threadID;
        pthread_attr_t _threadAttr;
        static void* runThread(void* _thread);

    protected:
        virtual void run() = 0;
    
    public:
        Thread();
        virtual ~Thread();

        void start();
        void join();
        void yield();
};