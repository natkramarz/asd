#include <iostream>
#include <vector>
#include "InsertionSort.h"

void InsertionSort::sort() {

    for (int i = 1; i < array.size(); i++) {
        int element = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > element) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = element;
    }

}

void InsertionSort::displayArray() {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "_____________________________________";
    std::cout << std::endl;
}