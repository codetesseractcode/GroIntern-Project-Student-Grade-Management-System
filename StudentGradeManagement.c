#include <stdio.h>

struct Student {
    char name[50];
    int RollNumber;
    float marks;
    char grade;
};

void CalculateGrade(struct Student *student) {
    if (student->marks >= 90.0 && student->marks <= 100.0) {
        student->grade = 'O';
    } else if (student->marks >= 80.0 && student->marks < 90.0) {
        student->grade = 'E';
    } else if (student->marks >= 70.0 && student->marks < 80.0) {
        student->grade = 'A';
    } else if (student->marks >= 60.0 && student->marks < 70.0) {
        student->grade = 'B';
    } else if (student->marks >= 50.0 && student->marks < 60.0) {
        student->grade = 'C';
    } else if (student->marks >= 40.0 && student->marks < 50.0) {
        student->grade = 'D';
    } else if (student->marks >= 0.0 && student->marks < 40.0) {
        student->grade = 'F';
    } else {
        printf("-----------------------\n");
        printf("Invalid marks entered! Marks should be between 0 and 100.\n");
        printf("-----------------------\n");
        student->grade = '?';
    }
}

void DisplayStudent(struct Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->RollNumber);
    printf("Marks: %.2f\n", student->marks);
    printf("Grade: %c\n", student->grade);
    printf("-----------------------\n");
}

int main() {
    struct Student students[1000];

    int n;
    printf("Enter the no of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", &students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].RollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);

        // Calculate and assign the grade
        CalculateGrade(&students[i]);
    }

    printf("Student details are the following:\n");
    for (int i = 0; i < n; i++) {
        DisplayStudent(&students[i]);
    }

    return 0;
}
