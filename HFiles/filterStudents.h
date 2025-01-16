#ifndef FILTER_STUDENTS_H
#define FILTER_STUDENTS_H

#include <stdio.h>
#include "student.h"
#include "compare.h"

void filterStudents(struct Student *students, int size) {
    int filterChoice;
    printf("По какому критерию фильтровать?\n");
    printf("1. Имя\n2. Фамилия\n3. Возраст\n4. Класс\n");
    scanf("%d", &filterChoice);

    if (filterChoice == 1) {
        char nameFilter[50];
        printf("Введите имя: ");
        scanf("%s", nameFilter);
        for (int i = 0; i < size; i++) {
            if (compareStrings(students[i].name, nameFilter) == 0) {
                printf("%s %s, возраст: %d, класс: %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
            }
        }
    } else if (filterChoice == 2) {
        char surnameFilter[50];
        printf("Введите фамилию: ");
        scanf("%s", surnameFilter);
        for (int i = 0; i < size; i++) {
            if (compareStrings(students[i].surname, surnameFilter) == 0) {
                printf("%s %s, возраст: %d, класс: %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
            }
        }
    } else if (filterChoice == 3) {
        int ageFilter;
        printf("Введите возраст: ");
        scanf("%d", &ageFilter);
        for (int i = 0; i < size; i++) {
            if (students[i].age == ageFilter) {
                printf("%s %s, возраст: %d, класс: %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
            }
        }
    } else if (filterChoice == 4) {
        char classFilter[50];
        printf("Введите класс: ");
        scanf("%s", classFilter);
        for (int i = 0; i < size; i++) {
            if (compareStrings(students[i].clas, classFilter) == 0) {
                printf("%s %s, возраст: %d, класс: %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
            }
        }
    }
}

#endif 
