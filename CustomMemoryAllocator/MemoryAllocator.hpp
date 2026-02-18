#ifndef MEMORY_ALLOCATOR_HPP
#define MEMORY_ALLOCATOR_HPP
#include <iostream>
#include <vector>

class MemoryPool {
private:
    size_t m_blockSize;
    void* m_poolStart;
    std::vector<void*> m_freeBlocks;

public:
    MemoryPool(size_t blockSize, size_t numBlocks) : m_blockSize(blockSize) {
        m_poolStart = std::malloc(blockSize * numBlocks);
        for (size_t i = 0; i < numBlocks; ++i) {
            m_freeBlocks.push_back(static_cast<char*>(m_poolStart) + (i * blockSize));
        }
        std::cout << "Bellek Havuzu Olusturuldu: " << (blockSize * numBlocks) << " byte.\n";
    }
    ~MemoryPool() { std::free(m_poolStart); std::cout << "Havuz Temizlendi.\n"; }

    void* allocate() {
        if (m_freeBlocks.empty()) return nullptr;
        void* ptr = m_freeBlocks.back();
        m_freeBlocks.pop_back();
        return ptr;
    }
    void deallocate(void* ptr) { m_freeBlocks.push_back(ptr); }
};
#endif