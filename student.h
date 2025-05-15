#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>

/**
 * @brief The student struct
 * @param name the studnt name
 * @param age the studnt age
 * @param id the studnt ID
 */
typedef struct student {
	char* name;
	int age;
	int id;

} student;

// the pointers to the functions
void* student_clone(void* e);
void student_destroy(void* e);
void student_print(void* e);

#endif
