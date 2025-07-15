#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *name;
    int age;
    char grade;
}Student;

int main(){
    // Student Database
    printf(" STUDENT DATABASE\n");

    int n = 0;
    printf("Enter the no.of students: ");
    scanf("%d", &n);

    Student students[n];

    for (int i = 0; i < n; i ++){
        char name[50] = {0};

        printf("Enter #%d name: ", i + 1);
        getchar();
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';

        students[i].name = malloc((strlen(name)+ 1) * sizeof(char));
        strcpy(students[i].name, name);

        printf("Enter the age: ");
        scanf("%d", &students[i].age);

        printf("Enter grade: ");
        scanf(" %c", &students[i].grade);
    }

    printf("%-20s %3s %s\n", "Name", "Age", "Grade");
    printf("==============================================\n");

    for (int i = 0; i < n; i++){
        printf("%-20s %2d %2c\n", students[i].name, students[i].age, students[i].grade);
    }

    for (int i = 0; i < n; i++){
        free(students[i].name);
    }
    
    return 0;
}