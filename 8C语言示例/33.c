#include <stdio.h>
int main(int argc, char *argv[])
{
  clrscr();
  textbackground(2);
  gotoxy(1,5);
  printf ("output at row 5 column 1\n");
  textbackground(3);
  gotoxy(20,10);
  printf ("output at row 10 column 20\n");
  return 0;
}


//clrscr() 清屏函数 textbackground() 背景颜色函数
//gotoxy() 定位函数  这是c++中的函数
