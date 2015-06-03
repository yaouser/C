#include <stdio.h>
#define N 5
int main(int argc, char *argv[])
{
  int a[N]={9,6,5,4,1},i,temp1,temp2;
  printf ("original array:\n");
  for (i=0; i<N; i++)
    {
      printf ("%d\n",a[i]);
    }
  for (i=0; i<N/2; i++)
    {
      temp1=a[i];
      a[i]=a[N-i-1];
      a[N-i-1]=temp1;
    }
  printf ("sorted array:\n");
  for(i=0;i<N;i++)
    printf ("%d\n",a[i]);
  return 0;
}
