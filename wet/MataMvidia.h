//
// Created by yusse on 08/07/2024.
//
#include <iostream>
#include "Utilities.h"
#include "Matrix.h"
#ifndef WET_MATAMVIDIA_H
#define WET_MATAMVIDIA_H

class MataMvidia{
public:
    MataMvidia(std::string name, std::string made ,Matrix* arr , int len);
    MataMvidia(const MataMvidia& other);
    MataMvidia& operator=(const MataMvidia& other);
    ~MataMvidia();

    Matrix& operator[](int index);
    const Matrix& operator[](int index) const;
    MataMvidia& operator+=(const MataMvidia& mata);
    MataMvidia& operator+=(const Matrix& frame);
    friend std::ostream& operator<<(std::ostream&, const MataMvidia& frame);

private:
    Matrix* mata_Arr;
    int m_length;
    std::string& m_filmName;
    std::string& m_madeName;
};
MataMvidia operator+(const MataMvidia& m1 , const MataMvidia& m2);


#endif //WET_MATAMVIDIA_H
