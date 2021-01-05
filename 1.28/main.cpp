#include <iostream>
#include <stack>

// S is a subset of set {1, 2, ..., n}
// an array is not initialized, so there can be garbage values in it

class S{
    int * set;
    int * from; // from, to - helper arrays to check whether an element
    int * to;  // of set has been initialized
    int n;
    int top;
    std::stack<int> stack;
public:
    S(int size){
        n = size;
        set = new int [size + 1];
        from = new int[size + 1];
        to = new int[size + 1];
        top = 0;
    }

    void select(){
        if(stack.empty()) return;
        int i = stack.top();
        stack.pop();
        set[i] = 0;
        std::cout << i << std::endl;
    }

    bool search(int i){
        if(i < 1 || i > n) return false;
        if(top > n && set[i] == 1) return true;
        if(top > n && set[i] == 0) return false;
        if(from[i] < top && to[from[i]] == i){
            return true;
        }
        return false;
    }

    void insert(int i){
        if(i < 1 || i > n) return;
        if(top > n)
            set[i] = 1;
        else {
            set[i] = 1;
            from[i] = top;
            to[top] = i;
            top++;
        }
        stack.push(i);
    }

    ~S(){
        delete [] set;
        delete [] from;
        delete [] to;
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