#include <stdio.h>
int main() {
    float length;
    float width;
    float area;

    printf("Please enter a width: ");
    scanf("%f", &width);
    printf("Please enter a length: ");
    scanf("%f", &length);

    area = length * width;

    printf ("The area is %f", area);

return 0;
}