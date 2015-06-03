#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
  long int i,x,y,z;
  for (i=1; i<100000; i++)
    {
      x=sqrt(i+100); //x为加上100后开放后的结果
      y=sqrt(i+268); //y为再加168后开方后的结果
      if(x*x==i+100&&y*y==i+268)
	printf ("\n%ld\n",i);
    }
  return 0;
}
