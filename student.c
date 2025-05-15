#include "student.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void* student_clone(void* e) {
	if(!e)
		return NULL;
	student* src = (student*)e;
	student* clone = malloc(sizeof(student));
	if(!clone)
		return NULL;
	clone->name = strdup(src->name);
	if(!clone->name)
		return NULL;
	clone->age = src->age;
	clone->id = src->id;
	return clone;
}

void student_destroy(void* e) {
	if(!e)
		return;
	student* Student = (student*)e;
	free(Student->name);
	free(Student);
}

void student_print(void* e) {
	if(!e)
		return;
	student* Student = (student*)e;
	printf("student name: %s, age: %d, id: %d", Student->name, Student->age, Student->id);
}
