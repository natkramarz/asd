#include "mergeSort.h"
#include <iostream>
#include <vector>

void MergeSort::merge(int low, int mid, int high) {
    int i = low, j = mid + 1;
    std::vector<int> sortedArray(mid - low + 1 + high - (mid + 1) + 1);
    int newIndex = 0;
    while(i <= mid && j <= high){
        if(array[i] <= array[j]){
            sortedArray[newIndex] = array[i];
            i++;
        }else{
            sortedArray[newIndex] = array[j];
            j++;
        }
        newIndex++;
    }
    if(i <= mid){
        while(i <= mid){
            sortedArray[newIndex] = array[i];
            newIndex++;
            i++;
        }
    }
    if(j <= high){
        while(j <= high){
            sortedArray[newIndex] = array[j];
            newIndex++;
            j++;
        }
    }
    for(int i = 0; i < newIndex; i++){
        array[low++] = sortedArray[i];
    }
}


void MergeSort::sort(int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        sort(low, mid);
        sort(mid + 1, high);
        merge(low, mid, high);
    }
}

void MergeSort::displayArray() {
    for(int i = 0; i < array.size(); i++){
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl << std::endl;
}