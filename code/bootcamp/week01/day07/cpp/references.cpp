int x { 5 };
// x lvalue yani adresi alınabilir (x&)
// 5 rvalue adres yok

int y { 9 };
int& ref { y }; // ref direkt y

const int& const_ref { 11 }; // const ile rvalue referansı alınabilir

// & -> (Address-of) adresi alır, * -> (Dereference) adrese gidilir oku/yaz

int* ptr { &x }; // x'in bellekteki adresi

int tmp { *ptr }; // tmp = 5 (x'in değer)

// pointer boş ise nullptr olarak başlatılmalı

const int* ptr;	     //| ptr is a pointer to const int	        | Adresini değiştirebilirsin ama gösterdiği adresteki değeri değiştiremezsin (Read-only).
int* const ptr;	     //| ptr is a const pointer to int	        | Gösterdiği adresi asla değiştiremezsin ama o adresteki değeri değiştirebilirsin.
const int* const ptr;//| ptr is a const pointer to const int	| Her şey kilitli. Ne adres değişir, ne değer.

// Pass by value
void fn(int A);

// Pass by reference
void fn(const int& B);

// Pass by address
void fn(int* C);