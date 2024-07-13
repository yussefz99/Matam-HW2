//
// Created by yusse on 08/07/2024.
//
#include <iostream>
#include "Utilities.h"
#ifndef WET_MATRIX_H
#define WET_MATRIX_H

class Matrix {
private:

    int n_rows;
    int m_colums;
    int* m_Matrix;

public:

    Matrix(int n,int m);
    Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();
    Matrix rotateClockwise();
    Matrix rotateCounterClockwise();
    Matrix transpose();
    int& operator()(int i , int j);
    int& operator()(int i , int j)const;
    Matrix& operator+=(const Matrix& frame);
    Matrix& operator-=(const Matrix& frame);
    Matrix& operator*=(const Matrix& frame);
    Matrix& operator*=(int k);
    Matrix operator*(int k);//&
    Matrix operator-();//&

    // Friend functions
    friend bool operator!=(const Matrix& frame1, const Matrix& frame2);
    friend bool operator==(const Matrix& frame1, const Matrix& frame2);
    friend Matrix operator*(int k , Matrix& frame2);//&&&
    friend std::ostream& operator<<(std::ostream& os, const Matrix& frame);
};

// Non-member operators
Matrix operator+(const Matrix& frame1 , const Matrix& frame2);
Matrix operator-(const Matrix& frame1 , const Matrix& frame2);
Matrix operator*(const Matrix& frame1 , const Matrix& frame2);


#endif //WET_MATRIX_H
