#ifndef MODIFY_STUDENT_H
#define MODIFY_STUDENT_H

#include <stdio.h>
#include "student.h"
#include "saveStudents.h"

void modifyStudent(struct Student *students, int size, int index) {
    int choice;

    printf("_____________________________________________\nЧто вы хотите изменить у студента #%d?\n", index + 1);
    printf("1. Имя\n2. Фамилия\n3. Возраст\n4. Класс\n_____________________________________________\n");
    fscanf(stdin, "%d", &choice); 

    if (choice == 1) {
        printf("Введите новое имя: ");
        fscanf(stdin, "%49s", students[index].name); 
    } else if (choice == 2) {
        printf("Введите новую фамилию: ");
        fscanf(stdin, "%49s", students[index].surname); 
    } else if (choice == 3) {
        printf("Введите новый возраст: ");
        fscanf(stdin, "%d", &students[index].age);  
    } else if (choice == 4) {
        printf("Введите новый класс: ");
        fscanf(stdin, "%49s", students[index].clas); 
    } 
    saveStudents(students, size);
    printf("Информация о студенте изменена\n");
}
#endif 