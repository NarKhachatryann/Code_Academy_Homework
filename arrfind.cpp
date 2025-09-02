#include <iostream>

void initialArr(int arr[], int size) {
    std::cout << "Enter numbers of array: " << std::endl;
    for(int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

int numfinder(int arr[], int size, int num) {
    for(int i = 0; i < size; ++i) {
        if(arr[i] == num) {
            return i;
        }
    }
    return 0;
}

int main() {
    int num = 0;
    int size = 0;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];

    initialArr(arr,size);

    std::cout << "Enter number to find it: ";
    std::cin >> num;

    std::cout << "This is the index, which one you were looking for: " << numfinder(arr,size,num) + 1 << std::endl;

    delete[] arr;
}