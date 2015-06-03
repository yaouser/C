#include <stdio.h>
int main()
{
  int number[10];
  input(number);
  max_min(number);
  output(number);
  return 0;
}
input(int number)
{
  int i;
  for (i=0; i<=9; i++)
    {
      scanf("%d",&number);
    }
}
max_min(int array[10])
{
  int *max,*min,k,l;
  int *p,*arr_end;
  max=min=array;
  for (p=array+1; p<arr_end+10; p++)
    {
      if(*p>*max)
	  max=p;
      else if(*p<*min) 
	min=p;
      k=*max; l=*min;
      *p=array[0]; array[0]=k; k=*p;
      *p=array[9]; array[9]=l; l=*p;
    }
  return 1;
}
output(int array[10])
{
  int *p;
  for (p=array; p<array+9; p++)
    {
      printf ("%d",*p);
    }
  printf ("%d\n",array[9]);
}

//没有很好的运行
