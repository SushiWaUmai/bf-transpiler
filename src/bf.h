#ifndef BF_H_
#define BF_H_

#define MEMORY_SIZE 30000

#include <stdio.h>
#include "./stack.h"

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

void        bf_write(bf_t *bf, bf_cell_t c, bf_ptr_t n);
void        bf_shift(bf_t *bf, bf_ptr_t way);
void        bf_move(bf_t *bf, bf_ptr_t target_pos);
void        bf_clear_value(bf_t *bf);

void        bf_set_value(bf_t *bf, bf_cell_t value);
void        bf_add_value(bf_t *bf, bf_cell_t value);
void        bf_sub_value(bf_t *bf, bf_cell_t value);

void        bf_prbf_ptr_t_value(bf_t *bf, bf_ptr_t pos);
void        bf_prbf_ptr_t_str(bf_t *bf, bf_ptr_t pos, bf_ptr_t len);

bf_ptr_t    bf_allocate_stack(bf_t *bf, bf_ptr_t size);
bf_ptr_t    bf_create_buffer(bf_t *bf, bf_cell_t info);
bf_ptr_t    bf_create_buffer_str(bf_t *bf, bf_cell_t* str, bf_ptr_t len);

void        bf_open_scope(bf_t *f);
void        bf_close_scope(bf_t *f);

#endif // BF_H_
