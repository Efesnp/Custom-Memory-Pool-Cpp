#include <iostream>
#include "MemoryAllocator.hpp"

int main() {
    
    MemoryPool pool(64, 10);

    void* adres = pool.allocate();
    std::cout << "Bellek adresi alindi: " << adres << std::endl;

    pool.deallocate(adres);
    std::cout << "Islem basariyla tamamlandi!" << std::endl;

    return 0;
}
