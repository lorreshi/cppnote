//
// Created by 石立宇 on 2023/8/7.
//

#include<iostream>
#include"Singleton.h"

int main(){
    std::cout << "-------------------------" << std::endl;
    singleton01::Singleton* s1 = singleton01::Singleton::Instance();
    std::cout << "-------------------------" << std::endl;
    singleton01::Singleton* s2 = singleton01::Singleton::Instance();
    std::cout << "-------------------------" << std::endl;

//    Singleton* singleton1 = Singleton::GetInstance();
//    singleton1->get();
    return 0;
}