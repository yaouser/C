#include <stdio.h>
int main(int argc, char *argv[])
{
  int i=7;
  printf ("(please input 7 charater) :");
  void palin(int n);
  palin(i);
  printf ("\n");
  return 0;
}

void palin(n)
{
  char next;
  if (n<=1)
    {
      next=getchar();
      printf ("\n");
      putchar(next);
    }
  else
    {
      next=getchar();
      palin(n-1);
      putchar(next);
    }
}
