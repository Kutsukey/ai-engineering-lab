#include <iostream>
#include <string_view>

enum class Day
{
    Pazartesi,
    Sali,
    Cuma
};

enum class MyDay
{
    Sali,
    Persembe,
    Pazar
};

std::string_view toString(Day day)
{
    switch (day)
    {
    case Day::Pazartesi:
        return "Pazartesi";
    case Day::Sali:
        return "Sali";
    case Day::Cuma:
        return "Cuma";

    default:
        return "Bilmiyorum Kingo";
    }
}

int main()
{
    Day day{Day::Sali};
    MyDay myDay{MyDay::Sali};

    std::cout << toString(day) << '\n';

    return 0;
}