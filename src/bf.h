#ifndef BF_H_
#define BF_H_

#define MEMORY_SIZE 30000

#include <stdio.h>
#include "./stack.h"

typedef struct {
    FILE *output;
    int current_ptr;
    int stack_ptr;
    StackNode *stack;
} BF;

BF*     bf_init(FILE *output);
void    bf_terminate(BF *bf);

void    bf_write(BF *bf, char c, int n);
void    bf_shift(BF *bf, int way);
void    bf_move(BF *bf, int target_pos);
void    bf_clear_value(BF *bf);

void    bf_set_value(BF *bf, char value);
void    bf_add_value(BF *bf, char value);
void    bf_sub_value(BF *bf, char value);

void    bf_print_str(BF *bf, int pos, int len);

int     bf_allocate_stack(BF *bf, int size);
int     bf_create_buffer(BF *bf, char info);
int     bf_create_buffer_str(BF *bf, char* str, int len);

void    bf_open_scope(BF *f);
void    bf_close_scope(BF *f);

#endif // BF_H_
