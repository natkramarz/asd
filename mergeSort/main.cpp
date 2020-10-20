#include <iostream>
#include "mergeSort.cpp"
#include <vector>
#include <random>

int main() {
    std::vector<int> array{1, 2, 3, 2, 4};
    MergeSort sort = MergeSort();
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
        sort.array = array;
        sort.sort(0, array.size() - 1);
        sort.displayArray();
    }
    return 0;
}
