//
// Created by yusse on 08/07/2024.
//
#include "Matrix.h"

Matrix::Matrix(int n, int m):n_rows(n),m_colums(m),m_Matrix(new int[m*n]) {
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                m_Matrix[i*m+j]=0;
            }
        }
}

Matrix::Matrix():n_rows(0),m_colums(0),m_Matrix(nullptr) {}

Matrix::Matrix(const Matrix &other):n_rows(other.n_rows),
m_colums(other.m_colums),m_Matrix(new int[other.n_rows+other.m_colums]) {
    for(int i=0;i<other.n_rows;i++){
        for(int j=0;j<other.m_colums;j++){
            m_Matrix[i*other.m_colums+j]=other.m_Matrix[i*other.m_colums+j];
        }
    }

}

Matrix &Matrix::operator=(const Matrix &other) {
    if(this == &other)return *this;
    int* temp_Matrix= nullptr;
    temp_Matrix = new int [other.n_rows*other.m_colums];
    for(int i=0;i<other.n_rows;i++){
        for(int j=0;j<other.m_colums;j++){
            temp_Matrix[i*other.m_colums+j]=other.m_Matrix[i*other.m_colums+j];
        }
    }
    delete[] m_Matrix;
    this->n_rows=other.n_rows;
    this->m_colums=other.m_colums;
    m_Matrix = temp_Matrix;
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

Matrix &Matrix::operator+=(const Matrix &frame) {
    if(n_rows != frame.n_rows || m_colums != frame.m_colums){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    for(int i=0;i<n_rows;i++){
        for(int j=0;j<m_colums;j++){
            m_Matrix[(i*m_colums)+j]+=frame.m_Matrix[(i*m_colums)+j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &frame) {
    if(n_rows != frame.n_rows || m_colums != frame.m_colums){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    for(int i=0;i<n_rows;i++){
        for(int j=0;j<m_colums;j++){
            m_Matrix[(i*m_colums)+j]-=frame.m_Matrix[(i*m_colums)+j];
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &frame) {
    if(m_colums != frame.n_rows){
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    int* result = new int[n_rows * frame.m_colums];
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < frame.m_colums; ++j) {
            result[i * frame.m_colums + j] = 0;
            for (int k = 0; k < m_colums; ++k) {
                result[i * frame.m_colums + j] += m_Matrix[i * m_colums + k] * frame.m_Matrix[k * frame.m_colums + j];
            }
        }
    }

    delete[] m_Matrix;
    m_Matrix = result;
    m_colums = frame.m_colums;

    return *this;
}

Matrix &Matrix::operator*=(int k) {
    for(int i=0;i<n_rows;i++){
        for(int j=0;j<m_colums;j++){
            m_Matrix[(i*m_colums)+j]*=k;
        }
    }
    return *this;
}

Matrix operator+(const Matrix& frame1 , const Matrix& frame2){
    Matrix res = frame1;
    res +=frame2;
    return res;
}

Matrix operator-(const Matrix& frame1 , const Matrix& frame2){
    Matrix res = frame1;
    res -=frame2;
    return res;
}

Matrix &Matrix::operator-() {
    return (*this)*-1;
}

Matrix operator*(const Matrix& frame1 , const Matrix& frame2){
    Matrix res = frame1;
    res *=frame2;
    return res;
}

Matrix &Matrix::operator*(int k) {
    for(int i=0;i<n_rows;i++){
        for(int j=0;j<m_colums;j++){
            m_Matrix[(i*m_colums)+j]*=k;
        }
    }
    return *this;
}

Matrix& operator*(int k, Matrix &frame2) {
    return frame2*k;
}

bool operator==(const Matrix& frame1, const Matrix& frame2){
    if(frame1.n_rows != frame2.n_rows || frame1.m_colums != frame2.m_colums)return false;
    int n =frame1.n_rows;
    int m =frame1.m_colums;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(frame1.m_Matrix[(i*m)+j] != frame2.m_Matrix[(i*m)+j])return false;
        }
    }
    return true;
}

bool operator!=(const Matrix& frame1, const Matrix& frame2){
    return !(frame1==frame2);
}

Matrix& Matrix::rotateClockwise() {
    int* newMatrix = new int[m_colums * n_rows];
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < m_colums; ++j) {
            newMatrix[j * n_rows + (n_rows - 1 - i)] = m_Matrix[i * m_colums + j];
        }
    }
    delete[] m_Matrix;
    m_Matrix = newMatrix;
    std::swap(n_rows, m_colums);
    return *this;
}

Matrix& Matrix::rotateCounterClockwise() {
    int* newMatrix = new int[m_colums * n_rows];
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < m_colums; ++j) {
            newMatrix[(m_colums - 1 - j) * n_rows + i] = m_Matrix[i * m_colums + j];
        }
    }
    delete[] m_Matrix;
    m_Matrix = newMatrix;
    std::swap(n_rows, m_colums);
    return *this;
}

Matrix &Matrix::transpose() {
    int* newMatrix = new int[m_colums * n_rows];
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < m_colums; ++j) {
            newMatrix[j * n_rows + i] = m_Matrix[i * m_colums + j];
        }
    }
    delete[] m_Matrix;
    m_Matrix = newMatrix;
    std::swap(n_rows, m_colums);
    return *this;
}





