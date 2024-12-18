#ifndef REMOVE_STUDENT_H
#define REMOVE_STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "saveStudents.h"

void removeStudent(struct Student **students, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Неверный индекс!\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        (*students)[i] = (*students)[i + 1];
    }

    *size -= 1;
    *students = realloc(*students, *size * sizeof(struct Student));

    saveStudents(*students, *size);
    printf("_____________________________________________\nСтудент удалён\n");
}

#endif 
