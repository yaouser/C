#include <stdio.h>
#define N 10
int main(int argc, char *argv[])
{
  int i,j,min,tem,a[N];
  //shu ru shu ju
  printf ("please input ten number:\n");
  for (i=0; i<N; i++)
    {
      printf ("a[%d]=",i);
      scanf("%5d",&a[i]);
    }
  printf ("\n");
  for (i=0; i<N; i++)
    {
      printf ("%5d",a[i]);
    }
  printf ("\n");
  //sort ten numbers
  for (i=0; i<N-1; i++)
    {
      min=i;
      for(j=i+1;j<N;j++)
	if(a[min]>a[j])
	  min=j;
      tem=a[i];
      a[i]=a[min];
      a[min]=tem;
    }
  //output data
  printf ("after sorted\n");
  for(i=0;i<N;i++)
    printf ("%5d",a[i]);
  printf ("\n");
  return 0;
}
