#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef void* elem_t;

typedef elem_t (*clone_t)(elem_t e);
typedef void (*destroy_t)(elem_t e);
typedef void (*print_t)(elem_t e);

typedef struct stack* Stack;

Stack stack_create(int max_size, clone_t clone, destroy_t destroy, print_t print);
int stack_destroy(Stack s);
int stack_push(Stack s, elem_t e);
void stack_pop(Stack s);
elem_t stack_peek(Stack s);
size_t stack_size(Stack s);
bool stack_is_empty(Stack s);
size_t stack_capacity(Stack s);
void stack_print(Stack s);

#endif
