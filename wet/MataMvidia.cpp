//
// Created by yusse on 08/07/2024.
//
#include "MataMvidia.h"

MataMvidia::MataMvidia(std::string name, std::string made, Matrix *arr, int len):m_filmName(name),
m_madeName(made),mata_Arr(new Matrix[len]),m_length(len){
    for(int i=0;i<len;i++){
        mata_Arr[i]=arr[i];
    }
}

MataMvidia::MataMvidia(const MataMvidia &other):m_filmName(other.m_filmName),m_madeName(other.m_madeName),
m_length(other.m_length),mata_Arr(new Matrix[other.m_length]){
    for(int i=0;i<m_length;i++){
        mata_Arr[i]=other.mata_Arr[i];
    }
}

MataMvidia &MataMvidia::operator=(const MataMvidia &other) {
    if(this == &other)return *this;
    delete[] mata_Arr;
    mata_Arr=new Matrix[other.m_length];
    for(int i=0;i<m_length;i++){
        mata_Arr[i]=other.mata_Arr[i];
    }
    m_length=other.m_length;
    m_filmName=other.m_filmName;
    m_madeName=other.m_madeName;
    return *this;
}

MataMvidia::~MataMvidia() {
    delete[] mata_Arr;
}


Matrix &MataMvidia::operator[](int index) {
    if(index < 0 || index >= m_length){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return mata_Arr[index];
}

const Matrix &MataMvidia::operator[](int index) const {
    if(index < 0 || index >= m_length){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return mata_Arr[index];
}

MataMvidia &MataMvidia::operator+=(const MataMvidia &mata) {
    int len = m_length+mata.m_length;
    Matrix* temp = new Matrix[len];
    for (int i = 0; i < m_length; ++i) {
        temp[i] = mata_Arr[i];
    }
    for (int i = 0; i < mata.m_length; ++i) {
        temp[m_length + i] = mata.mata_Arr[i];
    }

    delete[] mata_Arr;
    mata_Arr=temp;
    m_length=len;
    return *this;
}

MataMvidia &MataMvidia::operator+=(const Matrix &frame) {
    int len = m_length+1;
    Matrix* temp = new Matrix[len];
    int i=0;
    for(i;i<m_length;i++){
        temp[i]=mata_Arr[i];
    }
    temp[i]=frame;
    delete[] mata_Arr;
    mata_Arr=temp;
    m_length=len;
    return *this;
}


MataMvidia operator+(const MataMvidia& m1 , const MataMvidia& m2){
    MataMvidia res=m1;
    res+=m2;
    return res;
}


std::ostream &operator<<(std::ostream &os, const MataMvidia &mata) {
    os << "Movie Name:" << mata.m_filmName << std::endl;
    os << "Author:" << mata.m_madeName << std::endl;
    for(int i=0 ; i<mata.m_length;i++){
        os << "Frame " << i <<":"<<std::endl;
        std::cout << mata.mata_Arr[i] <<std::endl;
    }
    return os;
}



