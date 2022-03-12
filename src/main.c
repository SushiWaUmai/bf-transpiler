#include "bf.h"

int main(void)
{
    FILE *bf_output = fopen("output.bf", "w");
    bf_t *bf = bf_init(bf_output);

    bf_open_scope(bf);
    {
        bf_open_scope(bf);
        {
            bf_ptr_t test = bf_create_buffer(bf, "This is a test\n", 15);
            bf_print_buffer(bf, test, 15);
        }

        bf_close_scope(bf);
        bf_ptr_t pos = bf_create_buffer(bf, "Hello, World!\n", 14);
        bf_ptr_t test2 = bf_create_buffer(bf, "This is another test\n", 21);
        bf_ptr_t test3 = bf_allocate_stack(bf, 14);
        bf_cpy_buffer(bf, pos, test3, 14);

        bf_print_buffer(bf, pos, 14);
        bf_print_buffer(bf, test2, 21);
        bf_print_buffer(bf, test3, 14);
    }
    bf_close_scope(bf);

    bf_open_scope(bf);
    {
        bf_ptr_t pos = bf_create_buffer(bf, "yesyesyesyesyes\n", 16);

        bf_print_buffer(bf, pos, 16);

        // char val = 10;
        // bf_ptr_t num_ptr = bf_create_buffer(bf, &val, 1);

        // bf_print_number(bf, num_ptr);
    }
    bf_close_scope(bf);

    fclose(bf_output);
    bf_terminate(bf);
}
