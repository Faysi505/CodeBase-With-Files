#ifndef STUDENT_INPUT_H
#define STUDENT_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include "studentStruct.h"

int loadStudents(struct Student **students) {
    FILE *file = fopen("studentlist.txt", "r");
    if (!file) return 0;

    int count = 0;
    struct Student temp;
    while (fscanf(file, "%49s %49s %d %49s", temp.name, temp.surname, &temp.age, temp.className) == 4) {
        *students = realloc(*students, (count + 1) * sizeof(struct Student));
        (*students)[count++] = temp;
    }
    fclose(file);
    return count;
}

void saveStudents(struct Student *students, int size) {
    FILE *file = fopen("studentlist.txt", "w");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %d %s\n", students[i].name, students[i].surname, students[i].age, students[i].className);
    }
    fclose(file);
}

#endif // STUDENT_INPUT_H
