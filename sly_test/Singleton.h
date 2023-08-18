//
// Created by 石立宇 on 2023/8/7.
//

#ifndef TEST_SINGLETON_H
#define TEST_SINGLETON_H
#include <iostream>

namespace singleton01{
    //有缺陷的懒汉模式
    class Singleton{
    private:
        Singleton() {std::cout << "构造函数" << std::endl;};
        Singleton(const Singleton& singleton) = delete;
        Singleton& operator=(const Singleton& singleton) = delete;
        static Singleton* m_instance;
    public:
        ~Singleton(){std::cout << "析构函数" << std::endl;};
        static Singleton* Instance(){
            if(!m_instance){
                m_instance = new Singleton();
            }
            return m_instance;
        }
    };

    Singleton* Singleton::m_instance = nullptr;
}


namespace singleton03{

class Singleton
{
public:

    static Singleton* GetInstance()
    {
        return &m_instance;
    }

    void get(){
        std::cout << "this is a Singleton!" << std::endl;
    }

private:
    Singleton(){};
    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);

    static Singleton m_instance;
};

Singleton Singleton::m_instance;  // 在程序入口之前就完成单例对象的初始化
};


#endif //TEST_SINGLETON_H
