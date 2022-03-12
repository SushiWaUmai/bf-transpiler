#ifndef BF_LOOP_H_
#define BF_LOOP_H_

#include "./core.h"

void        bf_start_loop(bf_t *bf);
void        bf_stop_loop(bf_t *bf);
bf_ptr_t    bf_start_for_loop_r(bf_t *bf, bf_cell_t iterations);
bf_ptr_t    bf_start_for_loop_l(bf_t *bf, bf_ptr_t iterator);
void        bf_stop_for_loop(bf_t *bf, bf_ptr_t iterator);

#endif // BF_LOOP_H_