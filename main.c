/*
Purpose: Calculate GPA & CGPA

GPA = Quality Point / Credit Hours
CGPA = Total Quality Point / Total Credit Hours
Quality Point = Grade Point earned x Credit Hours

Prompt input and get 
1. student name
2. student id
3. course code
4. current semester
5. grade point earned
6. credit hours 

Process
1. navigation menu
    - student login
        -Enter student ID
            -view student ID
            -view gpa
    - teacher login
        -Enter teacher ID
    - exit
1. calculate quality point
2. calculate gpa
3. calculate cgpa
*/

#include <stdio.h>
#include <stdlib.h>

// declare function datatype
void studentLogin();
void teacherLogin();
void exitProgram();

int main(){
    // declare variable
    int choice;

    //run menu 
    do {
        //menu option
        printf("\nMenu:\n");
        printf("1. Student Login\n");
        printf("2. Teacher Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); //get choice

        rewind(stdin); // consume the newline character in the buffer

        // Process user choice
        switch(choice){
            case 1:
                studentLogin();
                break;
            case 2:
                teacherLogin();
                break;
            case 3:
                exitProgram();
                break;
            default:
                printf("Invalid choice, Please Try Again.\n");
        }
    } while (choice != 3);

    return 0;
}



void studentLogin(){
    printf("You Choose Student Login 1.\n");

    // declare variable
    char courseCode[10], currentSemester[10];
    char studentID[10];
    float gradePoint, qualityPoint, gpa;
    int creditHour;

    // get input 
    printf("Enter Your Student ID: ");
    gets(studentID);

    printf("Enter Your Couse Code: ");
    gets(courseCode);

    printf("Enter Your Grade Point: ");
    scanf("%f", &gradePoint);

    printf("Enter Your Credit Hours: ");
    scanf("%d", &creditHour);

    // process
    qualityPoint = gradePoint * creditHour;
    gpa = qualityPoint / creditHour;


    // output
    printf("\n\nHello student %s!\n", studentID);
    printf("Quality Point = %.2f\n", qualityPoint);
    printf("GPA = %.2f\n", gpa);

    printf("For your course %s, the GPA is %.2f\n", courseCode, gpa);
}

void teacherLogin(){
    printf("You Choose Teacher Login");

    //more code...
}


void exitProgram(){
    printf("Exiting the program...\n");
}