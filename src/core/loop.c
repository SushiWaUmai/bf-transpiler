#include "./loop.h"
#include "./memory.h"
#include "./instruction.h"

void bf_start_loop(bf_t *bf)
{
    fputc('[', bf->output);
}

void bf_stop_loop(bf_t *bf)
{
    fputc(']', bf->output);
}

bf_ptr_t bf_start_for_loop_r(bf_t *bf, bf_cell_t iterations)
{
    bf_open_scope(bf);
    bf_start_loop(bf);
    bf_ptr_t i = bf_create_value(bf, iterations);
    bf_move_ptr(bf, i);

    return i;
}

bf_ptr_t bf_start_for_loop_l(bf_t *bf, bf_ptr_t iterator)
{
    bf_open_scope(bf);
    bf_start_loop(bf);
    bf_ptr_t i = bf_allocate_stack(bf, 1);
    bf_cpy_value(bf, iterator, i);
    bf_move_ptr(bf, i);

    return i;
}

void bf_stop_for_loop(bf_t *bf, bf_ptr_t iterator)
{
    bf_sub_value_r(bf, 1, iterator);
    bf_stop_loop(bf);
    bf_close_scope(bf);
}
