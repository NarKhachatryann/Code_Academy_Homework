#include <iostream>
#include <cstdlib>
#include <ctime>

void printarr(int arr[], int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void randomArray(int arr[], int size) {
    srand(time(0));
    for( int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}

void* operator new(std::size_t size) {
    if(void* p = malloc(size)) {
        std::cout << "The memory has allocated!" << std::endl;
        return p;
    }
    else {
        std::cout << "Memory don't allocated!" << std::endl;
        return p;
    }
}

void operator delete(void* mem) noexcept {
    free(mem);
    std::cout << "Memory is deallocated!" << std::endl;
}

void* operator new[](std::size_t size) {
    if(void* p = malloc(size)) {
        std::cout << "Memory is allocated" << std::endl;
        return p;
    }
    else {
        std::cout << "Memory allocate is failed!" << std::endl;
        return p;
    }
}

void operator delete[] (void* mem) noexcept {
    free(mem);
    std::cout << "Memory are deallocated" << std::endl;
}

int main() {
    int size = 0;
    std::cout << "Enter Size for array: ";
    std::cin >> size;

    int* arr = new int[size];
    randomArray(arr,size);

    printarr(arr, size);

    delete[] arr;

    return 0;
}