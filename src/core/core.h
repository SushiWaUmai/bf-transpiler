#ifndef BF_CORE_H_
#define BF_CORE_H_

#include <stdio.h>
#include "../utils/stack.h"

#define MEMORY_SIZE 30000
#define INT_ENOUGH ((CHAR_BIT*sizeof(int)-1)*10/33+3)

typedef char bf_cell_t;
typedef int bf_ptr_t;

typedef struct {
    FILE *output;
    bf_ptr_t current_ptr;
    bf_ptr_t stack_ptr;
    StackNode *stack;
} bf_t;

bf_t*       bf_init(FILE *output);
void        bf_terminate(bf_t *bf);

#endif // BF_CORE_H_