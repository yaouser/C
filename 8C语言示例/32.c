#include <stdio.h>
int main(int argc, char *argv[])
{
  int color;
  for (color=0; color<8; color++)
    {
      textbackground(color);
      printf("this is color %d\n",color)
	printf("press any key to continue\n")
	getch();
    }
  return 0;
}


//这个程序没有很好的运行
