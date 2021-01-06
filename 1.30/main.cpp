#include <iostream>
#include <vector>

class q{

    std::vector<int> list;
    std::vector<int> min;
    int start;
    int minIndex;

public:
    q(){
        start = -1;
        minIndex = -1;
    }

    void push(int v){
        if(list.size() == 0){
            list.push_back(v);
        }
        else if(start + 1 < list.size()){
            list[start + 1] = v;
        }else{
            list.push_back(v);
        }
        start++;
        if(min.size() == 0){
            min.push_back(start);
            minIndex++;
        }else if(minIndex < 0 || v < list[min[minIndex]]){
            if(minIndex + 1 < min.size()){
                min[++minIndex] = start;
            }
            else{
                min.push_back(start);
                minIndex++;
            }
        }
    }

    void pop(){
        if(start >= 0)
            start--;
    }

    void uptomin(){
        start = min[minIndex] - 1;
        minIndex--;
    }

    void printList(){
        for(int i = 0; i <= start; i++){
            std::cout << list[i] << ", ";
        }
        std::cout << std::endl;
    }

    void prinMinList(){
        for(int i = 0; i <= minIndex; i++){
            std::cout << min[i] << ", ";
        }
        std::cout << std::endl;
    }
};

int main() {
    q list = q();
    list.push(10);
    list.push(11);
    list.push(9);
    list.push(12);
    list.push(14);
    list.push(16);
    list.push(3);
    list.push(4);
    list.push(5);
    list.prinMinList();
    list.printList();
    list.uptomin();
    list.prinMinList();
    list.printList();
    list.uptomin();
    list.printList();
    list.uptomin();
    list.printList();
    list.push(7);
    list.push(22);
    list.push(3);
    list.printList();
    list.pop();
    list.printList();
    return 0;
}
