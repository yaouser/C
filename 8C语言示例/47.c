#include <stdio.h>
//mcro define 时，超过两行时要用'\'结束
#define exchange(a,b) {\
  int t;\
  t=a;\
  a=b;\
  b=t;\
  }
void main(void)
{
  int x=10;
  int y=20;
  printf ("x=%d;y=%d\n",x,y);
  exchange(x,y);
  printf ("x=%d;y=%d\n",x,y);
}
