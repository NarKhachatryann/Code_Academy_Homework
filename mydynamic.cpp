#include <iostream>

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
    int* mem = new int[5];
    delete[] mem;

    mem = nullptr;
    mem = new int;
    delete mem;

    return 0;
}