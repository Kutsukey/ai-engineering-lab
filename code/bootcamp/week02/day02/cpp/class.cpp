#include <iostream>
#include <string>
using namespace std::string_literals;

class Player
{ // private by default
private:
    int m_health_point;
    int m_damage_per_sec{5};
    std::string m_name;
    bool m_has_shield{false};
    bool m_on_ground{true};

public:
    static int s_playerCount;
    static int getPlayerCount();
    // Player(std::string name = "Generico", int health = 100); // Default argümanlar bildirimde
    Player();
    Player(std::string name);
    Player(std::string name, int health);
    ~Player();
    Player &takeDamage(int d);
    int getHealth() const; // parametrelerden sonra const
    Player &setHealth(int health);
    const std::string &getName() const; // const T& getX() const

    enum class State
    {
        Idle,
        Running,
        Jumping
    };
};

int Player::s_playerCount{};

Player::Player(std::string name, int health)
    : m_health_point{health}, // ":" member initializer list
      m_name{name}
{
    std::cout << "Constructor: " << m_name << '\n';
    ++s_playerCount;
}

Player::Player(std::string name) : Player{name, 100} {}

int Player::getPlayerCount()
{
    return s_playerCount;
}

Player::Player() : Player{"Generic Pl", 99} {}

const std::string &Player::getName() const
{
    return m_name;
}

Player::~Player()
{
    std::cout << "Destructor: " << m_name << '\n';
    --s_playerCount;
}

Player &Player::takeDamage(int damage)
{
    m_health_point -= damage;
    if (m_health_point < 0)
    {
        m_health_point = 0;
    }
    return *this;
}

int Player::getHealth() const // küçük tipler değer olarak
{
    return m_health_point;
}

Player &Player::setHealth(int health)
{
    if (health > 0)
    {
        m_health_point = health;
    }
    else
    {
        m_health_point = 0;
    }

    return *this;
}

int main()
{
    Player myPlayer{"Patiz", 150};
    myPlayer.setHealth(90);
    std::cout << myPlayer.getHealth() << '\n'
              << myPlayer.getName() << '\n';
    // myPlayer.health_point = 90;
    // myPlayer.damage_per_sec = 15;
    // myPlayer.has_shield = true;

    myPlayer.setHealth(90)
        .takeDamage(15);
    std::cout << myPlayer.getHealth() << std::endl;

    Player secondPlayer{"Kutsu", 500};
    secondPlayer.takeDamage(550);

    const Player thirdPlayer{"Random", 9999};
    thirdPlayer.getHealth();

    Player{"TemporaryPlayer", 33};

    std::cout << Player::getPlayerCount() << '\n'; // 3 çünkü Temporary oluştuğu an gitti geri.

    // std::cout << myPlayer.damage_per_sec << " " << secondPlayer.health_point << std::endl;
    return 0;
}

// template <typename T>
// class Box
// {
// private:
//     T m_value;

// public:
//     Box(T value) : m_value = value {}
//     T getValue()
//     {
//         return m_value;
//     }
// };