#include <stdio.h>

int main(void){
  int a,b;
  float c;
  printf("Enter 2 integers, seperate by a space\n");
  scanf("%d %d",&a,&b);
  c= (a+b)/2.0;

  printf("average=%.2f \n",c);
  return 0;
} 
