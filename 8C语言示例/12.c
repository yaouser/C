#include<stdio.h> 
int is_prime(int n)
{
  int i;
  for(i=2;i<n;i++)
    if(n%i == 0)
      break;
  if(i==n)
    return 1;
  else 
    return 0;
}
int main(void)
{
  int i,j=0;
  for (i=101; i <= 200; i++)
    {
      if(!is_prime(i))
	continue;
      printf ("%d\t",i);
      j++;
      if(j%8==0&&j!=0)
	printf ("\n");
    }
  printf ("Total:%d\n",j);
  return 0;
}
/*break的用法是跳出循环体
  continue语句终止当前循环后又回到循环体的开头准备执行下一次循环*/
