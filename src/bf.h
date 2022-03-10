#ifndef BF_H_
#define BF_H_

#define MEMORY_SIZE 30000
#define INT_ENOUGH 10

#include <stdio.h>
#include "./stack.h"

typedef char bf_cell_t;
typedef int bf_ptr_t;

typedef struct {
    FILE *output;
    bf_ptr_t current_ptr;
    bf_ptr_t stack_ptr;
    bf_cell_t memory[MEMORY_SIZE];
    StackNode *stack;
} bf_t;

bf_t*       bf_init(FILE *output);
void        bf_terminate(bf_t *bf);

void        bf_write(bf_t *bf, bf_cell_t c, bf_ptr_t n);
void        bf_shift_ptr(bf_t *bf, bf_ptr_t way);
void        bf_move_ptr(bf_t *bf, bf_ptr_t target);
void        bf_clear_value(bf_t *b, bf_ptr_t target);

void        bf_update_memory(bf_t *bf, bf_cell_t value, bf_ptr_t target);
void        bf_cpy_value(bf_t *bf, bf_ptr_t src, bf_ptr_t dst);
void        bf_cpy_buffer(bf_t *bf, bf_ptr_t src, bf_ptr_t dst, bf_ptr_t len);
void        bf_set_value(bf_t *bf, bf_cell_t value, bf_ptr_t target);
void        bf_add_value(bf_t *bf, bf_cell_t value, bf_ptr_t target);
void        bf_sub_value(bf_t *bf, bf_cell_t value, bf_ptr_t target);

void        bf_print_ascii(bf_t *bf, bf_ptr_t pos);
void        bf_print_buffer(bf_t *bf, bf_ptr_t pos, bf_ptr_t len);
void        bf_print_number(bf_t *bf, bf_ptr_t pos);

bf_ptr_t    bf_allocate_stack(bf_t *bf, bf_ptr_t size);
bf_ptr_t    bf_create_buffer(bf_t *bf, bf_cell_t* str, bf_ptr_t len);

void        bf_open_scope(bf_t *f);
void        bf_close_scope(bf_t *f);

void        bf_output_simulated_memory(bf_t *bf, FILE *output);

#endif // BF_H_
