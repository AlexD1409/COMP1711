#include <stdio.h>
int main(){

    int a = 23;
    int guess;
    
       while (guess != a)
    {
        printf("Enter a guess ");
        scanf("%d", &guess);

    }
    
    printf("Correct!");

    return 0;
}