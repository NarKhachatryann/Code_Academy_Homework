#include <iostream>
#include <cstdlib>
#include <ctime>

void randomArray(int arr[], int size) {
    srand(time(0));
    for( int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int size = 0;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];
    randomArray(arr, size);

    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}