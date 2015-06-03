#include <stdio.h>
int main(int argc, char *argv[])
{
  int n1,n2,n3;
  int *pointer1,*pointer2,*pointer3;
  printf ("please input 3 number:n1,n2,n3:\n");
  scanf("%d%d%d",&n1,&n2,&n3);
  pointer1=&n1;
  pointer2=&n2;
  pointer3=&n3;
  if(n1>n2)
    swap(pointer1,pointer2);
  if(n1>n3)
    swap(pointer1,pointer3);
  if(n2>n3)
    swap(pointer2,pointer3);
  printf ("the sorted numbers are:%d,%d,%d\n",n1,n2,n3);
  return 0;
}
swap(int *p1,int *p2)
{
  int p;
  p=*p1;*p1=*p2;*p2=p;
}
