#include <stdio.h>
int main(void)
{
  int i, j;
  for (i=1; i<=9; i++)
    {
      for(j=1; j<=9&&j<=i;j++)
	printf ("%d*%d=%d\t",i,j,i*j);
      printf ("\n");
    }
  return 0;
}
