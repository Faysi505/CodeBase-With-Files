#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int age;
    char name[50];
    char surname[50];
    char clas[50];
};

int loadStudents(struct Student **students) {
    FILE *file = fopen("studentlist.txt", "r");

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

void saveStudents(struct Student *students, int size) {
    FILE *file = fopen("studentlist.txt", "w");

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %d %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
    }

    fclose(file);
}

void addStudent(struct Student **students, int *size) {
    *size += 1;
    *students = realloc(*students, *size * sizeof(struct Student));

    printf("_____________________________________________\nВведите имя: ");
    scanf("%s", (*students)[*size - 1].name);
    printf("Введите фамилию: ");
    scanf("%s", (*students)[*size - 1].surname);
    printf("Введите возраст: ");
    scanf("%d", &(*students)[*size - 1].age);
    printf("Введите класс: ");
    scanf("%s", (*students)[*size - 1].clas);

    saveStudents(*students, *size);
    printf("_____________________________________________\nСтудент добавлен!\n");
}

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

void modifyStudent(struct Student *students, int size, int index) {

    int choice;
    printf("_____________________________________________\nЧто вы хотите изменить у студента #%d?\n", index + 1);
    printf("1. Имя\n");
    printf("2. Фамилия\n");
    printf("3. Возраст\n");
    printf("4. Класс\n_____________________________________________\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("_____________________________________________\nВведите новое имя: ");
        scanf("%s", students[index].name);
    } else if (choice == 2) {
        printf("_____________________________________________\nВведите новую фамилию: ");
        scanf("%s", students[index].surname);
    } else if (choice == 3) {
        printf("_____________________________________________\nВведите новый возраст: ");
        scanf("%d", &students[index].age);
    } else if (choice == 4) {
        printf("_____________________________________________\nВведите новый класс: ");
        scanf("%s", students[index].clas);
    } else {
        printf("_____________________________________________\nНеверный выбор\n");
        return;
    }

    saveStudents(students, size);
    printf("_____________________________________________\nИнформация о студенте изменена!\n");
}

int compareStrings(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

int compareByName(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return compareStrings(studentA->name, studentB->name);
}
int compareBySurname(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return compareStrings(studentA->surname, studentB->surname);
}
int compareByAge(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return studentA->age - studentB->age;
}
int compareByClass(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return compareStrings(studentA->clas, studentB->clas);
}

void sortStudents(struct Student *students, int size) {
    int sortChoice;
    printf("_____________________________________________\nПо какому критерию вы хотите сортировать?\n");
    printf("1. Имя\n");
    printf("2. Фамилия\n");
    printf("3. Возраст\n");
    printf("4. Класс\n");
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
        printf("Неверный выбор!\n");
        return;
    }

    qsort(students, size, sizeof(struct Student), compareFunc);
    saveStudents(students, size);
    printf("_____________________________________________\nСписок студентов отсортирован!\n");
}

//filter 

void filterStudents(struct Student *students, int size) {
    int filterChoice;
    printf("_____________________________________________\nПо какому критерию вы хотите фильтровать?\n");
    printf("1. Имя\n");
    printf("2. Фамилия\n");
    printf("3. Возраст\n");
    printf("4. Класс\n");
    scanf("%d", &filterChoice);

    if (filterChoice == 1) {
        char nameFilter[50];
        printf("Введите имя для фильтрации: ");
        scanf("%s", nameFilter);
        for (int i = 0; i < size; i++) {
            if (compareStrings(students[i].name, nameFilter) == 0) {
                printf("%s %s, возраст: %d, класс: %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
            }
        }
    } else if (filterChoice == 2) {
        char surnameFilter[50];
        printf("Введите фамилию для фильтрации: ");
        scanf("%s", surnameFilter);
        for (int i = 0; i < size; i++) {
            if (compareStrings(students[i].surname, surnameFilter) == 0) {
                printf("%s %s, возраст: %d, класс: %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
            }
        }
    } else if (filterChoice == 3) {
        int ageFilter;
        printf("Введите возраст для фильтрации: ");
        scanf("%d", &ageFilter);
        for (int i = 0; i < size; i++) {
            if (students[i].age == ageFilter) {
                printf("%s %s, возраст: %d, класс: %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
            }
        }
    } else if (filterChoice == 4) {
        char classFilter[50];
        printf("Введите класс для фильтрации: ");
        scanf("%s", classFilter);
        for (int i = 0; i < size; i++) {
            if (compareStrings(students[i].clas, classFilter) == 0) {
                printf("%s %s, возраст: %d, класс: %s\n", students[i].name, students[i].surname, students[i].age, students[i].clas);
            }
        }
    } else {
        printf("Неверный выбор!\n");
    }
}

//print

void printStudents(struct Student *students, int size) {

    for (int i = 0; i < size; i++) {
        printf("%d. %s %s, возраст: %d, класс: %s\n", "_____________________________________________\n" i + 1, students[i].name, students[i].surname, students[i].age, students[i].clas);
    }
}

int main() {
    struct Student *students = NULL;
    int size = loadStudents(&students);

    int MoveNum;
    int ProgramExit = 0;

    while (ProgramExit != 1) {
        printf("_____________________________________________\nВведите действие:\n1. Добавить студента\n2. Удалить студента\n3. Изменить информацию\n4. Отсортировать список\n5. Отфильтровать список\n6. Показать список\n7. Выйти\n");
        scanf("%d", &MoveNum);

        if (MoveNum == 1) {
            addStudent(&students, &size);
        } else if (MoveNum == 2) {
            int index;
            printf("Введите индекс студента для удаления (1 - %d): ", size);
            scanf("%d", &index);
            removeStudent(&students, &size, index - 1);
        } else if (MoveNum == 3) {
            int index;
            printf("Введите индекс студента для изменения (1 - %d): ", size);
            scanf("%d", &index);
            modifyStudent(students, size, index - 1);
        } else if (MoveNum == 4) {
            sortStudents(students, size);
        } else if (MoveNum == 5) {
            filterStudents(students, size);
        } else if (MoveNum == 6) {
            printStudents(students, size);
        } else if (MoveNum == 7) {
            ProgramExit = 1;
        }
    }

    free(students);
    return 0;
}