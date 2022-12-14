#ifndef LABTESTS_CALCULATOR_H
#define LABTESTS_CALCULATOR_H

#include <iostream>
#define ll long long

struct DoublyLinkedList {
    ll value;
    DoublyLinkedList* next;
    DoublyLinkedList* prev;

    DoublyLinkedList() {
        this->value = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    DoublyLinkedList(ll value) {
        this->value= value;
        this->next = nullptr;
        this->prev = nullptr;
    }

    void InsertValue(ll value){
        this->value = value;
    }

    bool IsEmpty(){
        if ( (this->prev == nullptr) && (this->next == nullptr)
             &&   (this->value == 0 ) ) return 1;
        else return 0;
    }

    //Add behind Node
    void PushBack(ll value) {
        this->prev = new DoublyLinkedList(value);
        this->prev->next = this;
    }

    //Add front Node
    void PushTop(ll value) {
        this->next = new DoublyLinkedList(value);
        this->next->prev = this;
    }

    ll ShowTop() {
        return this->value;
    }

    void DelAct() {
        this->next = nullptr;
        this->prev = nullptr;
        this->value	= 0;
        delete this;
    }

};


struct Stack {
    size_t Size =  0;
    DoublyLinkedList* Node = new DoublyLinkedList;
    DoublyLinkedList* Head = Node;
    DoublyLinkedList* Tail = Node;

    void Push(int value) {
        if (Node->IsEmpty()) {
            ++Size;
            Node->InsertValue(value);
            Head = Node;
            return ;
        }
        else{
            ++Size;
            Node->PushTop(value);
            Head = Node->next;
            Node = Head;
            return ;
        }
    }

    bool IsEmpty(){
        return (Size == 0) ? 1 : 0;
    }

    ll Pop() {
        if (Size==0) {
            printf("Underflow\n");
            return 0;
        }

        if (Size == 1) {
            --Size;
            ll result = Head->ShowTop();
            Head->InsertValue(0);
            return result;
        }

        DoublyLinkedList* tmp = Node;
        ll result = Head->ShowTop();
        --Size;
        Head = Head->prev;
        Head->next = nullptr;
        Node = Head;

        tmp->DelAct();


        return result;
    }

};

class Calculator {
public:
    long long calculate(std::string str);
};


#endif LABTESTS_CALCULATOR_H
