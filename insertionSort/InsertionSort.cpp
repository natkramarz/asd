#include <iostream>
#include <vector>
#include "InsertionSort.h"

void InsertionSort::sort() {

    for (int j = 1; j < array.size(); j++) {
        int element = array[j];
        int i = j - 1;
        while (i >= 0 && array[i] > element) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = element;
    }
}
