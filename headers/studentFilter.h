#ifndef STUDENT_FILTER_H
#define STUDENT_FILTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentStruct.h"

void filterStudents(struct Student *students, int size, const char *criteria) {
    char key[50];
    char value[50];
    sscanf(criteria, "%49[^=]=%49s", key, value);

    for (int i = 0; i < size; i++) {
        if ((strcmp(key, "name") == 0 && strcmp(students[i].name, value) == 0) ||
            (strcmp(key, "surname") == 0 && strcmp(students[i].surname, value) == 0) ||
            (strcmp(key, "age") == 0 && students[i].age == atoi(value)) ||
            (strcmp(key, "class") == 0 && strcmp(students[i].className, value) == 0)) {
            printf("%s %s, age: %d, class: %s\n", students[i].name, students[i].surname, students[i].age, students[i].className);
        }
    }
}

#endif 