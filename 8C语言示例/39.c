#include <stdio.h>
int main(int argc, char *argv[])
{
  int a[10]={1,4,6,9,13,16,19,28,40,100};
  int i,j,number,temp1,temp2;
  printf ("original array is:\n");
  for(i=0;i<10;i++)
    printf ("%d\n",a[i]);
  printf ("\n");
  printf ("please input a insert number:");
  scanf("%d",&number);
  if(number>a[9])
    a[10]=number;
  else 
    {
      for (i=0;i<10 ; ++i)
{
  if (number<a[i])
    {
      temp1=a[i];
      a[i]=number;
      for (j=i+1; j<=10; j++)
	{
	  temp2=a[j];
	  a[j]=temp1;
	  temp1=temp2;
	}
      break;
    }
 }
    }
  for(i=0;i<=10;i++)
    printf ("%d\n",a[i]);
  return 0;
}
