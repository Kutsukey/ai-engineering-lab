#include <iostream>

struct Node
{
    int value;
    Node* next = nullptr;
};

void append(Node* head, int value){
    while (head->next != nullptr){
        head = head->next;
    }

    Node newNode {value};

    head->next = &newNode;
}

int main(){
    Node n1 {5};
    Node n2 {10};
    Node n3 {25};

    n1.next = &n2;
    n2.next = &n3;

    append(&n1,50);

    std::cout << n3.next->value;
    return 0;
}