#include <iostream>
#include "InsertionSort.cpp"

int main() {
    InsertionSort sort = InsertionSort();
    std::vector<int> array { 12, 11, 8, 5, 6 };
    sort.array = array;
    sort.sort();
    for (int i = 0; i < 5; i++) {
        std::cout << sort.array[i] << " ";
    }
    return 0;
}
