#include <iostream>
#include <utility>
#include <memory>

void myFunc(int &val)
{
    std::cout << "Bu L-value" << '\n';
}

void myFunc(int &&val)
{
    std::cout << "Bu R-value" << '\n';
}

class Holder
{
private:
    int *m_ptr;

public:
    Holder(int value);
    ~Holder();

    // Move constructor
    Holder(Holder &&source) noexcept : m_ptr{source.m_ptr}
    {
        source.m_ptr = nullptr;
        std::cout << "Move constructor" << '\n';
    }

    // Copy constructor
    Holder(const Holder &source) : m_ptr{new int(*source.m_ptr)}
    {
        std::cout << "Copy constructor" << '\n';
    }

    // Move assignment
    Holder &operator=(Holder &&source) noexcept
    {
        std::cout << "Move assignment" << '\n';
        if (this == &source)
        {
            return *this;
        }

        delete m_ptr;
        m_ptr = source.m_ptr;
        source.m_ptr = nullptr;
        return *this;
    }

    // Copy assignment
    Holder &operator=(const Holder &source)
    {
        std::cout << "Copy assignment" << '\n';
        if (this == &source)
            return *this;
        if (source.m_ptr == nullptr)

            return *this;

        delete m_ptr;
        m_ptr = new int(*source.m_ptr);
        return *this;
    }

    void print()
    {
        if (m_ptr != nullptr)
        {
            std::cout << m_ptr << '\n';
        }
        else
        {
            std::cout << "nullptr" << '\n';
        }
    }
};

Holder::Holder(int value) : m_ptr{new int(value)}
{
}

Holder::~Holder()
{
    delete m_ptr;
}

class Thrower
{
public:
    Thrower();
    ~Thrower();
    void doThrow()
    {
        std::cout << "Ben basit bir insanim." << '\n';
    }
};

Thrower::Thrower()
{
    std::cout << "Oluşturuldu." << '\n';
}

Thrower::~Thrower()
{
    std::cout << "Yok edildi." << '\n';
}

void fooThrow(std::unique_ptr<Thrower> ptr)
{
    ptr->doThrow();
}

class Node
{
private:
public:
    std::weak_ptr<Node> n_ptr;
    Node();
    ~Node();
};

Node::Node()
{
    std::cout << "Node " << this << " oluşturuldu" << '\n';
}

Node::~Node()
{
    std::cout << "Node " << this << " yok edildi" << '\n';
}

int main()
{
    int a{5};
    myFunc(a);
    myFunc(99);
    myFunc(5 + 15);

    Holder h1{100};
    Holder h2{200};

    h2 = h1;
    h1.print();
    h2.print();

    Holder h3 = std::move(h1);
    h2 = std::move(h3);
    h1.print();
    h2.print();
    h3.print();

    // std::unique_ptr<Thrower> ptr;
    auto ptr1 = std::make_unique<Thrower>();
    ptr1->doThrow();
    auto ptr2 = std::move(ptr1);
    fooThrow(std::move(ptr2));
    if (ptr1 == nullptr)
    {
        std::cout << "ptr1 nullptr" << '\n';
    }

    {
        auto n1 = std::make_shared<Node>();
        auto n2 = std::make_shared<Node>();
        n1->n_ptr = n2;
        n2->n_ptr = n1;

        if (auto shared_node = n1->n_ptr.lock())
            std::cout << shared_node << '\n';

        void* rawMemory = ::operator new(sizeof(Holder));
        Holder* holderPtr =  new (rawMemory) Holder(42);
        holderPtr->~Holder();
        ::operator delete(rawMemory);
    }
    return 0;
}