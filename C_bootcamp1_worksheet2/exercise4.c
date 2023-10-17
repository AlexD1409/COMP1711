#include <stdio.h>
int main() {
    int original[] = {1,2,3,4,5};
    int shifted[5];
    int i, first, a;

    shifted[0] = 0;
    first = original[0];

    for(i=0; i<5;i++)
    {
        shifted[i+1] = original[i];
    }

    printf("%d, %d, %d, %d, %d\n," shifted[0], shifted[1], shifted[2], shifted[3], shifted[4]);
    return 0;

    }




