#include <stdio.h>
#include <math.h> // insert "-lm" in the gcc command
//int x1,y2,x2,y2,x3,y3;
struct point{
    int x;
    int y;
};
struct triangle{
    float a;
    float b;
    float c;
    float s;
    float area;
};
struct point pt1,pt2,pt3;
struct triangle tr;


int main(void){
    // get user input
    printf("Nhap toa do dinh 1: \n");
    scanf("%d %d", &pt1.x, &pt1.y);
    printf("Nhap toa do dinh 2: \n");
    scanf("%d %d", &pt2.x, &pt2.y);
    printf("Nhap toa do dinh 3: \n");
    scanf("%d %d", &pt3.x, &pt3.y);
    // Calculate the triangle area using Heron'formular
    // area = sqrt(s(s-a)(s-b)(s-c))
    // with s = 0.5(a+b+c)
    tr.a = sqrt(pow(pt1.x-pt2.x,2) + pow(pt1.y-pt2.y,2));
    tr.b = sqrt(pow(pt1.x-pt3.x,2) + pow(pt1.y-pt3.y,2));
    tr.c = sqrt(pow(pt3.x-pt2.x,2) + pow(pt3.y-pt2.y,2));
    tr.s = 0.5*(tr.a + tr.b + tr.c);
    tr.area = sqrt(tr.s*(tr.s-tr.a)*(tr.s-tr.b)*(tr.s-tr.c));
    printf("Triangle area = %.2f \n", tr.area);
    return 0;
}
