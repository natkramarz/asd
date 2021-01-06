#include <iostream>

// q is a sequence, q's elements are in the set {1, 2, ..., n}
// an array is not initialized, so there can be garbage values in it


class q{


    struct node{
        int i;
        node * prev;
        node * next;
        node(int i, node * prev, node * next){
            this->i = i;
            this->prev = prev;
            this->next = next;
        }
    };

    struct node_ptr{
        node * ptr;
        node_ptr * prev;

        node_ptr(node * ptr, node_ptr * prev){
            this->ptr = ptr;
            this->prev = prev;
        }
    };

    struct list{
        node_ptr * head;
        list(node_ptr * head){
            this->head = head;
        }
    };

    int n;
    int top;
    int * from; // from, to - helper arrays to check whether an element
    int * to;   // of set has been initialized
    list ** sequence;
    node * head;

public:
    q(int size){
        n = size;
        top = 0;
        from = new int [n + 1];
        to = new int [n + 1];
        sequence = new list * [n + 1];
        head = NULL;
    }


    void push(int i){
        if(i < 1 || i > n) return;
        if(top > n || (from[i] < top && to[from[i]] == i && sequence[i]->head != NULL)){
            node * tmp = new node(i, head, NULL);
            if(head != NULL)
                head->next = tmp;
            head = tmp;
            node_ptr * ptr = new node_ptr(tmp, sequence[i]->head);
            sequence[i]->head = ptr;
        }else{
            from[i] = top;
            to[top] = i;
            top++;
            node * tmp = new node(i, head, NULL);
            if(head != NULL)
                head->next = tmp;
            head = tmp;
            node_ptr * ptr = new node_ptr(tmp, NULL);
            sequence[i] = new list(ptr);
            sequence[i]->head = ptr;
        }
    }

    void pop(){
        node * tmp = head;
        head = tmp->prev;
        sequence[tmp->i]->head = sequence[tmp->i]->head->prev;
        delete tmp;
    }

    bool search(int i){
        if(i < 1 || i > n) return false;
        if(top > n && sequence[i]->head != NULL) return true;
        if(top > n && sequence[i]->head == NULL) return false;
        if(from[i] < top && to[from[i]] == i && sequence[i]->head != NULL){
            return true;
        }
        return false;
    }

    void deleteElement(int i){
        if(i < 1 || i > n) return;
        if(top > n && sequence[i]->head == NULL) return;
        if((from[i] < top && to[from[i]] == i && sequence[i]->head != NULL) || top > n && sequence[i]->head != NULL){
            node_ptr * tmp = sequence[i]->head;
            node_ptr * prev;
            while(tmp != NULL){ // deleting all occurrences of element i in the sequence
                prev = tmp->prev;
                node * node_in_list = tmp->ptr;
                if(node_in_list->prev != NULL){
                    node_in_list->prev->next = node_in_list->next;
                }
                if(node_in_list->next != NULL){
                    node_in_list->next->prev = node_in_list->prev;
                }else{
                    head = node_in_list->prev;
                }
                delete tmp;
                tmp = prev;
            }
        }
    }

    void print(){
        node * tmp = head;
        while(tmp != NULL){
            std::cout << tmp->i << std::endl;
            tmp = tmp->prev;
        }
    }

    ~q(){
        delete [] from;
        delete [] to;
        node * tmp = head;
        node * prev;
        for(int i = 0; i <= n; i++){
            delete sequence[i];
        }

        while(tmp != NULL){
            prev = tmp->prev;
            delete tmp;
            tmp = prev;
        }
    }

};


int main() {
    q sequence = q(5);
    sequence.push(1);
    sequence.push(2);
    sequence.push(3);
    sequence.push(4);
    sequence.push(1);
    sequence.push(5);
    sequence.push(1);
    std::cout << sequence.search(3) << std::endl;
    std::cout << sequence.search(5) << std::endl;
    sequence.deleteElement(1);
    sequence.print();
    return 0;
}
