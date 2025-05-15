#include "stack.h"
#include <stdlib.h>

/**
 * @brief The stack struct
 * @param data the stack elemnts
 * @param top is the size of the strack
 * @param max_size is the maximum size of the strack
 * @param clone is a pointer to the clone function
 * @param destroy is a pointer to the destroy function
 * @param print is a pointer to the print function
 */
struct stack {
	elem_t* data;
	size_t top;
	size_t max_size;
	clone_t clone;
	destroy_t destroy;
	print_t print;
};

/**
 * @brief Creating a new stack
 * @param max_size Maximum size of the stack
 * @param clone is a pointer to the clone function
 * @param destroy is a pointer to the destroy function
 * @param print is a pointer to the print function
 * @return a pointer to the new stack
 */
Stack stack_create(size_t max_size, clone_t clone, destroy_t destroy ,print_t print){
	Stack s = malloc(sizeof(*s));
	if(!s)
		return NULL;
	s->data = malloc(sizeof(elem_t) * max_size);
	if(!s->data) {
	        free(s);
        	return NULL;
	}
 	s->top = 0;
	s->max_size = max_size;
	s->clone = clone;
	s->destroy = destroy;
	s->print = print;
	return s;
}

/**
 * @brief Destroy a stack
 * @param s Pointer to stack
 * @return 1 if the Fail, O is Success
 */
int stack_destroy(Stack s) {
	if(!s) return 1;
	for(size_t i = 0; i < s->top; ++i) {
		s->destroy(s->data[i]);
	}
	free(s->data);
	free(s);
	return 0;
}

/**
 * @brief Pushing a new element to the stack
 * @param s Pointer to stack
 * @param elem the element we want to push
 * @return 1 if the Fail, O is Success
 */
int stack_push(Stack s, elem_t elem) {
	if(!s || !elem || s->top == s->max_size) 
		return 1;
	elem_t copy = s->clone(elem);
	if(!copy) 
		return 1;
	s->data[s->top++] = copy;
	return 0;
}

/**
 * @brief taking out the last element in the stack
 * @param s Pointer to stack
 * @return nothing
 */
void stack_pop(Stack s) {
	if(!s || s->top == 0)
		return;
	s->destroy(s->data[--s->top]);
}

/**
 * @brief peeking to the last elent in the stack
 * @param s Pointer to stack
 * @return pointer to the last element in the stack
 */
elem_t stack_peek(Stack s) {
	if(!s || s->top == 0)
                return NULL;
        return s->data[s->top - 1];
}

/**
 * @brief the size of the stack
 * @param s Pointer to stack
 * @return the size of the stack
 */
size_t stack_size(Stack s) {
	return s ? s->top : 0;
}

/**
 * @brief checking if the stack is empty
 * @param s Pointer to stack
 * @return True if empty, False if it's not
 */
bool stack_is_empty(Stack s) {
	return s ? s->top ==0 : false;
}

/**
 * @brief how many more elemnts we can put
 * @param s Pointer to stack
 * @return the number of element keft to put until we at max size
 */
size_t stack_capacity(Stack s) {
	return s ? s->max_size - s->top : 0;
}

/**
 * @brief printing the stack from last to first
 * @param s Pointer to stack
 * @return nothing
 */
void stack_print(Stack s) {
	if(!s)
		return;
	for (size_t i = s->top; i > 0; --i) {
    		s->print(s->data[i - 1]);
	}
}

