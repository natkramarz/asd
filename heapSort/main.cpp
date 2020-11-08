#include <iostream>
#include <vector>
#include "heapSort.cpp"
#include <random>
#include <algorithm>

int main() {
    HeapSort heapSort = HeapSort();
    std::default_random_engine sizeGenerator;
    std::uniform_int_distribution<int> sizeDistribution(1, 200);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(-1000, 1000);

    for(int j = 0; j < 20; j++) {
        int size = sizeDistribution(sizeGenerator);
        std::vector<int> array(size);
        for (int i = 0; i < size; i++) {
            array[i] = distribution(generator);
        }
        heapSort.sort(array);
        if(std::is_sorted(begin(array), end(array))){
            std::cout << "Array is sorted!" << std::endl;
        }else{
            std::cout << "Array is not sorted!" << std::endl;
        }
    }
    return 0;
}
