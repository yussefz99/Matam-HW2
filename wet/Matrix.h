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
    int* m_Matrix;//??????

public:

    Matrix(int n,int m);
    Matrix()=default;
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();
    int& operator()(int i , int j);
    int& operator()(int i , int j)const;
    friend std::ostream& operator<<(std::ostream&, const Matrix& frame);//privte???????
};

#endif //WET_MATRIX_H
