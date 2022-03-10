#include "bf.h"

int main(void)
{

    bf_t *bf = bf_init(stdout);

    bf_open_scope(bf);
    {
        bf_open_scope(bf);
        {
            bf_ptr_t test   = bf_create_buffer(bf, "This is a test\n", 15);
            bf_print_buffer(bf, test,  15);
        }

        bf_close_scope(bf);
        bf_ptr_t pos    = bf_create_buffer(bf, "Hello, World!\n", 14);
        bf_ptr_t test2  = bf_create_buffer(bf, "This is another test\n", 21);
        bf_ptr_t test3  = bf_allocate_stack(bf, 14);
        bf_cpy_buffer(bf, pos, test3, 14);

        bf_print_buffer(bf, pos,   14);
        bf_print_buffer(bf, test2, 21);
        bf_print_buffer(bf, test3, 14);
    }
    bf_close_scope(bf);

    bf_open_scope(bf);
    {
        bf_ptr_t pos = bf_create_buffer(bf, "yesyesyesyesyes", 15);

        bf_print_buffer(bf, pos, 15);
    }
    bf_close_scope(bf);

    FILE *f = fopen("output.bin", "wb");
    bf_output_simulated_memory(bf, f);
    fclose(f);


    bf_terminate(bf);
}
