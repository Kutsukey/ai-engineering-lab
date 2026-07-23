#include <iostream>

class Base
{
private:
    /* data */
public:
    Base(/* args */);
    virtual ~Base();
    virtual void speak();
};

Base::Base(/* args */)
{
}

Base::~Base()
{
    std::cout << "Base destroyed" << '\n';
}

void Base::speak()
{
    std::cout << "Base speaking" << '\n';
}

class Derived : public Base
{
private:
    int *m_data;

public:
    Derived(/* args */);
    ~Derived();
    void speak() override
    {
        std::cout << "Derived speaking" << '\n';
    }
};

Derived::Derived()
{
    m_data = new int[100];
}

Derived::~Derived()
{
    std::cout << "Derived destroyed and memory cleared" << '\n';
}

int main()
{
    Base* ptr = new Derived();
    ptr->speak();
    delete ptr;
    
    return 0;
}