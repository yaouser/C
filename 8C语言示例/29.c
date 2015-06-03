#include <stdio.h>
int main(int argc, char *argv[])
{
  long a,b,c,d,e,x;
  scanf("%ld",&x);
  a=x/10000;
  b=x%10000/1000;
  c=x%1000/100;
  d=x%100/10;
  e=x%10;
  if(a!=0)
    printf ("there are 5   %ld,%ld,%ld,%ld,%ld\n",e,d,c,b,a);
  else if(b!=0)
    printf ("there are 4   %ld,%ld,%ld,%ld\n",e,d,c,b);
  else if(c!=0)
    printf ("there are 3   %ld,%ld,%ld\n",e,d,c);
  else if(b!=0)
    printf ("there are 2   %ld,%ld\n",e,d);
  else if(a!=0)
    printf ("there are 1   %ld\n",e);
  return 0;
}
