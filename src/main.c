#include "bf.h"

int main(void)
{
    // FILE *f = fopen("output.bf", "w");

    bf_t *bf = bf_init(stdout);

    bf_open_scope(bf);
    {
        int pos     = bf_create_buffer_str(bf, "Hello, World!\n", 14);
        int test    = bf_create_buffer_str(bf, "This is a test\n", 15);
        int test2   = bf_create_buffer_str(bf, "This is another test\n", 21);

        bf_print_str(bf, pos,   14);
        bf_print_str(bf, test,  15);
        bf_print_str(bf, test2, 21);
    }
    bf_close_scope(bf);

    bf_open_scope(bf);
    {
        int pos = bf_create_buffer_str(bf, "yesyesyesyesyes", 15);

        bf_print_str(bf, pos, 15);
    }
    bf_close_scope(bf);

    bf_terminate(bf);
    // fclose(f);
}
