#ifndef STACK_H_
#define STACK_H_

// C program for linked list implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "../core/type.h"

typedef struct bf_stacknode_t bf_stacknode_t;

// A structure to represent a stack
struct bf_stacknode_t {
	bf_ptr_t data;
	bf_stacknode_t* next;
};

bf_stacknode_t* bf_stack_new_node(bf_ptr_t data);
bf_ptr_t bf_stack_is_empty(bf_stacknode_t* root);
void bf_stack_push(bf_stacknode_t** root, bf_ptr_t data);
bf_ptr_t bf_stack_pop(bf_stacknode_t** root);
bf_ptr_t bf_stack_peek(bf_stacknode_t* root);

#endif //  STACK_H_

