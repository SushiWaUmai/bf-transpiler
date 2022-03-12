# Brainf**k Transpiler

Simple brainf**k transpiler written in C.

## Getting Started
Clone the repo
```bash
git clone https://github.com/SushiWaUmai/bf-transpiler.git
```

Generate the project using CMake
```bash
mkdir build && cd build
cmake ..
```

## Usage
Here is a simple example how to print the string "Hello, World!"

```C
#include "bf.h"

int main(void)
{
    // Create the output stream
    FILE *bf_output = fopen("output.bf", "w");
    
    // Initialize the brainf**k transpiler
    bf_t *bf = bf_init(bf_output);

    // Open a scope in the stack memory
    bf_open_scope(bf);
    {
        // allocate a buffer for the string and populate the buffer with "Hello, World!\n"
        bf_ptr_t hello_world_ptr = bf_create_buffer(bf, "Hello, World!\n", 14);
        bf_print_ascii_buffer_l(bf, hello_world_ptr, 14);
    }
    // Close the scope in the stack memory and free the memory
    bf_close_scope(bf);

    // Close the output stream
    fclose(bf_output);
    
    // Free the brainf**k transpiler
    bf_terminate(bf);
}
```

This code will generate a file named `output.bf` that will print the string `"Hello, World!"` in the brainf**k language.
 
