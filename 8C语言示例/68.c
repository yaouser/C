#include <stdio.h>
int main(int argc, char *argv[])
{
  int number[20],n,m,i;
  printf ("the total numbers is:");
  scanf("%d",&n);
  printf ("back m:");
  scanf("%d",&m);
  for(i=0;i<n-1;i++)
    scanf("%d",&number[i]);
  scanf("%d",&number[n-1]);
  move(number,n,m);
  for(i=0;i<n-1;i++) 
    printf ("%d",number[i]);
  printf ("%d",number[n-1]);
  return 0;
}
move(int array[20],int n,int m)
{
  int *p,array_end;
  array_end=*(array+n-1);
  for (p=array+n-1; p>array; p--)
    {
      *p=*(p-1);
      *array=array_end;
      m--;
    }
}
