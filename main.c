#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "loadStudents.h"
#include "saveStudents.h"
#include "addStudent.h"
#include "removeStudent.h"
#include "modifyStudent.h"
#include "compare.h"
#include "sortStudents.h"
#include "filterStudents.h"
#include "printStudents.h"

int main() {
    struct Student *students = NULL;
    int size = loadStudents(&students);  // Из файла в код
    int choice;

    do {
        printf("Меню:\n");
        printf("1. Вывести студентов\n");
        printf("2. Добавить студента\n");
        printf("3. Удалить студента\n");
        printf("4. Изменить информацию о студенте\n");
        printf("5. Сортировать студентов\n");
        printf("6. Фильтровать студентов\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStudents(students, size);  // Принт
                break;
            case 2:
                addStudent(&students, &size);   // Добавить студента
                break;
            case 3: {
                int index;
                printStudents(students, size);  // Удалить студента(отображение)
                printf("Введите индекс студента для удаления: ");
                scanf("%d", &index);
                removeStudent(&students, &size, index - 1);  // Удалить студента
                break;
            }
            case 4: {
                int index;
                printStudents(students, size);  // Изменить студента(отображение)
                printf("Введите индекс студента для изменения: ");
                scanf("%d", &index);
                modifyStudent(students, size, index - 1);  // Изменить студента
                break;
            }
            case 5:
                sortStudents(students, size);  // Сортировать
                break;
            case 6:
                filterStudents(students, size);  // Фильтр
                break;
            case 0:
                saveStudents(students, size);  // Сохранялка
                printf("Выход...\n");
                break;
            default:
                printf("Неверный выбор! Пожалуйста, выберите действие от 0 до 6.\n");
        }
    } while (choice != 0); 

    free(students); 
    return 0;  
}
