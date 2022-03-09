#include "./bf.h"

#include <stdlib.h>
#include <math.h>
#include <memory.h>

bf_t *bf_init(FILE *f) {
    bf_t* bf = (bf_t *)malloc(sizeof(bf_t));
    bf->output = f;
    bf->stack_ptr = MEMORY_SIZE;
    bf->current_ptr = 0;
    bf->stack = NULL;
    return bf;
}

void bf_terminate(bf_t *bf) {
    free(bf);
}

void bf_write(bf_t *bf, bf_cell_t c, bf_ptr_t n) {
    bf_cell_t* to_write = (bf_cell_t *)malloc(sizeof(bf_cell_t) * n);
    memset(to_write, c, n);
    fwrite(to_write, sizeof(bf_cell_t), n, bf->output);
    free(to_write);
}

void bf_shift(bf_t *bf, bf_ptr_t way) {
    bf_cell_t dir;
    if (way == 0)
        return;
    else if (way > 0) 
        dir = '>';
    else 
        dir = '<';

    bf_write(bf, dir, abs(way));

    bf->current_ptr+= way;
}

void bf_clear_value(bf_t *bf) {
    fprintf(bf->output, "[-]");
}

void bf_move(bf_t *bf, bf_ptr_t target_pos) {
    bf_ptr_t way = target_pos - bf->current_ptr;
    bf_shift(bf, way);
}

void bf_set_value(bf_t *bf, bf_cell_t value) {
    bf_clear_value(bf);
    bf_write(bf, '+', value);
}

void bf_add_value(bf_t *bf, bf_cell_t value) {
    bf_write(bf, '+', value);
}

void bf_sub_value(bf_t *bf, bf_cell_t value) {
    bf_write(bf, '-', value);
}

void bf_print_ascii(bf_t *bf, bf_ptr_t pos) {
    bf_move(bf, pos);
    fputc('.', bf->output);
}

void bf_print_str(bf_t *bf, bf_ptr_t pos, bf_ptr_t len) {
    bf_move(bf, pos);
    for(bf_ptr_t i = 0; i < len; i++) 
        bf_print_ascii(bf, pos + i);
}

bf_ptr_t bf_allocate_stack(bf_t *bf, bf_ptr_t size) {
    bf->stack_ptr -= size;
    bf_ptr_t scope_size = pop(&bf->stack);
    push(&bf->stack, scope_size + size);
    return bf->stack_ptr;
}

void bf_open_scope(bf_t *bf) {
    push(&bf->stack, 0);
}

void bf_close_scope(bf_t *bf) {
    bf_ptr_t scope_size = pop(&bf->stack);
    bf->stack_ptr += scope_size;
}

bf_ptr_t bf_create_buffer(bf_t *bf, bf_cell_t info) {
    bf_ptr_t pos = bf_allocate_stack(bf, 1);
    bf_move(bf, pos);
    bf_set_value(bf, info);
    return pos;
}

bf_ptr_t bf_create_buffer_str(bf_t *bf, bf_cell_t* str, bf_ptr_t len) {
    bf_ptr_t pos = bf_allocate_stack(bf, len);
    for (bf_ptr_t i = len - 1; i >= 0; i--) {
        bf_move(bf, pos + i);
        bf_set_value(bf, str[i]);
    }
    return pos;
}
