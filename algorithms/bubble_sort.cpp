#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    bool swapped;
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i) {
        swapped = false;
        for(int j = 0; j < n - 1 - i; ++j) {
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    std::cout << "Sorted array: \n";
    for(const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}