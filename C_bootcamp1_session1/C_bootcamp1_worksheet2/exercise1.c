#include <stdio.h>
int main() {

    int array[] = {13, 37, 73, 25, 79};
    int total = 0;
    int n;

    for (n=0; n<5; n++)
    {
        total += array[n];
    }

    printf("The total of the array is %d\n", total);
    return 0;
}