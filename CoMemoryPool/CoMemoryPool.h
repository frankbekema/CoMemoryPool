#ifndef CO_MEMORY_H
#define CO_MEMORY_H

class CoMemoryPool {
private:
    //Struct
    struct MemoryBlock {
        MemoryBlock* next;
        MemoryBlock* prev;
    };

    //Variables
    void* memoryPool;
    const unsigned int memorySize;
    const unsigned int blockSize;
    const int blockAmount;
    MemoryBlock* freeMemoryBlocks = nullptr;
    MemoryBlock* usedMemoryBlocks = nullptr;

    //Methods
    void assignMemoryBlocks();
public: 
    //Constructor
    CoMemoryPool(unsigned int size, int blockAmount);
    ~CoMemoryPool();

    //Methods
    void* alloc(unsigned int size);
    void free(void* address);
};

#endif