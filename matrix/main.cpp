#include "matrix.h"

int main() {
    int size = 0;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    Matrix mat(size);
    mat.initRandom();
    mat.print();

    mat = mat * 5;
    std::cout << "Matrix: \n" << mat << std::endl; 

    return 0;
}