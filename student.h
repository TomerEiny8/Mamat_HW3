#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>

typedef struct student {
	char* name;
	int age;
	int id;

} student;

void* student_clone(void* e);
void student_destroy(void* e);
void student_print(void* e);

#endif
