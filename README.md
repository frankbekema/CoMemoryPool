# CoMemoryPool
A memory pool with support for c++ and the Arduino  IDE

```C
#include <iostream>

#include "CoMemoryPool.hpp"

//Make a pool with 4 blocks of 256 bytes
CoMemoryPool memory(1024, 4);

int main() {
    //Get block
    void* block = memory.alloc(256);
    //Set data
    *((int*)block) = 5;
    //Displays : 5
    std::cout << *(int*)block << std::endl;  
    //Clear memory
    memory.free(block);
    //Displays : 0
    std::cout << *(int*)block << std::endl;  
    return 0;
}
```
