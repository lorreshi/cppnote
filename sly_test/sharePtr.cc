//
// Created by 石立宇 on 2023/8/7.
//
#include "sharePtr.h"

//循环引用
class A;
class B;

class A{
public:
    smartPtr<B> b_ptr;
    ~A(){
        std::cout << "a deleted " << std::endl;
    }
};

class B{
public:
    smartPtr<A> a_ptr;
    ~B(){
        std::cout << "b deleted " << std::endl;
    }
};

void test01(){
    smartPtr<int> ptr;
    std::cout << "ptr.use_count: " << ptr.use_count() << std::endl;
    smartPtr<int> ptr1(new int(10));
    std::cout << "ptr1.use_count: " << ptr1.use_count() << std::endl;
    smartPtr<int> ptr2(ptr1);
    std::cout << "ptr2.use_count: " << ptr2.use_count() << std::endl;
    std::cout << "ptr1.use_count: " << ptr1.use_count() << std::endl;
    smartPtr<int> ptr3(std::move(ptr2));
    std::cout << "ptr3.use_count: " << ptr3.use_count() << std::endl;
    std::cout << "ptr2.use_count: " << ptr2.use_count() << std::endl;
    std::cout << "ptr3.unique: " << ptr3.unique() << std::endl;
    ptr3.swap(ptr1);
    std::cout << "ptr3.use_count: " << ptr3.use_count() << std::endl;
    std::cout << "ptr3.unique: " << ptr3.unique() << std::endl;
    std::cout << "ptr1.use_count: " << ptr1.use_count() << std::endl;
}

int main(){

    smartPtr<A> pa;

    {
        smartPtr<A> ap(new A);
        smartPtr<B> bp(new B);
        ap->b_ptr = bp;
        bp->a_ptr = ap;
        //计数为2
        std::cout << ap.use_count() << " " << bp.use_count() << std::endl;


    }

    return 0;
}