#include "./print.h"
#include "./memory.h"
#include "./instruction.h"

// Print the ASCII value of the value at the current pointer
// pos - position to print the ASCII value of
void bf_print_ascii_l(bf_t *bf, bf_ptr_t pos)
{
    bf_move_ptr(bf, pos);
    fputc('.', bf->output);
}

// Print the digit value of the value at the current pointer
// pos - position to print the digit value of
void bf_print_digit_l(bf_t *bf, bf_ptr_t pos)
{
    bf_add_value_r(bf, '0', pos);
    bf_print_ascii_l(bf, bf->current_ptr);
    bf_sub_value_r(bf, '0', pos);
}

// Print a buffer in ascii to the output stream
// str - string to print
// len - length of the string
void bf_print_ascii_buffer_l(bf_t *bf, bf_ptr_t pos, bf_ptr_t len)
{
    bf_move_ptr(bf, pos);
    for (bf_ptr_t i = 0; i < len; i++)
        bf_print_ascii_l(bf, pos + i);
}

