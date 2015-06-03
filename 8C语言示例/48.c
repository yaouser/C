#include <stdio.h>
#define LAG >
#define SMA <
#define EQ ==
void main()
{
  int i=10;
  int j=20;
  if(i LAG j)
    printf ("%d large than %d\n",i,j);
  else if(i EQ j)
    printf ("%d equal to %d\n",i,j);
  else if(i SMA j)
    printf ("%d small than %d\n",i,j);
  else 
    printf ("no such value\n");
}
