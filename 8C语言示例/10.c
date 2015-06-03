#include <stdio.h>
int main(void)
{
  int i,j;
  printf ("   ^_^   ^_^\n"); //输出两个笑脸
  for (i=1; i<11; i++)
    {
      for(j=1;j<=i;j++)
	printf ("^_^\t");
      printf ("\n");
    }
  return 0;
}
