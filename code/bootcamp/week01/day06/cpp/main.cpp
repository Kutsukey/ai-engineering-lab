#include <iostream>

template <typename T>
T max(T x, T y){
    return (x < y) ? y : x;
}

template <class T>
void mySwap(T& a, T& b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x{5};
    int y{10};

    std::cout << max(x,y) << '\n';
    mySwap(x,y);
    std::cout << x << " " << y << '\n';

    double a{2.0};
    double b{4.0};

    std::cout << max(a,b) << '\n';
    mySwap(a,b);
    std::cout << a << " " << b << '\n';

    return 0;
}