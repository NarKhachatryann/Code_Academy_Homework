#include <iostream>
#include <cstdlib>
#include <ctime>

bool isprime(int num) {
    if(num <= 1) return false;
    for(int i = 2; i * i <= num; ++i) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

void printarr(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void randomArray(int** matrix, int size) {
    srand(time(0));
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printprime(int** matrix, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(isprime(matrix[i][j])) {
                std::cout << matrix[i][j] << " ";
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    int size = 0;
    std::cout << "Enter size for matrix (NxN): " << std::endl;
    std::cin >> size;

    int** matrix = new int*[size];
    for(int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }

    randomArray(matrix,size);
    printarr(matrix,size);
    printprime(matrix,size);

    for(int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}