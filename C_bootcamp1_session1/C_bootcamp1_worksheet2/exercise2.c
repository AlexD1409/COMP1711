#include <stdio.h>
int main() {

    int array[] = {24,46,57,79,8};
    int a,b,c,d,e;
    int ax,bx,cx,dx,ex;

    a = array[0];
    b = array[1];
    c = array[2];
    d = array[3];
    e = array[4];

    ax = a, bx = b, cx = c, dx = d, ex = e;

    array[4] = ax;
    array[3] = bx;
    array[2] = c;
    array[1] = dx;
    array[0] = ex;

    printf("The reversed array is %d, %d, %d, %d, %d\n", array[0], array[1], array[2], array[3], array[4]);

    return 0;
}