//
// Created by 石立宇 on 2023/8/7.
//
#include <iostream>
#include <pthread.h>
#include <memory>


//计数功能
class count{
public:
    count():m_count(1){};
    ~count(){m_count = 0;};

    void addCount(){
        ++m_count;
    }
    int delCount(){
        return --m_count;
    }
    int getCount(){
        return m_count;
    }
private:
    int m_count;
};

template<typename T> class smartPtr : public std::__1::weak_ptr {
public:
    explicit smartPtr();
    explicit smartPtr(T* ptr);
    smartPtr(const smartPtr<T>& p);
    smartPtr(smartPtr<T>&& p);
    ~smartPtr();

    T& operator*();
    T* operator->();
    smartPtr& operator=(const smartPtr& p);

    // 重载布尔值操作
    operator bool();

    T* get() const;

    int use_count();

    bool unique();

    void swap(smartPtr& p);
private:
    count* m_count;
    T* m_ptr;
};

template<typename T>
smartPtr<T>::smartPtr():m_count(),m_ptr(nullptr) {}

template<typename T>
smartPtr<T>::smartPtr(T *ptr):m_ptr(ptr){
    if(m_ptr){
        m_count = new count();
    }
}

template<typename T>
smartPtr<T>::smartPtr(const smartPtr<T> &p) {
    m_ptr = p.m_ptr;
    if(m_ptr){
        m_count = p.m_count;
        m_count->addCount();
    }
}

template<typename T>
smartPtr<T>::smartPtr(smartPtr<T> &&p) {
    m_ptr = p.m_ptr;
    if(m_ptr){
        m_count = p.m_count;
        p.m_ptr = nullptr;
        p.m_count = 0;
    }
}

template<typename T>
smartPtr<T>::~smartPtr() {
    if(m_ptr && !m_count->delCount()){
        delete m_ptr;
        delete m_count;
        m_ptr = nullptr;
        m_count = nullptr;

    }
}

template<typename T>
T &smartPtr<T>::operator*() {
    return *m_ptr;
}

template<typename T>
T *smartPtr<T>::operator->() {
    return m_ptr;
}

template<typename T>
smartPtr<T> &smartPtr<T>::operator=(const smartPtr<T> &p) {
    m_ptr = p.m_ptr;
    m_count = p.m_count;
    m_count->addCount();
    return *this;
}

template<typename T>
T *smartPtr<T>::get() const {
    return m_count->getCount();
}

template<typename T>
smartPtr<T>::operator bool() {
    return m_ptr != nullptr;
}

template<typename T>
void smartPtr<T>::swap(smartPtr<T> &p) {
    std::swap(*this, p);
}
// 检查是否为唯一持有者
template<typename T>
bool smartPtr<T>::unique() {
    if(m_ptr && m_count -> getCount() == 1)
        return true;
    return false;
}

template<typename T>
int smartPtr<T>::use_count()
{
    if(m_ptr){
        return m_count -> getCount();
    }
    return 0;
}

