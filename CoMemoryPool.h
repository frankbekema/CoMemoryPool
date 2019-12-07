#ifndef CO_MEMORY_H
#define CO_MEMORY_H

#include <exception>

struct out_of_blocks : public std::exception {
    const char *what() const throw() {
        return "There is no memory block left in this pool";
    }
};

struct not_enough_memory : public std::exception {
    const char *what() const throw() {
        return "The block doesn't have enough memory";
    }
};

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

    //Methods
    void assignMemoryBlocks();
public: 
    MemoryBlock* freeMemoryBlocks = nullptr;
    MemoryBlock* usedMemoryBlocks = nullptr;

    //Constructor
    CoMemoryPool(unsigned int size, int blockAmount);
    ~CoMemoryPool();

    //Methods
    void* alloc(unsigned int size);
    void free(void* address);
};

#endif