#include <stdio.h>

float circleArea (float radius)
    {
        float area;
        area = radius * radius * 3.14159;
        return area;
    }

int main() {

    float radius; 
    printf("Enter a radius to find the area: \n");
    scanf("%f", &radius);
    printf("The area is %f\n", circleArea(radius));
    return 0;
}

