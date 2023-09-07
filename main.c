/*
Assignment: AACS1074
Group members: Cheah Hong Lek
               Lee Wei Hao

Date: 30/8/2023

Purpose: Calculate GPA & CGPA

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AAA1003 3
#define AAA1014 4
#define ABA1003 3
#define ABA1014 4
#define ACA1003 3
#define ACA1014 4
#define MAX_LENGTH 100
#define FILENAME "user.csv"

#pragma warning(disable:4996)
// declare global variable

float gradePointAAA1003, gradePointAAA1014, gradePointABA1003, gradePointABA1014, gradePointACA1003, gradePointACA1014;
float gradePoint;
float qualityPointAAA1003, qualityPointAAA1014, qualityPointABA1003, qualityPointABA1014, qualityPointACA1003, qualityPointACA1014;
float cgpa;
float gpaSem1, gpaSem2, gpaSem3;
char* courseCode[] = { "AAA1003", "AAA1014", "ABA1003", "ABA1014", "ACA1003", "ACA1014" };
char studentID[20] = "2303442";
char studentName[50] = "Cheah Hong Lek";


// declare function datatype
void studentLogin();
void staffLogin(), staffMenu();
char* checkGrade(float gradePoint);
void enterGradePoint();
void viewStudentResult();
int checkLogin();
void enterStudentDetail();

int main() {
    // declare variable
    int choice;

    //run menu 
    do {
        printf("======================\n");
        printf("Welcome to Kolej Pasar\n");
        printf("======================\n");
        printf("  ___________ \n");
        printf(" /           \\ \n");
        printf("|    Kolej    |\n");
        printf("|    Pasar    |\n");
        printf(" \\           /\n");
        printf("  \\_________/\n");

        //menu option
        printf("\n\nMenu:\n");
        printf("1. Student Login\n");
        printf("2. Staff Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); //get choice

        rewind(stdin); // consume the newline character in the buffer

        // Process user choice
        switch (choice) {
        case 1:
            studentLogin();
            break;
        case 2:
            staffLogin();
            break;
        case 3:
            printf("Exiting the program...\n");
            exit(1);
            break;
        default:
            printf("Invalid choice, Please Try Again.\n");
        }
    } while (choice != 3);

    return 0;
}



void studentLogin() {
    printf("You Choose Student Login\n");
    printf("========================\n");

    // Enter Username Password
    checkLogin();

    // view student result
    viewStudentResult();

    // return main menu
    main();

}

void staffLogin() {
    printf("You Choose Staff Login\n");
    printf("======================\n");

    // Enter Username & Password
    checkLogin();

    // menu
    staffMenu();

}

void staffMenu() {
    int choice;
    do {

        printf("\nMenu:\n");
        printf("1. Enter Student ID & Name\n");
        printf("2. Enter Student grade point\n");
        printf("3. View Student GPA & CGPA\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); //get choice
        rewind(stdin);

        switch (choice) {
        case 1:
            // enter student name & ID
            enterStudentDetail();
            break;
        case 2:
            // enter student grade point
            printf("\n\n\n");
            enterGradePoint();
            break;

        case 3:
            // view student gpa & cgpa
            viewStudentResult();
            staffMenu();
            break;
        case 4:
            main(); // return main menu
            break;
        default:
            printf("Invalid choice, Please Try Again.\n");
        }
    } while (choice != 4);
}

char* checkGrade(float gradePoint) {
    char* message = malloc(3);
    if (gradePoint == 4.00) {
        *message = 'A';
        *(message + 1) = ' ';
    }
    else if (gradePoint >= 3.75) {
        *message = 'A';
        *(message + 1) = '-';
    }
    else if (gradePoint >= 3.50) {
        *message = 'B';
        *(message + 1) = '+';
    }
    else if (gradePoint >= 3.00) {
        *message = 'B';
        *(message + 1) = ' ';
    }
    else if (gradePoint >= 2.75) {
        *message = 'B';
        *(message + 1) = '-';
    }
    else if (gradePoint >= 2.50) {
        *message = 'C';
        *(message + 1) = '+';
    }
    else if (gradePoint >= 2.00) {
        *message = 'C';
        *(message + 1) = ' ';
    }
    else {
        *message = 'F';
        *(message + 1) = ' ';
    }
    *(message + 2) = '\0'; // Null-terminate the string

    return message;
}

void enterGradePoint() {
    //create table for grade point and grade
    printf("\n\n\n");
    printf("%-6s\t%-11s\n", "Grade", "Grade Point");
    printf("%-6s\t%-11s\n", "=======", "===========");
    printf("%-6s\t%-11s\n", "A", "4.00");
    printf("%-6s\t%-11s\n", "A-", "3.75");
    printf("%-6s\t%-11s\n", "B+", "3.50");
    printf("%-6s\t%-11s\n", "B", "3.00");
    printf("%-6s\t%-11s\n", "B-", "2.75");
    printf("%-6s\t%-11s\n", "C+", "2.50");
    printf("%-6s\t%-11s\n", "C", "2.00");
    printf("%-6s\t%-11s\n", "F", "0.00");

    // sem 1
    printf("\n\nSemester 1\n");
    printf("For course AAA1003\n");
    printf("Enter Grade Point: ");
    scanf("%f", &gradePointAAA1003);
    rewind(stdin);

    printf("For course AAA1014\n");
    printf("Enter Grade Point: ");
    scanf("%f", &gradePointAAA1014);
    rewind(stdin);

    // calculate quality point sem 1
    qualityPointAAA1003 = gradePointAAA1003 * AAA1003;
    qualityPointAAA1014 = gradePointAAA1014 * AAA1014;

    gpaSem1 = (qualityPointAAA1003 + qualityPointAAA1014) / (AAA1014 + AAA1003);

    // print quality point and GPA sem 1
    printf("\n\n\nQuality Point for AAA1003: %.2f\n", qualityPointAAA1003);
    printf("Quality Point for AAA1014: %.2f\n", qualityPointAAA1014);

    printf("Semester 1 GPA: %.2f\n", gpaSem1);
    char* result = checkGrade(gpaSem1);
    printf("Grade Obtained: %s\n", result);

    // sem 2
    printf("\n\n\nSemester 2\n");
    printf("For course ABA1003\n");
    printf("Enter Grade Point: ");
    scanf("%f", &gradePointABA1003);
    rewind(stdin);

    printf("For course ABA1014\n");
    printf("Enter Grade Point: ");
    scanf("%f", &gradePointABA1014);
    rewind(stdin);

    // calculate quality point sem 2
    qualityPointABA1003 = gradePointABA1003 * ABA1003;
    qualityPointABA1014 = gradePointABA1014 * ABA1014;

    gpaSem2 = (qualityPointABA1003 + qualityPointABA1014) / (ABA1014 + ABA1003);

    // print quality point and GPA sem 2
    printf("\nQuality Point for ABA1003: %.2f\n", qualityPointABA1003);
    printf("Quality Point for ABA1014: %.2f\n", qualityPointABA1014);

    printf("Semester 2 GPA: %.2f\n", gpaSem2);
    result = checkGrade(gpaSem2);
    printf("Grade Obtained: %s\n", result);

    // sem 3
    printf("\n\n\nSemester 3\n");
    printf("For course ACA1003\n");
    printf("Enter Grade Point: ");
    scanf("%f", &gradePointACA1003);
    rewind(stdin);

    printf("For course ACA1014\n");
    printf("Enter Grade Point: ");
    scanf("%f", &gradePointACA1014);
    rewind(stdin);

    // calculate quality point sem 3
    qualityPointACA1003 = gradePointACA1003 * ACA1003;
    qualityPointACA1014 = gradePointACA1014 * ACA1014;

    gpaSem3 = (qualityPointACA1003 + qualityPointACA1014) / (ACA1014 + ACA1003);

    // print quality point and GPA sem 3
    printf("\nQuality Point for ABA1003: %.2f\n", qualityPointACA1003);
    printf("Quality Point for ABA1014: %.2f\n", qualityPointACA1014);

    printf("Semester 3 GPA: %.2f\n", gpaSem3);
    result = checkGrade(gpaSem3);
    printf("Grade Obtained: %s\n", result);

    //CGPA
    cgpa = (qualityPointAAA1003 + qualityPointAAA1014 + qualityPointABA1003 + qualityPointABA1014 + qualityPointACA1003 + qualityPointACA1014) / (21);
    printf("\n\nTotal credit hours: %d\n", AAA1003 + AAA1014 + ABA1003 + ABA1014 + ACA1003 + ACA1014);
    printf("CGPA: %.2f\n", cgpa);
    result = checkGrade(cgpa);
    printf("Grade Obtained: %s\n", result);

}

void viewStudentResult() {
    char* result;

    printf("\n\n\n");
    printf("Student ID: %s\n", studentID);
    printf("Student Name: %s\n", studentName);

    //Sem 1
    printf("\n\nSemester 1\n");
    printf("Course code: AAA1003\n");
    printf("Credit hour: 3\n");

    printf("Course code: AAA1014\n");
    printf("Credit hour: 4\n");

    printf("GPA: %.2f\n", gpaSem1);
    result = checkGrade(gpaSem1);
    printf("Grade Obtained: %s\n", result);

    // Sem 2
    printf("\n\nSemester 2\n");
    printf("Course code: ABA1003\n");
    printf("Credit hour: 3\n");

    printf("Course code: ABA1014\n");
    printf("Credit hour: 4\n");

    printf("GPA: %.2f\n", gpaSem2);
    result = checkGrade(gpaSem2);
    printf("Grade Obtained: %s\n", result);

    // sem 3
    printf("\n\nSemester 3\n");
    printf("Course code: ACA1003\n");
    printf("Credit hour: 3\n");

    printf("Course code: ACA1014\n");
    printf("Credit hour: 4\n");

    printf("GPA: %.2f\n", gpaSem3);
    result = checkGrade(gpaSem3);
    printf("Grade Obtained: %s\n", result);

    printf("\n\nTotal credit hours: %d\n", AAA1003 + AAA1014 + ABA1003 + ABA1014 + ACA1003 + ACA1014);
    printf("CGPA: %.2f\n", cgpa);
    result = checkGrade(cgpa);
    printf("Grade Obtained: %s\n", result);

}

int checkLogin() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char login_status = 0;

    do {
        //enter password & username
        printf("Enter Username: ");
        scanf("%s", username);

        printf("Enter Password: ");
        scanf("%s", password);

        FILE* file = fopen(FILENAME, "r");
        if (file == NULL) {
            printf("Error opening file\n");
            exit(1);
        }

        char line[MAX_LENGTH];
        while (fgets(line, sizeof(line), file)) {
            char stored_username[MAX_LENGTH];
            char stored_password[MAX_LENGTH];

            sscanf(line, "%[^,],%s", stored_username, stored_password);

            if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
                printf("Login Successful!\n\n");
                login_status = 1;
                fclose(file);
                return 0;
            }
        }

        printf("Login Failed...\n\n");
        fclose(file);
    } while (login_status == 0);

    return 0;
}

void enterStudentDetail() {
    printf("Enter Student ID: ");
    scanf("%s", studentID);
    rewind(stdin);

    printf("Enter Student Name: ");
    scanf("%[^\n]", studentName);
    rewind(stdin);

    printf("Student ID: %s\n", studentID);
    printf("Student Name: %s\n", studentName);
}
