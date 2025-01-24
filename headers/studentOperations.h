#ifndef STUDENT_OPERATIONS_H
#define STUDENT_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentStruct.h"
#include "studentInput.h"

void addStudent(struct Student **students, int *size, const char *name, const char *surname, int age, const char *className) {
    *students = realloc(*students, (*size + 1) * sizeof(struct Student));
    strcpy((*students)[*size].name, name);
    strcpy((*students)[*size].surname, surname);
    (*students)[*size].age = age;
    strcpy((*students)[*size].className, className);
    (*size)++;
    saveStudents(*students, *size);
}

void removeStudent(struct Student **students, int *size, int index) {
    if (index < 0 || index >= *size) return;
    for (int i = index; i < *size - 1; i++) (*students)[i] = (*students)[i + 1];
    *students = realloc(*students, (--(*size)) * sizeof(struct Student));
    saveStudents(*students, *size);
}

void modifyStudent(struct Student *students, int size, int index, const char *name, const char *surname, int age, const char *className) {
    if (index < 0 || index >= size) return;
    strcpy(students[index].name, name);
    strcpy(students[index].surname, surname);
    students[index].age = age;
    strcpy(students[index].className, className);
    saveStudents(students, size);
}

#endif 
