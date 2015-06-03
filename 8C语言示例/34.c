#include <stdio.h>
void hello_world(void)
{
  printf ("hello, world!\n");
}
void three_hellos(void)
{
  int counter;
  for (counter=1; counter<=3; counter++)
    {
      hello_world();
    }
}
int main(int argc, char *argv[])
{
  three_hellos();
  return 0;
}
