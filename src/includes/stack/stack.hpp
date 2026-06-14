#ifndef STACK
#define STACK

#include <cstddef>
#include <iostream>
#include <initializer_list>

template <typename T>
class Stack{

    struct Node{
        T data;
        Node* next;

        //=== [I] SPECIAL MEMBERS (1 OF THEM)
        
        explicit Node(T input) : //BASE CONSTRUCTOR
        data(input), next(nullptr) {};

        bool operator==(const Node& rhs) const { return this->data==rhs.data; };
    };

    //===ALIASES
public:
    using value_type = T;
    using size_type = size_t;
    using pointer = value_type *;
    using reference = value_type&;
    using const_reference = const value_type&;

private:

    Node* head;
    size_type size;

public:

    //=== [I] SPECIAL MEMBERS(3 OF THEM)
    explicit Stack() : head(nullptr), size(0) {}    //BASE CONSTRUCTOR;
    virtual ~Stack(){  //DESTRUCTOR
        Node* curr = head;
        while (curr!=nullptr){
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    Stack(const std::initializer_list<T>& il)  //INITIALIZER_LIST CONSTRUCTOR
    : head(nullptr), size(il.size()){   
        auto cpy {il.end() - 1};
        auto end {il.begin()};
        while (cpy >= end){
            Node* data = new Node(*cpy);
            data->next = head;

            head = data;

            cpy--;
        }
    }
    
    //=== [II] MODIFIERS
    void push(const_reference input);
    void pop();
    void clear();

    //=== [III] GETTERS
    size_type get_size() const { return this->size; }
    friend std::ostream &operator<<(std::ostream & os, const Stack<T> &list){
        os << "{";
        Node* curr {list.head};
        while (curr!=nullptr){
            Node* next = curr->next;
            
            os << curr->data;

            if (next!=nullptr) os << ' ';
            curr = next;
        }

        os << '}';

        return os;
    }
    /*needed functions:
    
        modifiers:
            push
            pop
            clear
        
        getters:
            peek_head
            [[nodiscard]] size
    */


};

#endif