#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MEMORY_SIZE 30000

int current_pos = 0;
int stack_pointer = MEMORY_SIZE;

void bf_move(FILE* f, int target_pos) {
    int way = target_pos - current_pos;
    char dir;

    if (way == 0)
        return;
    else if (way > 0) 
        dir = '>';
    else 
        dir = '<';

    for (int i = 0; i < abs(way); i++) {
        fputc(dir, f);
    }

    current_pos = target_pos;
}

void bf_update_info(FILE* f, char value) {
    for(int i = 0; i < value; i++) {
        fputc('+', f);
    }
}

void bf_print_str(FILE* f, int pos, int len) {
    bf_move(f, pos);
    for(int i = 0; i < len; i++) {
        fputc('.', f);
        fputc('>', f);
    }
    current_pos += len;
}

int bf_allocate_stack(int size) {
    stack_pointer -= size;
    return stack_pointer;
}

int bf_create_buffer(FILE* f, char info) {
    int pos = bf_allocate_stack(1);
    bf_move(f, pos);
    bf_update_info(f, info);
    return pos;
}

int bf_create_buffer_str(FILE* f, char* str, int len) {
    int pos = bf_allocate_stack(len);
    for (int i = len; i >= 0; i--) {
        bf_move(f, pos + i);
        bf_update_info(f, str[i]);
    }
    return pos;
}

int main(void) {
    FILE* f = fopen("output.bf", "w");

    int pos = bf_create_buffer_str(f, "Hello, World!\n", 14);
    int test = bf_create_buffer_str(f, "This is a test", 14);
    // printf("%d\n", pos);
    // printf("%d\n", test);
    bf_print_str(f, pos, 14);
    bf_print_str(f, test, 14);

    fclose(f);
}

