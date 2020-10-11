#include <iostream>
#include <random>
#include "InsertionSort.cpp"

int main() {
    InsertionSort sort = InsertionSort();

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
        sort.sort();
        sort.displayArray();
    }

    return 0;
}
