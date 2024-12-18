#ifndef PRINT_STUDENTS_H
#define PRINT_STUDENTS_H

#include <stdio.h>
#include "student.h"

// Function to print all students
void printStudents(struct Student *students, int size) {
    if (size == 0) {
        printf("Нет студентов для отображения.\n");
        return;
    }

    printf("\nСписок студентов:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s %s, возраст: %d, класс: %s\n", 
            i + 1, students[i].name, students[i].surname, students[i].age, students[i].clas);
    }
    printf("\n");
}

#endif
