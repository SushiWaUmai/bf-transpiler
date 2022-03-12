#ifndef BF_INSTRUCTION_H_
#define BF_INSTRUCTION_H_

#include "./core.h"

void        bf_clear_value(bf_t *b, bf_ptr_t target);
void        bf_cpy_value(bf_t *bf, bf_ptr_t src, bf_ptr_t dst);
void        bf_cpy_buffer(bf_t *bf, bf_ptr_t src, bf_ptr_t dst, bf_ptr_t len);
void        bf_move_value(bf_t *bf, bf_ptr_t src, bf_ptr_t dst);
void        bf_move_buffer(bf_t *bf, bf_ptr_t src, bf_ptr_t dst, bf_ptr_t len);
void        bf_set_value(bf_t *bf, bf_cell_t value, bf_ptr_t target);
void        bf_add_value_r(bf_t *bf, bf_cell_t value, bf_ptr_t target);
void        bf_add_value_l(bf_t *bf, bf_ptr_t a, bf_ptr_t b);
void        bf_sub_value_r(bf_t *bf, bf_cell_t value, bf_ptr_t target);

#endif //  BF_INSTRUCTION_H_