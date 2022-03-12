#include "./stack.h"

StackNode *new_node(int data)
{
    StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int is_empty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, int data)
{
    StackNode *stackNode = new_node(data);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(StackNode **root)
{
    if (is_empty(*root))
        return INT_MIN;
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode *root)
{
    if (is_empty(root))
        return INT_MIN;
    return root->data;
}
