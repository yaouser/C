#include <stdio.h>
int incerment(j)
{
  int sum;
  if (j==0)
    {
      sum=1;
    }
  else
    sum=j*incerment(j-1);
  return sum;
}
int main(int argc, char *argv[])
{
  int i;
  int incerment();
  for (i=0; i<=5; i++)
    {
      printf ("\40:%d!=%d\n",i,incerment(i));
    }
  return 0;
}
