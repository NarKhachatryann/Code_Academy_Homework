#include "matrix.h"
#include <fstream>

int main() {
    std::ofstream outfile("matrix_output.txt", std::ios::app);
    int size = 0;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    Matrix mat(size);
    mat.initRandom();
    mat.print();
    if(outfile.is_open()) {
        outfile << "Initial Matrix: \n" << mat << std::endl;
    }

    mat = mat * 5;
    std::cout << "Matrix: \n" << mat << std::endl;
    if(outfile.is_open()) {
        outfile << "Matrix: \n" << mat << std::endl;
        outfile.close();
    }

    return 0;
}