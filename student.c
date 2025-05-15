#include "student.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Cloning a student
 * @param e pointer to a student
 * @return a pointer to the student clone
 */
void* student_clone(void* e) {
	if(!e)
        return NULL;
    student* src = (student*)e;
    student* clone = malloc(sizeof(student));
    if(!clone)
        return NULL;

    size_t len = strlen(src->name) + 1;
    clone->name = malloc(len);
    if (!clone->name) {
        free(clone);
        return NULL;
    }
    memcpy(clone->name, src->name, len);
    clone->age = src->age;
    clone->id = src->id;
    return clone;
}

/**
 * @brief destoying a student
 * @param e pointer to a student
 * @return nothing
 */
void student_destroy(void* e) {
	if(!e)
		return;
	student* Student = (student*)e;
	free(Student->name);
	free(Student);
}

/**
 * @brief printing the student information according to format
 * @param e pointer to a student
 * @return nothing
 */
void student_print(void* e) {
	if(!e)
		return;
	student* Student = (student*)e;
	printf("student name: %s, age: %d, id: %d.\n", Student->name, Student->age, Student->id);
}
