#include <iostream>
#include <cstdlib>
#include <ctime>

class Matrix {
    private:
    int** m_data;
    int m_size;

    public:
    Matrix(int size) : m_size(size) {
        m_data = new int*[m_size];
        for(int i = 0; i < m_size; ++i) {
            m_data[i] = new int[m_size];
            for(int j = 0; j < m_size; ++j) {
                m_data[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& other) : m_size(other.m_size) {
        m_data = new int*[m_size];
        for(int i = 0; i < m_size; ++i) {
            m_data[i] = new int[m_size];
            for(int j = 0; j < m_size; ++j) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }

    Matrix& operator= (const Matrix& other) {
        if(this != &other) {
            for(int i = 0; i < m_size; ++i) {
                delete[] m_data[i];
            }
            delete[] m_data;

            m_size = other.m_size;
            m_data = new int*[m_size];
            for(int i = 0; i < m_size; ++i) {
                m_data[i] = new int[m_size];
                for(int j = 0; j < m_size; ++j) {
                    m_data[i][j] = other.m_data[i][j];
                }
            }
        }

        return *this;
    }

    Matrix operator* (const Matrix& other) {
        Matrix count(m_size);
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                for(int k = 0; k < m_size; ++k) {
                    count.m_data[i][j] += m_data[i][k] * other.m_data[k][j];
                }
            }
        }
        return count;
    }

    Matrix operator* (int num) {
        Matrix count(*this);
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                count.m_data[i][j] = m_data[i][j] * num;
            }
        }

        return count;
    }

    void init(){
        std::cout << "Enter elements for a " << m_size << "x" << m_size << " matrix:" << std::endl;
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                std::cin >> m_data[i][j];
            }
        }
    }

    void print() const {
        std::cout << "Matrix elements:" <<std::endl;
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                std::cout << m_data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void initRandom() {
        srand(time(0));
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                m_data[i][j] = rand() % 100;
            }
        }
    }

    void pasteValue(int value, int row, int col) {
        m_data[row][col] = value;
    }

    void transpose() {
        for(int i = 0; i < m_size; ++i) {
            for(int j = i + 1; j < m_size; ++j) {
                std::swap(m_data[i][j], m_data[j][i]);
            }
        }
        
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size / 2; ++j) {
                std::swap(m_data[i][j], m_data[i][m_size - j - 1]);
            }
        }
    }

    ~Matrix() {
        for(int i = 0; i < m_size; ++i) {
            delete[] m_data[i];
        }
        delete[] m_data;
    }
};

int main() {
    int size = 0;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    Matrix mat(size);
    mat.initRandom();
    mat.print();

    mat = mat * 5;
    mat.print();

    return 0;
}