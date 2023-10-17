#include <stdio.h>
int main (){
    float a , b ,c;
    printf ("Enter the first number");
    scanf ("%f" , &a );
    printf ("Enter the second number");
    scanf ("%f", &b);

    c = a + b;

    printf ("The answer is %f", c);
    return 0;
}