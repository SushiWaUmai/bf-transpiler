#ifndef BF_MEMORY_H_
#define BF_MEMORY_H_

#include "./core.h"

void        bf_write(bf_t *bf, bf_cell_t c, bf_ptr_t n);
void        bf_shift_ptr(bf_t *bf, bf_ptr_t way);
void        bf_move_ptr(bf_t *bf, bf_ptr_t target);

void        bf_cpy_value(bf_t *bf, bf_ptr_t src, bf_ptr_t dst);
void        bf_cpy_buffer(bf_t *bf, bf_ptr_t src, bf_ptr_t dst, bf_ptr_t len);

void        bf_move_value(bf_t *bf, bf_ptr_t src, bf_ptr_t dst);
void        bf_move_buffer(bf_t *bf, bf_ptr_t src, bf_ptr_t dst, bf_ptr_t len);

bf_ptr_t    bf_allocate_stack(bf_t *bf, bf_ptr_t size);
bf_ptr_t    bf_create_value(bf_t *bf, bf_cell_t value);
bf_ptr_t    bf_create_buffer(bf_t *bf, bf_cell_t* str, bf_ptr_t len);

void        bf_open_scope(bf_t *f);
void        bf_close_scope(bf_t *f);

#endif //  BF_MEMORY_H_

