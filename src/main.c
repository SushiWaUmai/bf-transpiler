#include "bf.h"

int main(void) {
    FILE* f = fopen("output.bf", "w");

    BF* bf = bf_init(f);

    int pos = bf_create_buffer_str(bf, "Hello, World!\n", 14);
    int test = bf_create_buffer_str(bf, "This is a test", 14);

    bf_print_str(bf, pos, 14);
    bf_print_str(bf, test, 14);

    bf_terminate(bf);
    fclose(f);
}

