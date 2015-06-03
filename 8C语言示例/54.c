#include <stdio.h>
main()
{
  unsigned a,b,c,d;
  printf ("please input a number:\n");
  scanf("%o",&a);
  b=a>>4;
  c=~(~0<<4);
  d=b&c;
  printf ("%o\n%d\n",a,d);
}
