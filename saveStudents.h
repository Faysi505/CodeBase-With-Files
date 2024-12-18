#ifndef SAVE_STUDENTS_H
#define SAVE_STUDENTS_H

#include <stdio.h>
#include "student.h"

void saveStudents(struct Student *students, int size) {
    FILE *file = fopen("studentlist.txt", "w");
    if (!file) {
        perror("Ошибка");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %d %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
    }

    fclose(file);
}

#endif 
