//
// Created by yusse on 08/07/2024.
//
#include <iostream>
#include "Matrix.h"
#include "MataMvidia.h"

int main(){

    Matrix frame1(2,2);
    Matrix frame2(2,2);
    frame1(0,0) = 1;
    frame1(1,0) = 2;
    frame1(0,1) = 3;
    frame1(1,1) = 3;
    frame2(0,0) = 1;
    frame2(1,0) = 2;
    frame2(0,0) = 2;
    frame2(1,1) = 2;
//
//    std::cout << frame1(0,0)<<std::endl;
//    std::cout << frame1<<std::endl;
//    std::cout << frame2<<std::endl;
//
//    Matrix frame3;
//    frame3=frame1+frame2;
//    std::cout <<"frame3 = " <<frame3<<std::endl;
//    frame3*=-2;
//    std::cout <<"frame3 = " <<frame3<<std::endl;
//    if(frame1 != frame2){
//        printf("aaaaaaa\n");
//    } else{
//        printf("laaaaaaaa\n");
//    }
    Matrix frame4(2,3);
    frame4(0,0) = 1;
    frame4(0,1) = 2;
    frame4(0,2) = 3;
    frame4(1,0) = 4;
    frame4(1,1) = 5;
    frame4(1,2) = 6;

    Matrix array[2];
    array[0] = frame1;
    array[1] = frame2;
    MataMvidia movie("MataMatrix","Adi Harif",array, 2);
    std::cout << movie <<std::endl;
   Matrix arr2[1];
   arr2[0]=frame4;
   MataMvidia temp("aaaaa","bbbbb",arr2,1);
   movie+=frame4;
    std::cout << movie <<std::endl;
    MataMvidia temp1 = movie +temp;
    std::cout << temp1 <<std::endl;


//    std::cout <<"frame4 = " <<frame4<<std::endl;
//    std::cout <<"rotate = " <<std::endl;
//    frame4.rotateClockwise();
//    std::cout <<frame4<<std::endl;
//    frame1.transpose();
//    std::cout <<frame1<<std::endl;
//    -frame1;
//    std::cout <<frame1<<std::endl;
//

    return 0;
}