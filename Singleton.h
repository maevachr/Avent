//
// Created by maeva on 11/07/18.
//

#ifndef AVENT_SINGLETON_H
#define AVENT_SINGLETON_H

#include <iostream>
#include <cassert>

template<class T>
class Singleton {
    static T* ms_Singleton;
public:
    Singleton(){
        assert(!ms_Singleton);
        ms_Singleton = static_cast<T*>(this);
    }
    ~Singleton(){ ms_Singleton = nullptr; }
    static T& GetSingleton(){
        assert(ms_Singleton);
        return *ms_Singleton;
    }
    static T* GetSingletonPtr(){
        return ms_Singleton;
    }
};
template <typename T>
    T* Singleton<T>::ms_Singleton = 0;


#endif //AVENT_SINGLETON_H
