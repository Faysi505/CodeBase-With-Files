#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include header files
#include "headers/studentStruct.h"
#include "headers/studentInput.h"
#include "headers/studentOperations.h"
#include "headers/studentFilter.h"
#include "headers/studentSort.h"
#include "headers/studentPrint.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./main.o <operation> [parameters]\n");
        return 1;
    }

    const char *operation = argv[1];

    struct Student *students = NULL;
    int size = loadStudents(&students);

    if (strcmp(operation, "add") == 0) {
        if (argc != 6) {
            printf("Usage for add: ./main.o add <name> <surname> <age> <class>\n");
            return 1;
        }
        addStudent(&students, &size, argv[2], argv[3], atoi(argv[4]), argv[5]);
    } else if (strcmp(operation, "remove") == 0) {
        if (argc != 3) {
            printf("Usage for remove: ./main.o remove <index>\n");
            return 1;
        }
        removeStudent(&students, &size, atoi(argv[2]) - 1);
    } else if (strcmp(operation, "modify") == 0) {
        if (argc != 7) {
            printf("Usage for modify: ./main.o modify <index> <name> <surname> <age> <class>\n");
            return 1;
        }
        modifyStudent(&students, size, atoi(argv[2]) - 1, argv[3], argv[4], atoi(argv[5]), argv[6]);
    } else if (strcmp(operation, "sort") == 0) {
        if (argc != 3) {
            printf("Usage for sort: ./main.o sort <criteria>\nCriteria: name, surname, age, class\n");
            return 1;
        }
        sortStudents(students, size, argv[2]);
    } else if (strcmp(operation, "filter") == 0) {
        if (argc != 3) {
            printf("Usage for filter: ./main.o filter <criteria>\nCriteria: name=<value>, surname=<value>, age=<value>, class=<value>\n");
            return 1;
        }
        filterStudents(students, size, argv[2]);
    } else if (strcmp(operation, "print") == 0) {
        printStudents(students, size);
    } else {
        printf("Unknown operation.\n");
    }

    saveStudents(students, size);
    free(students);
    return 0;
}
