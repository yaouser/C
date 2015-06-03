#include <stdio.h>
int a,b,c;
void add()
{
  int a;
  a=3;
  c=a+b;
}
void main()
{
  a=b=4;
  add();
  printf ("the value of c is equal to %d\n",c);
}

//运行结果 ：the value of c is equal to 7
//全局变量，主函数的赋值会将调用函数的值覆盖
