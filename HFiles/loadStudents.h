#ifndef LOAD_STUDENTS_H
#define LOAD_STUDENTS_H

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int loadStudents(struct Student **students) {
    FILE *file = fopen("studentlist.txt", "r");
    if (!file) {
        perror("Ошибка");
        return 0;
    }

    int size = 0;
    struct Student temp;
    while (fscanf(file, "%s %s %d %s", temp.name, temp.surname, &temp.age, temp.clas) != EOF) {
        *students = realloc(*students, (size + 1) * sizeof(struct Student));
        (*students)[size] = temp;
        size++;
    }

    fclose(file);
    return size;
}

#endif
