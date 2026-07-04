#ifndef STACK
#define STACK

#include <cstddef>
#include <iostream>
#include <initializer_list>

namespace sc{
template <typename T>
class Stack{

    struct Node{
        T data;
        Node* next;

        //=== [I] SPECIAL MEMBERS (1 OF THEM)
        
        explicit Node(T input) : //BASE CONSTRUCTOR
        data(input), next(nullptr) {};
    };

    //===ALIASES
public:
    using value_type = T;
    using size_type = size_t;
    using const_reference = const value_type&;

private:

    Node* head;
    size_type size;

public:

    //=== [I] SPECIAL MEMBERS(5 OF THEM)
    explicit Stack() : head(nullptr), size(0) {}    //BASE CONSTRUCTOR;
    virtual ~Stack(){  //DESTRUCTOR
        Node* curr = head;
        while (curr!=nullptr){
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    Stack(const std::initializer_list<value_type>& il)  //INITIALIZER_LIST CONSTRUCTOR
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
    Stack(const Stack& cpy)  //COPY CONSTRUCTOR
    :   head(nullptr), size(cpy.size)
    { 
        auto cpy_it {cpy.head};

        while (cpy_it != nullptr){
            Node* data = new Node(cpy_it->data);
            data->next = this->head;
            this->head = data;

            cpy_it = cpy_it->next;
        }
        
        Node* prev {nullptr};
        Node* curr {this->head};
        Node* next {this->head->next};

        while (curr!=nullptr){
            curr->next = prev;
            prev = curr;

            curr = next;

            if (next==nullptr) break;
            next = next->next;
        }

        this->head = prev;
    }
    Stack& operator=(const Stack& other){   //EQUAL OPERATOR
        if (this == &other){
            return *this;
        }

        // [ 1 ] Copy the data
        this->size = other.size;
        this->head = nullptr;

        auto cpy {other.head};
        
        while (cpy != nullptr){
            Node* data = new Node(cpy->data);
            data->next = this->head;
            this->head = data;
            
            cpy = cpy->next;
        }

        // [ 2 ] Invert the order
        Node* prev {nullptr};
        Node* curr {this->head};
        Node* next {this->head->next};

        while (curr!=nullptr){
            curr->next = prev;
            prev = curr;

            curr = next;

            if (next==nullptr) break;
            next = next->next;
        }

        this->head = prev;

        return *this;
    }

    //=== [II] MODIFIERS
    void push(const_reference input){
        Node* inp = new Node(input);
        inp->next = head;
        head = inp;
        size++;
    }
    void pop(){
        Node* new_head {head->next};
        delete head;
        head = new_head;
        size--;
    }
    void clear(){
        if (head==nullptr){
            return;
        }

        while (head != nullptr){
            Node* next {head->next};

            delete head;

            head = next;
        }

        size = 0;
    };

    //=== [III] GETTERS
    const_reference peek () const{ return head->data; }
    bool empty() const { return head==nullptr; }
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

    //=== [IV] COMPARISON OPERATORS
    bool operator==(const Stack& rhs){
        if (this->size != rhs.size){
            return false;
        }

        auto lhs_it {this->head};
        auto rhs_it {rhs.head};

        while (lhs_it != nullptr){
            if (lhs_it->data != rhs_it->data){
                return false;
            }

            lhs_it = lhs_it->next;
            rhs_it = rhs_it->next;
        }

        return true;
    }
    bool operator!=(const Stack& rhs){
        if (this->size != rhs.size){
            return true;
        }

        auto lhs_it {this->head};
        auto rhs_it {rhs.head};

        while (lhs_it != nullptr){
            if (lhs_it->data != rhs_it->data){
                return true;
            }

            lhs_it = lhs_it->next;
            rhs_it = rhs_it->next;
        }

        return false;
    }

};

}

#endif