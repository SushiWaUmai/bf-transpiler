#include "./core.h"

// Initialize a brainfuck transpiler
// f - output stream
bf_t *bf_init(FILE *f)
{
    bf_t *bf = (bf_t *)malloc(sizeof(bf_t));
    bf->output = f;
    bf->stack_ptr = MEMORY_SIZE;
    bf->current_ptr = 0;
    bf->stack = NULL;
    return bf;
}

// Terminate a brainfuck transpiler
void bf_terminate(bf_t *bf)
{
    free(bf);
}
