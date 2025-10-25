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
        }
    }

    Matrix(const Matrix& other) {
        for(int i = 0; i < m_size; ++i) {
            for(int j = 0; j < m_size; ++j) {
                other.m_data[i][j] = m_data[i][j];
            }
        }
    }

    const Matrix& operator= (const Matrix& other) {
        if(this != &other) {
            for(int i = 0; i < m_size; ++i) {
                for(int j = 0; j < m_size; ++j) {
                    other.m_data[i][j] = m_data[i][j];
                }
            }
        }

        return *this;
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
}