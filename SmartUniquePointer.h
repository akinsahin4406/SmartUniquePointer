#pragma once

#include <iostream>
#include <bits/stdc++.h>

template<typename T>
class SmartUniquePointer
{
     T *my_ptr;
    public:
    SmartUniquePointer(T *ptr)
    {
        my_ptr = ptr;

    }

    ~SmartUniquePointer()
    {
        delete my_ptr;

    }

    SmartUniquePointer(const SmartUniquePointer& rhs) = delete;
    SmartUniquePointer& operator = (SmartUniquePointer& rhs) = delete;

    SmartUniquePointer& operator = (SmartUniquePointer&& rhs)
    {
        if (this != &rhs)
        {
            delete my_ptr;
            my_ptr = rhs.my_ptr;
            rhs.my_ptr = nullptr;
        }
        return *this;
    }

    SmartUniquePointer(SmartUniquePointer&& rhs)
    {
        my_ptr = rhs.my_ptr;
        rhs.my_ptr = nullptr;
    }
    
    T* get()
    {
        return my_ptr;
    }

    T* release()
    {
        T* ptr = my_ptr;
        my_ptr = nullptr;
        return ptr;
    }

    void reset(T* ptr)
    {
        delete my_ptr;
        my_ptr = ptr;
    }

    T& operator * ()
    {
        return *my_ptr;
    }
    T* operator -> ()
    {
        return my_ptr;
    }

};

template<typename T, typename... Args> SmartUniquePointer<T>&& make_unique_pointer(Args&&... args)
{
    T* rawptr = new T(std::forward<Args>(args)...);
    SmartUniquePointer<T>* smrptr = new SmartUniquePointer<T>(rawptr);
    return std::move(*smrptr);
}
