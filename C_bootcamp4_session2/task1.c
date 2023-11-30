#include <stdlib.h>
#include <stdio.h>

int main(){

    char* address = malloc( 200 * sizeof(char));

    int* data = malloc(70 * sizeof(int));

    int size;
    printf("Enter size of array\n");
    scanf("%d", &size);
    double* samples = malloc(size * sizeof(double));
    if(!samples){
        printf("Array too large\n");
    }

}