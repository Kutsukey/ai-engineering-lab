#include <array>
#include <vector>
#include <iostream>
#include <string>

std::vector<int> createVector(){
    std::vector<int> created_vector{10,20,30};
    return created_vector;
}

template <typename T>
T calculateAverage(std::vector<T>& arr){
        T average{0};
    for (std::size_t i{0}; i < arr.size(); i++)
    {
        average += arr[i];
    }
    average /= static_cast<int>(arr.size());
    return average;
}

enum Items{
    armor,
    sword,
    potion,
    max_items
};

int main(){
    std::array<int, 4> first_array{10,20,30,40};
    std::vector<int> first_vector{5,10,15};

    std::vector<int> numbers{}; // Boş ise <> tip lazım
    std::vector grades{90,95,100}; // Compiler tipi bulur
    
    // size() -> std::size_t döndürüyor. unsigned integer
    std::cout << grades.size() << std::endl; 

    std::vector function_vector{createVector()};

    std::cout << function_vector[0] << '\n';

    std::cout << calculateAverage(first_vector) << std::endl;

    for (int i = std::ssize(grades) - 1; i >= 0; i--) // std::ssize() modern size çözümü signed döndürür
    {
        std::cout << grades[i] << '\n';
    }
    

    std::vector<std::string> names{"Must","Feh","Pat"};

    for (const auto& name : names){
        std::cout << name << "\n";
    }

    std::vector<int> myItems(max_items);
    myItems[sword] = 5;
    myItems[potion] = 10;
    myItems[armor] = 9;

    std::cout << myItems[sword] << '\n';

    std::vector<int> cappedVector{};
    std::cout << cappedVector.size() << " " << cappedVector.capacity() << '\n';

    cappedVector.reserve(8);
    std::cout << cappedVector.size() << " " << cappedVector.capacity() << '\n';

    cappedVector.resize(5);
    std::cout << cappedVector.size() << " " << cappedVector.capacity() << '\n';


    std::vector<int> pushVector{};
    pushVector.push_back(100);
    pushVector.push_back(200);
    pushVector.push_back(300);
    std::cout << pushVector.back() << '\n';
    pushVector.pop_back();
    std::cout << pushVector.back() << '\n';

    std::vector<bool> hasShield{true,false};
    hasShield[0] = false;
    for (auto flag : hasShield)
    {
        std::cout << flag << '\n';
    }
    

    return 0;
}

