#include <stdio.h>
int main(int argc, char *argv[])
{
  int x,y,z,t;
  scanf("%d %d %d",&x,&y,&z);
  if (x>y)
    {
      t=x;x=y;y=t;
    }
  if (x>z)
    {
      t=z;z=x;x=t;
    }
  if (y>z)
    {
      t=y;y=z;z=t;
    }
  printf ("small to big:%d %d %d\n",x,y,z);
  return 0;
}
