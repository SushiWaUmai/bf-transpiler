#include "./instruction.h"
#include "./memory.h"
#include "./loop.h"

// Clear the value at the current pointer
// The same as bf_set_value(bf, 0, target)
void bf_clear_value(bf_t *bf, bf_ptr_t target)
{
    bf_move_ptr(bf, target);
    fprintf(bf->output, "[-]");
}

// Set the value at the current pointer
// value - value to set the memory with
void bf_set_value(bf_t *bf, bf_cell_t value, bf_ptr_t target)
{
    bf_clear_value(bf, target);
    bf_add_value_r(bf, value, target);
}

// Add a value to the value at the current pointer
// value - value to add to the memory
void bf_add_value_r(bf_t *bf, bf_cell_t value, bf_ptr_t target)
{
    bf_move_ptr(bf, target);
    bf_write(bf, '+', value);
}

bf_ptr_t bf_add_values(bf_t *bf, bf_ptr_t a, bf_ptr_t b)
{
    bf_ptr_t target = bf_allocate_stack(bf, 1);
    bf_clear_value(bf, target);

    {
        bf_ptr_t iterator = bf_start_for_loop_l(bf, a);
        bf_add_value_r(bf, 1, target);
        bf_stop_for_loop(bf, iterator);
    }

    {
        bf_ptr_t iterator = bf_start_for_loop_l(bf, b);
        bf_add_value_r(bf, 1, target);
        bf_stop_for_loop(bf, iterator);
    }

    return target;
}

// Subtract a value from the value at the current pointer
// value - value to subtract from the memory
void bf_sub_value_r(bf_t *bf, bf_cell_t value, bf_ptr_t target)
{
    bf_move_ptr(bf, target);
    bf_write(bf, '-', value);
}

