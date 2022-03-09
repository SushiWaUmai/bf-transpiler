#include "./bf.h"

#include <stdlib.h>
#include <math.h>
#include <memory.h>

BF *bf_init(FILE *f) {
    BF* bf = (BF *)malloc(sizeof(BF));
    bf->output = f;
    bf->stack_ptr = MEMORY_SIZE;
    bf->current_ptr = 0;
    bf->stack = NULL;
    return bf;
}

void bf_terminate(BF *bf) {
    free(bf);
}

void bf_write(BF *bf, char c, int n) {
    char* to_write = (char *)malloc(sizeof(char) * n);
    memset(to_write, c, n);
    fwrite(to_write, sizeof(char), n, bf->output);
    free(to_write);
}

void bf_shift(BF *bf, int way) {
    char dir;
    if (way == 0)
        return;
    else if (way > 0) 
        dir = '>';
    else 
        dir = '<';

    bf_write(bf, dir, abs(way));

    bf->current_ptr+= way;
}

void bf_clear_value(BF *bf) {
    fprintf(bf->output, "[-]");
}

void bf_move(BF *bf, int target_pos) {
    int way = target_pos - bf->current_ptr;
    bf_shift(bf, way);
}

void bf_set_value(BF *bf, char value) {
    bf_clear_value(bf);
    bf_write(bf, '+', value);
}

void bf_add_value(BF *bf, char value) {
    bf_write(bf, '+', value);
}

void bf_sub_value(BF *bf, char value) {
    bf_write(bf, '-', value);
}

void bf_print_str(BF *bf, int pos, int len) {
    bf_move(bf, pos);
    for(int i = 0; i < len; i++) {
        fputc('.', bf->output);
        bf_shift(bf, 1);
    }
}

int bf_allocate_stack(BF *bf, int size) {
    bf->stack_ptr -= size;
    int scope_size = pop(&bf->stack);
    push(&bf->stack, scope_size + size);
    return bf->stack_ptr;
}

void bf_open_scope(BF *bf) {
    push(&bf->stack, 0);
}

void bf_close_scope(BF *bf) {
    int scope_size = pop(&bf->stack);
    bf->stack_ptr += scope_size;
}

int bf_create_buffer(BF *bf, char info) {
    int pos = bf_allocate_stack(bf, 1);
    bf_move(bf, pos);
    bf_set_value(bf, info);
    return pos;
}

int bf_create_buffer_str(BF *bf, char* str, int len) {
    int pos = bf_allocate_stack(bf, len);
    for (int i = len - 1; i >= 0; i--) {
        bf_move(bf, pos + i);
        bf_set_value(bf, str[i]);
    }
    return pos;
}

