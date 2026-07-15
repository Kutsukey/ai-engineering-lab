#include <iostream>
#include <string>
using namespace std::string_literals; // "s" koyabilmek için

struct GPU{ // Teorik toplam 45 byte ama bool 1+3'e yuvarlanmış (padding) reel 48 byte
    std::string name {"Generic GPU"}; // 32
    int vram {8}; // 4
    bool rtx_on {false}; // 1
    double price {99.9}; //8
};

void printGPU(const GPU& gpu){
    std::cout << gpu.name << " (" << gpu.vram << "GB)" << '\n';
}

void printGPUPtr(const GPU* gpuPtr){
    std::cout << gpuPtr->name << " (" << gpuPtr->vram << "GB)" << '\n';
}

GPU getUpgradedGPU(const GPU& gpu, int new_vram){
    GPU upgraded {gpu};
    upgraded.vram = new_vram;
    return upgraded;
}

struct PC
{
    std::string cpu;
    GPU gpu;
};

template <typename T /*,typename U*/>
struct Box
{
    T value;
    // U another_value;
};

using StringBox = Box<std::string>;

int main(){
    GPU myCard;

    myCard.name = "RTX 5060 Ti";
    myCard.vram = 16;
    myCard.rtx_on = true;
    myCard.price = 399.0;

    GPU otherCard {
        "RX 580", 8, false, 100
    };

    GPU anotherCard {
        .name = "ARC b580",
        .vram = 12,
        .rtx_on = false,
        .price = 250.0
    };

    GPU defaultCard {};
    std::cout << defaultCard.name << " " <<
     defaultCard.price << " " << defaultCard.rtx_on << " " << defaultCard.price << '\n';

    printGPU(myCard);
    printGPU(getUpgradedGPU(myCard,32));

    std::cout << sizeof(GPU) << '\n';

    PC my_pc {.cpu="7500f",.gpu=myCard};
    std::cout << my_pc.cpu << " " << my_pc.gpu.name << '\n';

    printGPUPtr(&myCard);

    Box<int> intBox {11};
    Box<std::string> stringBox { "Cruel Box"s };

    Box boolBox {true};

    StringBox newStringBox { "Lovely Box"s };

    std::cout << intBox.value << " " << stringBox.value << " " << boolBox.value << " " << newStringBox.value << '\n';

    return 0;
}