//
// Created by yusse on 08/07/2024.
//
#include "Matrix.h"

Matrix::Matrix(int n, int m):n_rows(n),m_colums(m){ //m_Matrix(new int[m*n]) ??
    if(n > 0 && m > 0){
        m_Matrix = new int [n*m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                m_Matrix[i*m+j]=0;
            }
        }
    } else{
        m_Matrix = nullptr;
    }
}

Matrix::Matrix(const Matrix &other) {
    this->n_rows=other.n_rows;
    this->m_colums=other.m_colums;
    delete[] m_Matrix;
    if(n_rows > 0 && m_colums > 0){
        m_Matrix = new int [n_rows*m_colums];
        for(int i=0;i<n_rows;i++){
            for(int j=0;j<m_colums;j++){
                m_Matrix[(i*m_colums)+j]=0;
            }
        }
    } else{
        m_Matrix = nullptr;
    }
}

Matrix &Matrix::operator=(const Matrix &other) {
    if(this == &other)return *this;
    this->n_rows=other.n_rows;
    this->m_colums=other.m_colums;
    delete[] m_Matrix;
    if(n_rows > 0 && m_colums > 0){
        m_Matrix = new int [n_rows*m_colums];
        for(int i=0;i<n_rows;i++){
            for(int j=0;j<m_colums;j++){
                m_Matrix[(i*m_colums)+j]=0;
            }
        }
    } else{
        m_Matrix = nullptr;
    }
    return *this;
}

Matrix::~Matrix() {
        delete[] m_Matrix;
}

int& Matrix::operator()(int i, int j){
    if(i < 0 || j< 0 || i >= n_rows || j >= m_colums){
        exitWithError(MatamErrorType::OutOfBounds);
    }
   // if(m_Matrix == nullptr)exitWithError();
    return m_Matrix[i * m_colums + j];
}
 int& Matrix::operator()(int i, int j)const{
    if(i < 0 || j< 0 || i >= n_rows || j >= m_colums){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    // if(m_Matrix == nullptr)exitWithError();
    return m_Matrix[i * m_colums + j];
}

std::ostream &operator<<(std::ostream &os, const Matrix &frame){
    for(int i=0 ; i<frame.n_rows ;i ++){
        for(int j=0 ; j<frame.m_colums;j++){
            os << "|" << frame(i,j);
        }
        os << "|" <<std::endl;
    }
    return os;
}





