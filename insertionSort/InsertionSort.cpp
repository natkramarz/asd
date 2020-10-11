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
