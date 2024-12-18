#ifndef COMPARE_H
#define COMPARE_H

#include <string.h>
#include "student.h"

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

#endif
