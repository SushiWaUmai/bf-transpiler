#include "./stack.h"

bf_stacknode_t *bf_stack_new_node(bf_ptr_t data)
{
    bf_stacknode_t *stackNode = (bf_stacknode_t *)malloc(sizeof(bf_stacknode_t));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

bf_ptr_t bf_stack_is_empty(bf_stacknode_t *root)
{
    return !root;
}

void bf_stack_push(bf_stacknode_t **root, bf_ptr_t data)
{
    bf_stacknode_t *stackNode = bf_stack_new_node(data);
    stackNode->next = *root;
    *root = stackNode;
}

bf_ptr_t bf_stack_pop(bf_stacknode_t **root)
{
    if (bf_stack_is_empty(*root))
        return -1;
    bf_stacknode_t *temp = *root;
    *root = (*root)->next;
    bf_ptr_t popped = temp->data;
    free(temp);

    return popped;
}

bf_ptr_t bf_stack_peek(bf_stacknode_t *root)
{
    if (bf_stack_is_empty(root))
        return -1;
    return root->data;
}
