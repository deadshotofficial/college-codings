#include <stdio.h>
#include <string.h>

typedef struct Student {
    int roll_no;
    char name[50];
    int age;
    char address[100];
} stud;

void printAge14(stud st[], int num) {
    int a=0;

    printf("\nStudents with age 14:\n");
    for (int i=0; i<num; i++) {
        if (st[i].age == 14) {
            printf("%s\n", st[i].name);
            a = 1;
        }
    }

    if (!a) {
        printf("No students found with age 14.");
    }
}

void printEvenRollNo(stud st[], int num) {
    int a = 0;

    printf("\nStudents with even roll numbers:\n");
    for (int i=0; i<num; i++) {
        if (st[i].roll_no % 2 == 0) {
            printf("%s\n", st[i].name);
            a = 1;
        }
    }

    if (!a) {
        printf("No students found with even roll numbers.\n");
    }
}
void displayStudent(stud st[], int num, int roll) {
    int a = 0;

    for (int i=0; i<num; i++) {
        if (st[i].roll_no == roll) {
            printf("\nStudent Details:\n");
            printf("Roll Number: %d\n", st[i].roll_no);
            printf("Name: %s\n", st[i].name);
            printf("Age: %d\n", st[i].age);
            printf("Address: %s\n", st[i].address);
            a = 1;
            break;
        }
    }

    if (!a) {
        printf("No student found with roll number %d.\n", roll);
    }
}

int main() {
    stud std[12];

    for (int i=0; i<12; i++) {
        printf("Enter Student %d Details:\n", i+1);

        printf("Roll No: ");
        scanf("%d", &std[i].roll_no);

        fflush(stdin);
        printf("Name: ");
        gets(std[i].name);

        printf("Age: ");
        scanf("%d", &std[i].age);

        fflush(stdin);
        printf("Address: ");
        gets(std[i].address);

        printf("\n");
    }

    int choice, rno, num_std = 12;

    do {
        printf("\nMenu:\n");
        printf("1. Print names of students having age 14\n");
        printf("2. Print names of students having even roll number\n");
        printf("3. Display details of a student by roll number\n");
        printf("4. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printAge14(std, num_std);
                break;
            case 2:
                printEvenRollNo(std, num_std);
                break;
            case 3:
                printf("Enter the roll number: ");
                scanf("%d", &rno);
                displayStudent(std, num_std, rno);
                break;
            case 4:
                printf("Thanks for using the Program!");
                break;
            default:
                printf("Invalid choice! Please try again.");
        }
    } while (choice != 4);

    return 0;
}
