#include <iostream>
#include "MemoryAllocator.hpp"

int main() {
    // 64 byte'lik 10 yer ayiriyoruz. 9800X3D icin cocuk oyuncagi!
    MemoryPool pool(64, 10);

    void* adres = pool.allocate();
    std::cout << "Bellek adresi alindi: " << adres << std::endl;

    pool.deallocate(adres);
    std::cout << "Islem basariyla tamamlandi!" << std::endl;

    return 0;
}