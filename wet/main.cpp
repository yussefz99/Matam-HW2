//
// Created by yusse on 08/07/2024.
//
#include <iostream>
#include "Matrix.h"


int main(){

    Matrix frame1(2,2);
    Matrix frame2(2,3);
    frame1(0,0) = 1;
    std::cout << frame1(0,0)<<std::endl;
    std::cout << frame1;

    return 0;
}