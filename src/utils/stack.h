#ifndef STACK_H_
#define STACK_H_

// C program for linked list implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode StackNode;

// A structure to represent a stack
struct StackNode {
	int data;
	StackNode* next;
};

StackNode* new_node(int data);
int is_empty(StackNode* root);
void push(StackNode** root, int data);
int pop(StackNode** root);
int peek(StackNode* root);

#endif //  STACK_H_