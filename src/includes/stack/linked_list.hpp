#ifndef LINKED_LIST
#define LINKED_LIST

template <typename T>
class LinkedList{
    class Node{
        T data;
        Node* next;

        public:
        Node(T input) : data(input), next(nullptr) {};
        Node(const Node& other){

        }
        
        void set_next(Node* ptr){ this->next = ptr; }
    };

public:
    class iterator{

    };

    class const_iterator{

    };

private:



};

#endif