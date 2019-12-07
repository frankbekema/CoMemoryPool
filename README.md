# CoMemoryPool
A memory pool with support for c++ and the Arduino IDE

## Usage
This sections describes how to use the library

### C++
To use this library with C++ you need to copy all the files in the CoMemoryPool to your C++ working directory. From there on you should be able to include the library by including "CoMemoryPool.h"

### Arduino
To use this library for arduino copy the "CoMemoryPool" folder to your Arduino libraries directory. From there on you should be able to include it with <CoMemoryPool.h>



## Example
```C
#include <iostream>

#include "CoMemoryPool.h"

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

## License
This project is licensed under the [MIT license](https://opensource.org/licenses/MIT)

## Questions?
If you have any questions feel free to contact Frank Bekema on frankbekema10@gmail.com or open up an issue.
