#include "Thread.hpp"

Thread::Thread(){}
Thread::~Thread(){}

void Thread::yield(){
    sched_yield();
}

void Thread::start(){
    int status = pthread_attr_init(&_threadAttr);
    status = pthread_attr_setscope(&_threadAttr, PTHREAD_SCOPE_SYSTEM);
    if(status != 0)
        std::cerr << "Falha inicialização de thread: Inicialização do atributo da thread." << std::endl;
    status = pthread_create(&_threadID, &_threadAttr, this->runThread, (void*)this);
    if(status != 0)
        std::cerr << "Falha inicialização de thread: Inicialização da thread." << std::endl;
    status = pthread_attr_destroy(&_threadAttr);
    if(status != 0)
        std::cerr << "Falha inicialização de thread: Destruição do atributo da thread." << std::endl;
}

void Thread::join(){
    int status = pthread_join(_threadID, NULL);
    if(status != 0)
        std::cerr << "Falha Thread::join()." << std::endl;
}

void* Thread::runThread(void* pThread){
    Thread* sThread = static_cast<Thread*>(pThread);
    if(sThread == NULL){
        std::cerr << "Falha Thread::runThread()." << std::endl;
    }else{
        sThread->run();
    }
    return NULL;
}