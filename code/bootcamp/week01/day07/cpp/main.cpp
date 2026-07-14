#include <iostream>

struct Node{
    int val;
    Node* next {nullptr};
};

int main(){
    Node n1 {10};
    Node n2 {20};
    Node n3 {40};
    
    n1.next = &n2;
    n2.next = &n3;

    Node* current = &n1;
    while (current != nullptr){
        std::cout << "Adres: " <<current << " | Değeri = " << current->val << '\n';
        current = current->next;
    }
    return 0;
}