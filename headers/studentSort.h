#ifndef STUDENT_SORT_H
#define STUDENT_SORT_H

#include <stdlib.h>
#include <string.h>
#include "studentStruct.h"

int compareByName(const void *a, const void *b) {
    return strcmp(((struct Student *)a)->name, ((struct Student *)b)->name);
}

int compareBySurname(const void *a, const void *b) {
    return strcmp(((struct Student *)a)->surname, ((struct Student *)b)->surname);
}

int compareByAge(const void *a, const void *b) {
    return ((struct Student *)a)->age - ((struct Student *)b)->age;
}

int compareByClass(const void *a, const void *b) {
    return strcmp(((struct Student *)a)->className, ((struct Student *)b)->className);
}

void sortStudents(struct Student *students, int size, const char *criteria) {
    if (strcmp(criteria, "name") == 0) {
        qsort(students, size, sizeof(struct Student), compareByName);
    } else if (strcmp(criteria, "surname") == 0) {
        qsort(students, size, sizeof(struct Student), compareBySurname);
    } else if (strcmp(criteria, "age") == 0) {
        qsort(students, size, sizeof(struct Student), compareByAge);
    } else if (strcmp(criteria, "class") == 0) {
        qsort(students, size, sizeof(struct Student), compareByClass);
    } else {
        printf("Invalid sort criteria.\n");
    }
}

#endif // STUDENT_SORT_H
