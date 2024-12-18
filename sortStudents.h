#ifndef SORT_STUDENTS_H
#define SORT_STUDENTS_H

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "compare.h"
#include "saveStudents.h"

void sortStudents(struct Student *students, int size) {
    int sortChoice;
    printf("По какому критерию сортировать?\n");
    printf("1. Имя\n2. Фамилия\n3. Возраст\n4. Класс\n");
    scanf("%d", &sortChoice);

    int (*compareFunc)(const void *, const void *) = NULL;

    if (sortChoice == 1) {
        compareFunc = compareByName;
    } else if (sortChoice == 2) {
        compareFunc = compareBySurname;
    } else if (sortChoice == 3) {
        compareFunc = compareByAge;
    } else if (sortChoice == 4) {
        compareFunc = compareByClass;
    } else {
        printf("Ошибка\n");
        return;
    }

    qsort(students, size, sizeof(struct Student), compareFunc);
    saveStudents(students, size);
    printf("Список отсортирован!\n");
}

#endif
