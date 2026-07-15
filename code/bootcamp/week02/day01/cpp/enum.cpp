#include <iostream>
#include <string>
#include <string_view>

enum Day{
    Pazartesi = 2,
    Sali,
    Carsamba,
    Persembe,
    Cuma,
    Cumartesi,
    Pazar,
};

std::string_view toString(Day day){
    switch (day)
    {
        case Pazartesi: return "Pazartesi";
        case Sali: return "Sali";
        case Carsamba: return "Carsamba";
        case Persembe: return "Persembe";
        case Cuma: return "Cuma";
        case Cumartesi: return "Cumartesi";
        case Pazar: return "Pazar";
        default: return "Senin Günün";
    }
}

std::ostream& operator<<(std::ostream& out, Day day){
    out << toString(day);
    return out;
}

std::istream& operator>>(std::istream& in, Day& day){
    int input {};
    if (in >> input)
    {
        day = static_cast<Day>(input);
    }
    return in;
}

int main(){
    Day myDay { Cuma };
    std::cout << myDay << '\n';

    // Day other { 5 }; static cast lazım
    int x;
    std::cin >> x;
    Day inputDay {static_cast<Day>(x)};
    std::cout << toString(inputDay) << " " << (inputDay==Persembe) << '\n';

    Day inputDay2;
    std::cin >> inputDay2;
    std::cout << inputDay2 << '\n';
    
    std::cout << Pazartesi << ' ' << Sali << ' ' << Carsamba << ' '
          << Persembe << ' ' << Cuma << ' ' << Cumartesi << ' ' << Pazar << '\n';
    return 0;
}