#ifndef BF_PRINT_H_
#define BF_PRINT_H_

#include "./core.h"

void        bf_print_ascii_l(bf_t *bf, bf_ptr_t pos);
void        bf_print_ascii_r(bf_t *bf, bf_cell_t val);
void        bf_print_ascii_buffer_l(bf_t *bf, bf_ptr_t pos, bf_ptr_t len);
void        bf_print_ascii_buffer_r(bf_t *bf, bf_cell_t* val, bf_ptr_t len);
void        bf_print_digit_l(bf_t *bf, bf_ptr_t pos);
void        bf_print_digit_r(bf_t *bf, bf_cell_t val);

#endif // BF_PRINT_H_

