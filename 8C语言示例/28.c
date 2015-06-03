#include <stdio.h>
age(int n)
{
  int c;
  if(n==1)
    c=10;
  else
    c=age(n-1)+2;
  return(c);
}
int main(int argc, char *argv[])
{
  printf ("%d\n",age(5));
  return 0;
}
