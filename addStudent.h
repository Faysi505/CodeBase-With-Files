#ifndef ADD_STUDENT_H
#define ADD_STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "saveStudents.h"

void addStudent(struct Student **students, int *size) {
    *size += 1;
    *students = realloc(*students, *size * sizeof(struct Student));

    printf("_____________________________________________\nВведите имя: ");
    fscanf(stdin, "%49s", (*students)[*size - 1].name);  

    printf("Введите фамилию: ");
    fscanf(stdin, "%49s", (*students)[*size - 1].surname);  

    printf("Введите возвраст: ");
    fscanf(stdin, "%d", &(*students)[*size - 1].age); 

    printf("Введите класс: \n");
    fscanf(stdin, "%49s", (*students)[*size - 1].clas); 

    saveStudents(*students, *size);
    printf("_____________________________________________\nСтудент добавлен!\n");
}


#endif 
