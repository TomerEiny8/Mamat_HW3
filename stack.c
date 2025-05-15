#include "stack.h"
#include <stdlib.h>

struct stack {
	elem_t* data;
	size_t top;
	size_t maxsize;
	clone_t clone;
	destroy_t destroy;
	print_t print;
};

Stack stack_create(size_t max_size, clone_t clone, destroy_t destroy print_t print){
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

int stack_destroy(Stack s) {
	if(!s) return 1;
	for(size_t i = 0; i < s->top; ++i) {
		s->destroy(s->data[i]);
	}
	free(s->data);
	free(s);
	return 0;
}

bool stack_push(Stack s, elem_t elem) {
	if(!s || s->top == s->max_size) 
		return 1;
	elem_t copy = s->clone(elem);
	if(!copy) 
		return 1;
	s->data[s->top++] = copy;
	return 0;
}

void stack_pop(Stack s) {
	if(!s || s->top == 0)
		return;
	s->destroy(s->data[--s->top]);
}

elem_t stack_peek(Stack s) {
	if(!s || s->top == 0)
                return NULL;
        return s->data[s->top - 1];
}

size_t stack_size(Stack s) {
	return s ? s->top : 0;
}

bool stack_is_empty(Stack s) {
	return s ? s->top ==0 : false;
}

size_t stack_capacity(Stack s) {
	return s ? s->max_size - s->top : 0;
}

void stack_print(Stack s) {
	if(!s)
		return;
	for (size_t i = s->top; i > 0; --i)
    		s->print(s->data[i - 1]);
	}
}

