#include <iostream>
#include "mergeSort.cpp"
#include <vector>
int main() {
    std::vector<int> array{1, 2, 3, 2, 4};
    MergeSort sort = MergeSort();
    sort.array = array;
    sort.sort(0, array.size() -1 );
    sort.displayArray();
    return 0;
}
