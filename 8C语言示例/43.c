#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,num;
  num=2;
  for (i=0; i<3; i++)
    {
      printf ("the number equal %d\n",num);
      num++;
      {
	static int num=1;
	printf ("the internal block equal %d\n",num);
	num++;
      }
    }
  return 0;
}
