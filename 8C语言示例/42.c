#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,num;
  num=2;
  for (i=0; i<3; i++)
    {
      printf ("the num equal %d\n",num);
      num++;
      {
	auto int num=1;
	printf ("the internal block num equal %d\n",num);
	num++;
      }
    }
  return 0;
}

//auto 声明的常量，其值不会改变
