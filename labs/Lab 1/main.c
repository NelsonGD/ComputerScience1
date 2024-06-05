// Nelson Diaz

// Pre-processor directive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leak_detector_c.h"

typedef struct student 
{ 
    char *lname; // length can vary
    int assignment; // score of assignment
    int finalExam; // score of final exam
    int total; // total score for assignment, final exam, and quizzes.
    int *quizzes; //this will require DMA to store quizzes; number of quizzes can vary

} student;

// Function prototypes
student** readCourses(int *C, int *N, int *M); 
void release_memory(student **courses, int C, int N, int M);
void printHighestTotal(student **courseList, int C, int N, int M);

// driver function 
int main() 
{ 
    atexit(report_mem_leak); //for memory leak detector. 

    student **courseList; // pointer to a "student" struct, used to store list of courses and their students.

    // variable declaration
    int i, j, C, N, M; // C: Number of courses; N: Students PER Course; M: Quizzes per student
    
    //passing reference(addresses) of C, N, and M so that we get to know what we have in the first line
    courseList = readCourses(&C, &N, &M); // Returns pointer to list of courses

    printHighestTotal(courseList, C, N, M); // prints student with highest total score

    release_memory(courseList, C, N, M); // free all allocated memory.

    return 0; 
}

student** readCourses(int *C, int *N, int *M)
{   
    scanf("%d %d %d", C, N, M); // reading number of courses, students per course, and quizzes.

    student **courses = (student**)malloc(*C * sizeof(student*)); // Allocates memory for an array of pointer to "student" struct, one for each course
    
    // memory allocation
    for(int i = 0; i < *C; i++) // responsible for num of courses. Loop mean; For each course:
    { 
        courses[i] = (student*)malloc(*N * sizeof(student));
        for(int j = 0; j < *N; j++) // For each student
        {
            courses[i][j].quizzes = (int*)malloc(*M * sizeof(int)); // allocates memory for an array of integers, one for each quiz score
            char lastname[50];
            scanf("%s", lastname); // Read last name
            int len = strlen(lastname) + 1;
            courses[i][j].lname = (char*)malloc(len * sizeof(char));
            strcpy(courses[i][j].lname, lastname);

            scanf("%d", &courses[i][j].assignment); // Read assignment score

            for (int k = 0; k < *M; k++) // Read quiz scores
            {
                scanf("%d", &courses[i][j].quizzes[k]);
            }

            scanf("%d", &courses[i][j].finalExam); // Read final exam score

            // Calculate total score
            courses[i][j].total = courses[i][j].assignment + courses[i][j].finalExam;
            for (int k = 0; k < *M; k++)
            {
                courses[i][j].total += courses[i][j].quizzes[k];
            }

        }
    }

    return courses; // returns pointer to array of courses
}

/*
pass courseList to function. Then create a For Example: Nested Loop, loop over all student information,
print out information of student that has the highest total score.
*/
void printHighestTotal(student **courseList, int C, int N, int M) // Function needs to iterate through all students in all courses, calculate their total scores, and print the details of the student with the highest score 
{
    int courseIndex = -1, studentIndex = -1, maxTotal = -1; // initialize to -1 to indicate if no valid index was found.

    for(int i = 0; i < C; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(courseList[i][j].total > maxTotal){
                maxTotal = courseList[i][j].total;
                courseIndex = i;
                studentIndex = j;
            }
        }
    }
    
    if(courseIndex != -1 && studentIndex != -1)
    {
        printf("Name: %s\nAssignment: %d\nQuizzes: ", courseList[courseIndex][studentIndex].lname, courseList[courseIndex][studentIndex].assignment);
        for(int i = 0; i < M; i++)
        {
            printf("%d ", courseList[courseIndex][studentIndex].quizzes[i]);
        }
        printf("\nFinal exam: %d\nTotal: %d\nCourse number: %d\n", courseList[courseIndex][studentIndex].finalExam, courseList[courseIndex][studentIndex].total, courseIndex + 1); // Assuming courses are 1-indexed for display
    }
}

void release_memory(student **courses, int C, int N, int M)
{
    for(int j = 0; j < C; j++)
    {
        for(int i = 0; i < N; i++)
        {
            free(courses[j][i].lname); // Free DMA for lname
            free(courses[j][i].quizzes); // Free DMA for quizzes
        }
        free(courses[j]); // Free memory for each student in each course
    }
    free(courses); // Free memory for courses
}
