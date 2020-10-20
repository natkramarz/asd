#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H
#include <vector>

class MergeSort {
public:
    std::vector<int> array;


    void sort(int low, int high);

    void merge(int low, int mid, int high);

    void displayArray();
};


#endif //MERGESORT_MERGESORT_H
