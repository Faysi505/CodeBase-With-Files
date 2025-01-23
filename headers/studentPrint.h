#ifndef STUDENT_PRINT_H
#define STUDENT_PRINT_H

#include <stdio.h>
#include "studentStruct.h"

void printStudents(struct Student *students, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s %s, age: %d, class: %s\n", i + 1, students[i].name, students[i].surname, students[i].age, students[i].className);
    }
}

#endif // STUDENT_PRINT_H
