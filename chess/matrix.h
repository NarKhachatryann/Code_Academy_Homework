#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    char** m_data;
    int m_size;

public:
    Matrix(int size);
    Matrix(const Matrix& other);
    virtual ~Matrix();

    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;
    Matrix(Matrix&& other) noexcept;

    void pasteValue(char value, int row, int col);
    char getElement(int row, int col) const;
    void setElement(int row, int col, char value);
    int getSize() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& obj);
};

#endif
