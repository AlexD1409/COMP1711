#include <stdio.h>

struct student{ //arrays only hold one type of data, structs can hold more
    char name[20]; //1 letter takes 1 byte of space, better to give more space than needed 
    char student_id[11]; //good to store numbers as chars when not purely for operations,int will remove leading 0 e.g. in phone numbers
    int mark;
};

int main () {

    struct student new_student;
    
    printf("Enter a name");
    scanf("%s", new_student.name); //Has issues with reading in spaces

    printf("Enter a student ID");
    scanf("%d", new_student.student_id);

    printf("Enter a mark");
    scanf("%d", new_student.mark);

    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}