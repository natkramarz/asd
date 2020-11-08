#ifndef HASHTABLES_HEAPSORT_H
#define HASHTABLES_HEAPSORT_H
#include <vector>

class Heap{
public:
    void buildHeap(std::vector<int> & array);
    void heapify(int i, std::vector<int> & heap);
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void insert(std::vector<int> & array, int value);
};

class HeapSort{
public:
    std::vector<int> sort(std::vector<int> & array);
};


#endif //HASHTABLES_HEAPSORT_H
