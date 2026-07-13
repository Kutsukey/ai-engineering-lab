#include <iostream>

int foo(int a){
    return 0;
}

double foo(double b){
    return 1;
}

void printInt(int x){
    std::cout << x << '\n';
}

void print(int x=5, int y=1, int z=3){
    std::cout << x << " + " << y << " + " << z << '\n';
}

void printInt(char) = delete;
void printInt(bool) = delete;


// int main(){
//     foo(5);
//     foo(1.9);

//     print(5,2,3);

//     return 0;
// }