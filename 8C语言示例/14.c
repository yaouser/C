#include <stdio.h>
int main(void)
{
  int n,i;
  printf ("please input a number:\n");
  scanf("%d=",&n);
  printf ("%d=",n);
  for(i=2;i<=n;i++)
    while(n!=i)
      {
	if (n%i==0)
	  {
	    printf ("%d*",i);
	    n=n/i;
	  }
	else
	  break;
      }
  printf ("%d",n);
  return 0;
}
