#include <stdio.h>
int main(int argc, char *argv[])
{
  float sn=100.0,hn=sn/2;
  int n;
  for (n=2; n<=10; n++)
    {
      sn = sn + 2*hn;
      hn = hn/2;
    }
  printf ("总路程为：%f\n",sn);
  printf ("第%d次的高度为：%f\n",n-1,hn);
  return 0;
}
