#include <array>
#include <iostream>
#include <string_view>
#include <functional>
#include <span>

using namespace std::string_literals;

template <typename T, auto N>
void printArray(const std::array<T, N> &arr)
{
    for (auto &&i : arr)
    {
        std::cout << i << '\n';
    }
}

struct Student
{
    int id;
    std::string_view name;
};

enum class StudentNames
{
    keny,
    kyle,
    stan,
    max_students
};

void printCSize(const int arr[]) // length yanında taşımak zorunda
{
    std::cout << "Fonksiyon icinde sizeof: " << sizeof(arr) << '\n';
}

void printElements(std::span<const int> arr) // std::span C-style ve std::array'leri güvenlice tutar
{
    for (auto &&i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << '\n'
              << arr.size() << '\n';
}

int main()
{
    constexpr std::array my_arr{9, 18, 24};
    std::array<int, 5> s_arr{};
    constexpr auto toChar_arr{std::to_array<char>({67, 65, 66})};
    std::cout << toChar_arr[1] << '\n';

    int my_arr_size = std::ssize(my_arr);
    std::cout << my_arr[2] << " " << std::get<2>(my_arr) << std::endl; // std::get<>() modern derleme zamanı
    // std::get<9>(my_arr); derlenirken hata fırlatıyor.

    printArray(my_arr);
    printArray(toChar_arr);

    constexpr std::array studs{Student{3, "Arf"}, Student{4, "Feh"}};
    constexpr std::array<Student, 2> students{{{1, "Must"}, {2, "Pato"}}};
    for (auto &&i : students)
    {
        std::cout << i.id << " Name: " << i.name << '\n';
    }

    int sayi1{10};
    int sayi2{20};
    std::array<std::reference_wrapper<int>, 2> ref_arr{sayi1, sayi2};
    std::array ref_arr2{std::ref(sayi1), std::ref(sayi2)};
    ref_arr[0].get() = 99;
    std::cout << sayi1 << '\n';
    for (auto &&i : ref_arr)
    {
        std::cout << i << " ";
    }

    constexpr std::array grades{75, 80, 95};
    static_assert(grades.size() == static_cast<size_t>(StudentNames::max_students)); // derleme sırası kontrol
    std::cout << std::get<static_cast<size_t>(StudentNames::stan)>(grades) << '\n';

    double bounds[]{2.2, 3.4, 5.6, 1.2};
    auto size_bounds = std::size(bounds);
    for (auto &&i : bounds)
    {
        std::cout << i << ", ";
    }
    std::cout << bounds[10] << std::endl; // UB, derleyici hata vermez neye erişirse o geliyor

    int nums[]{1, 2, 3, 4, 5, 6};
    printCSize(nums);
    std::cout << "main icindeki sizeof: " << sizeof(nums) << '\n';

    int data[]{100, 200, 300, 400};
    int *ptr{data};
    std::cout << *(ptr + 1) << " " << *(ptr + 2) << " " << *(ptr + 3) << " adress: " << ptr + 3 << "\n";

    char str[]{"CUDA"}; // 4 + 1 null = 5
    std::cout << std::size(str) << " " << sizeof(str) << '\n'
              << static_cast<int>(str[4]) << '\n';
    char *ptr_str{str};
    while (*ptr_str != '\0')
    {
        std::cout << *ptr_str;
        ptr_str++;
    }
    std::cout << std::endl;

    int matrix[2][3]{{10, 20, 30}, {40, 50, 60}};
    for (size_t i = 0; i < std::size(matrix); i++)
    {
        for (size_t j = 0; j < std::size(matrix[0]); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int *matrix_ptr{&matrix[0][0]};
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << *(matrix_ptr + i) << " ";
    }
    std::cout << std::endl;

    // index = (row x cols) + col
    int grid[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    constexpr int ROWS{3};
    constexpr int COLS{4};
    for (size_t r = 0; r < ROWS; r++)
    {
        for (size_t c = 0; c < COLS; c++)
        {
            std::cout << grid[(r * COLS) + c] << " ";
        }
        std::cout << '\n';
    }

    int c_arr[]{1, 5, 10};
    std::array<int, 3> cpp_arr{11, 12, 13};
    printElements(c_arr);
    printElements(cpp_arr);

    return 0;
}