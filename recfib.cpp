#include <iostream>

int fib(int n) {
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

void printfib(int n) {
    for(int i = 0; i <= n; ++i) {
        std::cout << fib(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int num = 0;
    std::cout << "Enter number for fibonachi" << std::endl;
    std::cin >> num;

    printfib(num);

    return 0;
}