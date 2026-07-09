#include <iostream>
#include "Vector2.h"

int main()
{
    Vector2 myVector;
    myVector.x = 3;
    myVector.y = 4;

    std::cout << myVector.length() << '\n';

    Vector2 otherVector;
    otherVector.x = 5;
    otherVector.y = 12;

    myVector = myVector.substract(otherVector);
    std::cout << myVector.length() << '\n';

    myVector = myVector.add(otherVector);
    std::cout << myVector.length() << '\n';
    std::cout << otherVector.length() << '\n';
}

