#ifndef BF_H_
#define BF_H_

#include "./core/core.h"
#include "./core/loop.h"
#include "./core/memory.h"
#include "./core/instruction.h"

void        bf_print_ascii(bf_t *bf, bf_ptr_t pos);
void        bf_print_buffer(bf_t *bf, bf_ptr_t pos, bf_ptr_t len);
void        bf_print_number(bf_t *bf, bf_ptr_t pos);

#endif // BF_H_
