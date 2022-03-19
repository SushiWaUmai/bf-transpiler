#include "bf.h"

int main(void)
{
    // Create the output stream
    FILE *bf_output = fopen("output.bf", "w");

    // Initialize the brainf**k transpiler
    bf_t *bf = bf_init(bf_output);

    bf_open_scope(bf);
    {
        bf_open_scope(bf);
        {
            bf_ptr_t test = bf_create_buffer(bf, (bf_cell_t *)"This is a test\n", 15);
            bf_print_ascii_buffer_l(bf, test, 15);
        }
        bf_close_scope(bf);

        bf_ptr_t pos = bf_create_buffer(bf, (bf_cell_t *)"Hello, World!\n", 14);
        bf_ptr_t test2 = bf_create_buffer(bf, (bf_cell_t *)"This is another test\n", 21);
        bf_ptr_t test3 = bf_allocate_stack(bf, 14);
        bf_cpy_buffer(bf, pos, test3, 14);

        bf_print_ascii_buffer_l(bf, pos, 14);
        bf_print_ascii_buffer_l(bf, test2, 21);
        bf_print_ascii_buffer_l(bf, test3, 14);
    }
    bf_close_scope(bf);

    bf_open_scope(bf);
    {
        bf_ptr_t num_ptr_1 = bf_create_value(bf, 6);
        bf_ptr_t op = bf_create_buffer(bf, (bf_cell_t *)" + ", 3);
        bf_ptr_t num_ptr_2 = bf_create_value(bf, 3);
        bf_ptr_t equal = bf_create_buffer(bf, (bf_cell_t *)" = ", 3);
        bf_ptr_t result = bf_add_values(bf, num_ptr_1, num_ptr_2);

        bf_print_digit_l(bf, num_ptr_1);
        bf_print_ascii_buffer_l(bf, op, 3);
        bf_print_digit_l(bf, num_ptr_2);
        bf_print_ascii_buffer_l(bf, equal, 3);
        bf_print_digit_l(bf, result);
    }
    bf_close_scope(bf);

    fclose(bf_output);
    bf_terminate(bf);
}
