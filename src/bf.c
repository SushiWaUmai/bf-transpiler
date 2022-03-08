#include "./bf.h"

#include <stdlib.h>
#include <math.h>
#include <memory.h>

BF *bf_init(FILE *f) {
    BF* bf = (BF *)malloc(sizeof(BF));
    bf->output = f;
    bf->stack_ptr = MEMORY_SIZE;
    bf->current_ptr = 0;
    return bf;
}

void bf_terminate(BF *bf) {
    free(bf);
}

void bf_write(BF *bf, char c, char n) {
    char* to_write = (char *)malloc(sizeof(char) * n);
    memset(to_write, c, n);
    fwrite(to_write, sizeof(char), n, bf->output);
    free(to_write);
}

void bf_shift(BF *f, int way) {
    char dir;
    if (way == 0)
        return;
    else if (way > 0) 
        dir = '>';
    else 
        dir = '<';

    bf_write(f, dir, abs(way));

    f->current_ptr+= way;
}

void bf_move(BF *f, int target_pos) {
    int way = target_pos - f->current_ptr;
    bf_shift(f, way);
}

void bf_add_value(BF *f, char value) {
    bf_write(f, '+', value);
}

void bf_sub_value(BF *f, char value) {
    bf_write(f, '-', value);
}

void bf_print_str(BF *f, int pos, int len) {
    bf_move(f, pos);
    for(int i = 0; i < len; i++) {
        fputc('.', f->output);
        bf_shift(f, 1);
    }
}

int bf_allocate_stack(BF *f, int size) {
    f->stack_ptr -= size;
    return f->stack_ptr;
}

int bf_create_buffer(BF *f, char info) {
    int pos = bf_allocate_stack(f, 1);
    bf_move(f, pos);
    bf_add_value(f, info);
    return pos;
}

int bf_create_buffer_str(BF *f, char* str, int len) {
    int pos = bf_allocate_stack(f, len);
    for (int i = len; i >= 0; i--) {
        bf_move(f, pos + i);
        bf_add_value(f, str[i]);
    }
    return pos;
}

