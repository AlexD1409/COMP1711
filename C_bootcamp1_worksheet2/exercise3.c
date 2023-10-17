#include <stdio.h>
int main() {

    int numbers[] = {14,25,45,76,78};
    int max = 0;
    int i, a;

    for (i=0; i<5; i++)
    {
        a = numbers[i];
        if (a > max){
            max = a;
        }

    }    

    printf("The maximum value is %d\n", max);

    return 0;
}