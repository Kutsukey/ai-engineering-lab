#include <iostream>
#include <string>

template <typename T, std::size_t Size>
class FixedArray
{
private:
    T m_array[Size];

public:
    T &operator[](std::size_t index)
    {
        return m_array[index];
    }

    const T &operator[](std::size_t index) const
    {
        return m_array[index];
    }

    constexpr std::size_t getSize() const
    {
        return Size;
    }

    FixedArray()
    {
    }

    ~FixedArray()
    {
    }
};

template <typename T>
class Formatter
{
private:
    T m_data;

public:
    Formatter(T data) : m_data{data}
    {
    }
};

template <>
class Formatter<const char *>
{
private:
    const char *m_data;

public:
    Formatter(const char *data) : m_data(data)
    {
    }
    void format()
    {
        std::cout << "String Data: \"" << m_data << "\"" << '\n';
    }
};

template <typename T>
class ValueHolder
{
private:
    T m_val;

public:
    ValueHolder(T value) : m_val(value) {}
    void print()
    {
        std::cout << m_val << '\n';
    }
};

template <typename T>
class ValueHolder<T*>
{
private:
    T *m_ptr;

public:
    ValueHolder(T *value) : m_ptr(value) {}
    void print()
    {
        if (m_ptr)
            std::cout << *m_ptr << '\n';
        else
            std::cout << "nullptr" << '\n';
    }
};

int main()
{
    FixedArray<int, 5> arr_int{};
    arr_int[0] = 79;
    std::cout << "arr_int[0]: " << arr_int[0] << '\n';

    FixedArray<std::string, 3> arr_string{};
    arr_string[0] = "Kilis";

    std::cout << "arr_string[0]: " << arr_string[0] << '\n';

    Formatter<int> f1{100};
    Formatter<const char *> f2("C++ 26");
    f2.format();

    ValueHolder<int> v1{06};
    int x{100};
    ValueHolder<int*> v2{&x};
    v2.print();

    return 0;
}
