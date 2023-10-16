#include <stdio.h>
int main() {
    int mark;
    printf("Please enter a mark ");
    scanf("%d", &mark);

    if (mark >= 0 && mark <= 100)
    {
        if (mark <50)
        {
            printf("This mark is a fail\n");
        }
        else if (mark <70)
        {
            printf("This mark is a pass\n");
        }
        else 
            printf("This mark is a distinction\n");
    }

    else 
    {
        printf("Mark must be between 0 and 100\n");
    }

    return 0;
}