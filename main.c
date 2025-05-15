#include "stack.h"
#include "student.h"
#include <stdio.h>

int main() {
    Stack s = stack_create(2, student_clone, student_destroy, student_print);

    student a = {"dan", 22, 11};
    student b = {"samir", 24, 12};
    student c = {"reut", 31, 123};

    // Push a and b - should succeed
    printf("Push a: %s\n", stack_push(s, &a) == 0 ? "OK" : "FAIL");
    printf("Push b: %s\n", stack_push(s, &b) == 0 ? "OK" : "FAIL");

    // Push c - should fail (stack full)
    printf("Push c (overflow): %s\n", stack_push(s, &c) == 0 ? "OK" : "FAIL");

    // Print stack
    printf("\nCurrent stack:\n");
    stack_print(s);

    // Peek top
    printf("\nPeek top:\n");
    student_print(stack_peek(s));

    // Pop once
    stack_pop(s);
    printf("\nAfter 1 pop:\n");
    stack_print(s);

    // Pop twice (empty after second)
    stack_pop(s);
    stack_pop(s); // Should not crash
    printf("\nAfter 2 more pops (empty):\n");
    stack_print(s);

    // Check is_empty
    printf("\nIs empty: %s\n", stack_is_empty(s) ? "yes" : "no");

    // Check peek on empty
    printf("\nPeek on empty: ");
    elem_t top = stack_peek(s);
    printf(top ? "NOT NULL (BUG)\n" : "NULL (OK)\n");

    // Clean up
    stack_destroy(s);
    return 0;
}
