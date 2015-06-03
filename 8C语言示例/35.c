#include <stdio.h>
int main(int argc, char *argv[])
{
  int color;
  for (color=1; color<=16; color++)
    {
      textcolor(color);
      printf ("this is color %d\n",color);
    }
  textcolor(128+15);
  printf ("this is blinking\n");
  return 0;
}
