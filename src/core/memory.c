#include "./memory.h"
#include "./instruction.h"

#include <string.h>

// Write multiple characters to the output stream
// c - character to write
// n - number of characters to write
void bf_write(bf_t *bf, bf_cell_t c, bf_ptr_t n)
{
    bf_cell_t *to_write = (bf_cell_t *)malloc(sizeof(bf_cell_t) * n);
    memset(to_write, c, n);
    fwrite(to_write, sizeof(bf_cell_t), n, bf->output);
    free(to_write);
}

// Shift the current pointer by a given amount
void bf_shift_ptr(bf_t *bf, bf_ptr_t way)
{
    bf_cell_t dir;
    if (way == 0)
        return;
    else if (way > 0)
        dir = '>';
    else
        dir = '<';

    bf_write(bf, dir, abs(way));

    bf->current_ptr += way;
}

// Move the current pointer to a given position
void bf_move_ptr(bf_t *bf, bf_ptr_t target_pos)
{
    bf_ptr_t way = target_pos - bf->current_ptr;
    bf_shift_ptr(bf, way);
}

// Allocate memory on the stack
// size - size of the memory to allocate
bf_ptr_t bf_allocate_stack(bf_t *bf, bf_ptr_t size)
{
    bf->stack_ptr -= size;
    bf_ptr_t scope_size = bf_stack_pop(&bf->stack);
    bf_stack_push(&bf->stack, scope_size + size);
    return bf->stack_ptr;
}

// Create an array on the stack
// str - array to create
bf_ptr_t bf_create_buffer(bf_t *bf, bf_cell_t *str, bf_ptr_t len)
{
    bf_ptr_t pos = bf_allocate_stack(bf, len);
    for (bf_ptr_t i = len - 1; i >= 0; i--)
    {
        bf_set_value(bf, str[i], pos + i);
    }
    return pos;
}

bf_ptr_t bf_create_value(bf_t *bf, bf_cell_t value)
{
    bf_ptr_t pos = bf_allocate_stack(bf, 1);
    bf_set_value(bf, value, pos);
    return pos;
}

// Open a scope on the stack
void bf_open_scope(bf_t *bf)
{
    bf_stack_push(&bf->stack, 0);
}

// Close a scope on the stack and deallocate scope
void bf_close_scope(bf_t *bf)
{
    bf_ptr_t scope_size = bf_stack_pop(&bf->stack);
    bf->stack_ptr += scope_size;
}