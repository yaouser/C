#include <stdio.h>
int main(int argc, char *argv[])
{
  int day,x1,x2;
  day=9;
  x2=1;
  while(day>0)
    {
      x1=(x2+1)*2;
	x2=x1;
      day--;
     }
  printf ("苹果总数为：%d\n",x1);
  return 0;
}
