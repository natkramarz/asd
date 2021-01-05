#include <iostream>

// S is a subset of set {1, 2, ..., n}
// an array is not initialized, so there can be garbage values in it



class S{
        int * set;
        int * from;
        int * to;
        int n;
        int top;
public:
        S(int size){
            n = size;
            set = new int [size + 1];
            from = new int[size + 1];
            to = new int[size + 1];
            top = 0;
        }

        int select(){
            top--;
            int i = to[top];
            std::cout << i << std::endl;
            from[i] = 0;
            to[top] = 0;
        }

        bool search(int i){
            if(i < 1 || i > n) return false;
            if(from[i] < top && to[from[i]] == i){
                return true;
            }
            return false;
        }

        void insert(int i){
            if(i < 1 || i > n) return;
            set[i] = 1;
            from[i] = top;
            to[top] = i;
            if(top < n)
                top++;
        }
};



int main() {
    S set = S(7);
    set.insert(7);
    set.insert(2);
    set.insert(1);
    std::cout << set.search(7) << std::endl;
    std::cout << set.search(4) << std::endl;
    set.select();
    set.select();
    set.select();
    std::cout << set.search(7);
    return 0;
}
