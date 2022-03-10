#include "./bf.h"

// Initialize a brainfuck transpiler
// f - output stream
bf_t *bf_init(FILE *f)
{
    bf_t *bf = (bf_t *)malloc(sizeof(bf_t));
    bf->output = f;
    bf->stack_ptr = MEMORY_SIZE;
    bf->current_ptr = 0;
    bf->stack = NULL;
    memset(bf->memory, 0, MEMORY_SIZE);
    return bf;
}

// Terminate a brainfuck transpiler
void bf_terminate(bf_t *bf)
{
    free(bf);
}

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

// Clear the value at the current pointer
void bf_clear_value(bf_t *bf, bf_ptr_t target)
{
    bf_move_ptr(bf, target);
    fprintf(bf->output, "[-]");
}

bf_cell_t bf_read_memory(bf_t *bf, bf_ptr_t target)
{
    return bf->memory[target];
}

// Update the memory simuation on the current pointer
// value - value to update the memory with
void bf_update_memory(bf_t *bf, bf_cell_t value, bf_ptr_t target)
{
    bf->memory[target] = value;
}

// Set the value at the current pointer
// value - value to set the memory with
void bf_set_value(bf_t *bf, bf_cell_t value, bf_ptr_t target)
{
    bf_clear_value(bf, target);
    bf_add_value(bf, value, target);
}

// Copy the value at src to dst
// src - source position
// dst - destination position
void bf_cpy_value(bf_t *bf, bf_ptr_t src, bf_ptr_t dst)
{
    bf_set_value(bf, bf_read_memory(bf, src), dst);
}

// Copy the buffer at src to dst
// src - source position
// dst - destination position
// len - length of the buffer
void bf_cpy_buffer(bf_t *bf, bf_ptr_t src, bf_ptr_t dst, bf_ptr_t len)
{
    for (bf_ptr_t i = 0; i < len; i++)
        bf_cpy_value(bf, src + i, dst + i);
}

// Add a value to the value at the current pointer
// value - value to add to the memory
void bf_add_value(bf_t *bf, bf_cell_t value, bf_ptr_t target)
{
    bf_move_ptr(bf, target);
    bf_write(bf, '+', value);
    bf_update_memory(bf, value, target);
}

// Subtract a value from the value at the current pointer
// value - value to subtract from the memory
void bf_sub_value(bf_t *bf, bf_cell_t value, bf_ptr_t target)
{
    bf_move_ptr(bf, target);
    bf_write(bf, '-', value);
    bf_update_memory(bf, value, target);
}

// Print the ASCII value of the value at the current pointer
// pos - position to print the ASCII value of
void bf_print_ascii(bf_t *bf, bf_ptr_t pos)
{
    bf_move_ptr(bf, pos);
    fputc('.', bf->output);
}

// Print the digit value of the value at the current pointer
// pos - position to print the digit value of
void bf_print_digit(bf_t *bf, bf_ptr_t pos)
{
    bf_add_value(bf, '0', pos);
    bf_print_ascii(bf, bf->current_ptr);
    bf_sub_value(bf, '0', pos);
}

// Print a digit value of the value at the current pointer
// pos - position to print the digit value of
void bf_print_number(bf_t *bf, bf_ptr_t pos)
{
    bf_open_scope(bf);
    bf_cell_t num = bf_read_memory(bf, pos);

    static char num_str[INT_ENOUGH];
    sprintf(num_str, "%d", num);

    bf_ptr_t str_ptr = bf_create_buffer(bf, num_str, INT_ENOUGH);
    bf_print_buffer(bf, str_ptr, INT_ENOUGH);

    bf_close_scope(bf);
}

// Print a buffer in ascii to the output stream
// str - string to print
// len - length of the string
void bf_print_buffer(bf_t *bf, bf_ptr_t pos, bf_ptr_t len)
{
    bf_move_ptr(bf, pos);
    for (bf_ptr_t i = 0; i < len; i++)
        bf_print_ascii(bf, pos + i);
}

// Allocate memory on the stack
// size - size of the memory to allocate
bf_ptr_t bf_allocate_stack(bf_t *bf, bf_ptr_t size)
{
    bf->stack_ptr -= size;
    bf_ptr_t scope_size = pop(&bf->stack);
    push(&bf->stack, scope_size + size);
    return bf->stack_ptr;
}

// Open a scope on the stack
void bf_open_scope(bf_t *bf)
{
    push(&bf->stack, 0);
}

// Close a scope on the stack and deallocate scope
void bf_close_scope(bf_t *bf)
{
    bf_ptr_t scope_size = pop(&bf->stack);
    bf->stack_ptr += scope_size;
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

// Print the simulated memory
// output - output stream to print to
void bf_output_simulated_memory(bf_t *bf, FILE *output)
{
    fwrite(bf->memory, sizeof(bf_cell_t), MEMORY_SIZE, output);
}
