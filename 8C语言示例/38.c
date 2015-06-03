#include <stdio.h>
int main(int argc, char *argv[])
{
  float a[3][3],sum=0;
  int i,j;
  printf ("please input rectangle element:\n");
  for(i=0;i<3;i++)
    for(j=0;j<3 ;j++ )
      {
	printf ("a[%d][%d]=",i,j);
	scanf("%f",&a[i][j]);
	if(i==j)
	  {
	    sum+=a[i][j];
	  }
      }
  printf ("dui jiao xian he is %6.2f\n",sum);
  return 0;
}
