#include "matrix.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Matrix::Matrix(int size) : m_size(size) {
    m_data = new char*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = new char[m_size];
        for (int j = 0; j < m_size; ++j) {
            m_data[i][j] = '.';
        }
    }
}

Matrix::Matrix(const Matrix& other) : m_size(other.m_size) {
    m_data = new char*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = new char[m_size];
        for (int j = 0; j < m_size; ++j) {
            m_data[i][j] = other.m_data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < m_size; ++i) {
        delete[] m_data[i];
    }
    delete[] m_data;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < m_size; ++i) {
            delete[] m_data[i];
        }
        delete[] m_data;

        m_size = other.m_size;
        m_data = new char*[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = new char[m_size];
            for (int j = 0; j < m_size; ++j) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }
    return *this;
}

Matrix::Matrix(Matrix&& other) noexcept : m_data(other.m_data), m_size(other.m_size) {
    other.m_size = 0;
    other.m_data = nullptr;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if(this != &other) {
        for(int i = 0; i < m_size; ++i) {
            delete[] m_data[i];
        }
        delete[] m_data;

        m_data = other.m_data;
        m_size = other.m_size;

        other.m_data = nullptr;
        other.m_size = 0;
    }
    
    return *this;
}

void Matrix::pasteValue(char value, int row, int col) {
    m_data[row][col] = value;
}

char Matrix::getElement(int row, int col) const {
    return m_data[row][col];
}

void Matrix::setElement(int row, int col, char value) {
    m_data[row][col] = value;
}

int Matrix::getSize() const {
    return m_size;
}

std::ostream& operator<<(std::ostream& os, const Matrix& obj) {
    for (int i = 0; i < obj.m_size; ++i) {
        for (int j = 0; j < obj.m_size; ++j) {
            os << obj.m_data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}