#include "heapSort.h"
#include <vector>
#include <iostream>

int Heap::parent(int i){
    return i / 2;
}
int Heap::leftChild(int i){
    return 2 * i + 1;
}
int Heap::rightChild(int i){
    return 2 * i + 2;
}
void Heap::heapify(int i, std::vector<int> & heap) {
    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;
    if(left < heap.size() && heap[left] > heap[i]){
        largest = left;
    }
    if(right < heap.size() && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != i){
        std::swap(heap[i], heap[largest]);
        heapify(largest, heap);
    }
}
void  Heap::buildHeap(std::vector<int> & array) {
    for(int i = array.size() / 2 - 1; i >= 0; i--){
        heapify(i, array);
    }
}

void Heap::displayHeap(int i, std::vector<int> & array) {
    if(leftChild(i) < array.size() && rightChild(i) < array.size()){
        if(array[leftChild(i)] < array[rightChild(i)]){
            displayHeap(leftChild(i), array);
            displayHeap(rightChild(i), array);
        }
        else{
            displayHeap(rightChild(i), array);
            displayHeap(leftChild(i), array);
        }
    }
    else if(rightChild(i) < array.size()){
        displayHeap(rightChild(i), array);
    }else if(leftChild(i) < array.size()){
        displayHeap(leftChild(i), array);
    }
    std::cout << array[i] << " ";
}

std::vector<int> HeapSort::sort(std::vector<int> & array){
    std::vector<int> sortedArray(array.size());
    Heap heap;
    heap.buildHeap(array);
    for(int i = array.size() - 1; i >= 0; i--){
        std::swap(array[i], array[0]);
        sortedArray[i] = array[i];
        array.pop_back();
        heap.heapify(0,array);
    }
    return sortedArray;
}
