#ifndef BF_CORE_H_
#define BF_CORE_H_

#include <stdio.h>
#include "./type.h"
#include "../utils/stack.h"

typedef struct {
    FILE *output;
    bf_ptr_t current_ptr;
    bf_ptr_t stack_ptr;
    bf_stacknode_t *stack;
} bf_t;

bf_t*       bf_init(FILE *output);
void        bf_terminate(bf_t *bf);

#endif // BF_CORE_H_