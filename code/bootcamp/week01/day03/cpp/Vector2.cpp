#include "Vector2.h"
#include <cmath>

Vector2 Vector2::add(Vector2 vector)
{
    Vector2 newVector;
    newVector.x = x + vector.x;
    newVector.y = y + vector.y;
    return newVector;
}

Vector2 Vector2::substract(Vector2 vector)
{
    Vector2 newVector;
    newVector.x = x - vector.x;
    newVector.y = y - vector.y;
    return newVector;
}

float Vector2::length()
{
    return sqrtf((x * x) + (y * y));
}