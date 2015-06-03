/****************************************
技巧01:求100-200之间的素数
****************************************/
/*
#include <stdio.h>
#include <math.h>
main()
{
  int i,j,n=0;
  for(i=100;i<=200;i++)
    for(j=2;j<=sqrt(i);j++)
      if(i%j==0)
	break;
      else if(j>sqrt(i)-1)
	{
	  printf ("%d ",i);
	  n++;
	  if(n%5==0)
	    printf ("\n");
	}
  return 0;
}
*/
/****************************************
技巧02：可逆素数
****************************************/
 /*
#include <stdio.h>
#include <math.h>
 //自定义ss函数，作用是判断一个数是否为素数
int ss(int i)
{
  int j;
  if(i<=1)      //小于1的数不是素数
    return 0;
  if(i==2)      //2是素数
    return 1;
  for (j=2; j<i; j++)    //对大于2的数进行判断
    {
      if(i%j==0)
	return 0;
      else if(i!=j+1)
	continue;
      else
	return 1;
    }
}
int main(int argc, char *argv[])
{
  int i,n=0,n1,n2,n3,n4;
  for(i=1000;i<10000;i++)
    if (ss(i)==1)
      {
	n4=i%10;
	n3=(i%100)/10;
	n2=(i/100)%10;
	n1=i/1000;
	if(ss(1000*n4+100*n3+10*n2+n1)==1
	   &&1000*n4+100*n3+10*n2+n1>i)
	  {
	    printf ("%d ",i);
	    n++;
	    if(n%10==0)
	      printf ("\n");
	  }
      }
  return 0;
}
*/
/****************************************
技巧03:回文素数
****************************************/
/*
#include <stdio.h>
int ss(int i)
{
  int j;
  if(i<=1)
    return 0;
  if(i==2)
    return 1;
  for (j=2; j<i; j++)
    {
      if(i%j==0)
	return 0;
      else if(i!=j+1)
	continue;
      else
	return 1;
    }
}
int main(int argc, char *argv[])
{
  int i;
  for (i=10; i<1000; i++)
    if(ss(i)==1)         //判断是否是素数
      if (i/100==0)      //判断是否是两位数
	{
	  if (i/10==i%10)  //判断十位和各位是否相同
	    printf ("%5d ",i);
	}
      else
	if(i/100==i%10)    //判断百位和各位是否相同
	  printf ("%5d ",i);
  return 0;
}
*/
/****************************************
技巧04：特殊的完全平方数
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j;
  int hun,ten,data;
  printf ("the result is:\n");
  for (i=100; i<=999; i++)
    {
      j=10;
      while(j*j<=i)
	{
	  if (i==j*j)
	    {
	      hun=i/100;
	      ten=i%100/10;
	      data=i%10;
	      if(hun==ten||hun==data||ten==data)
		printf ("%5d ",i);
	    }
	  j++;
	}
    }
  return 0;
}
*/
/****************************************
技巧05：求1000以内的玩数
****************************************/
 /*
#include <stdio.h>
main()
{
  int i,j,sum=0;
  for (i=1; i<1000; i++)
    {
      sum=0;
      for(j=1;j<i;j++)
	if(i%j==0)
	  sum+=j;
      if(sum==i)
	printf ("%4d ",i);
    }
  return 0;
}
 */
/****************************************
技巧06：三重回文数(未成功）
****************************************/
  /*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
  //自定义judge函数，用来判断一个数是否是回文数
 int judge(long n)
{
  int i,len,half;
  char a[20];
  ltoa(n,a,10);  //把常整形n转换成字符串存到数组a中
  len=strlen(a);
  half=len/2;
  for(i=0;i<half;i++)
    if(a[i]!=a[--len])//判断相对应位置的字符串是否相同
      break;
  if (i>=half)
    return 1;
  else 
    return 0;
}
int main(int argc, char *argv[])
{
  long n;
  printf ("the result is:\n");
  for(n=11;n<1000;n++)
    if(judge(n)&&judge(n*n)&&judge(n*n*n))//判断三重回文数
      printf ("n=%ld\tn*n=%ld\tn*n*n=%ld\n",n,n*n,n*n*n);
  return 0;
}
  */
/****************************************
技巧07：亲密数
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j,k,sum1,sum2;
  for (i=1; i<=10000; i++)
    {
      sum1=0;
      sum2=0;
      for(j=1;j<i;j++)
	if(i%j==0)
	  sum1+=j;
      for(k=1;k<sum1;k++)
	if(sum1%k==0)
	  sum2+=k;
      if(sum2==i&&i!=sum1&&i<sum1)//判断亲密数
	printf ("%5d=>%5d\n",i,sum1);
    }
  return 0;
}
*/
/****************************************
技巧08：自守数（没写完）
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  long i,j,k1,k2,k3,a[10]={0},num,m,n,sum;
  printf ("please input a number:\n");
  scanf("%ld",&num);
  printf ("the result is:\n");
  for (j=0; j<num; j++)
    {
      m=j;
      n=1;
      sum=0;
      k1=10;
      k2=1;
      while(m!=0)  //判断该数的位置
	{
	  a[n]=j%k1;
	  
	}
    }
  return 0;
}
 */
/****************************************
技巧09：满足abcd=（ab+cd）^2的数
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,a,b;
  for (i=1000; i<10000; i++)
    {
      a=i/100;   //求出该数的前两位数；
      b=i%100;   //求出该数的后两位数；
      if((a+b)*(a+b)==i)
	printf ("%5d\n",i);
    }
  return 0;
}
  */
/****************************************
技巧10：神奇的数字6174
****************************************/
   /*
#include <stdio.h>
   //自定义函数，实现求最大4位数与最小数的差
  int difference(int a[])
{
  int t,i,j,sum,sum1,sum2;
  for(i=0;i<3;i++)
    for(j=i+1;j<4;j++)
      if (a[i]<a[j])
	{
	  t=a[i];
	  a[i]=a[j];
	  a[j]=t;
	}
  sum1=a[0]*1000+a[1]*100+a[2]*10+a[3];
  sum2=a[3]*1000+a[2]*100+a[1]*10+a[0];
  sum=sum1-sum2;
  printf ("%5d=%5d-%5d\n",sum,sum1,sum2);
  return sum;
}
int main(int argc, char *argv[])
{
  int n,a[4];
  printf ("please input a number:\n");
  scanf("%d",&n);
  while(n!=6174)
    {
      a[0]=n/1000;
      a[1]=n/100%10;
      a[2]=n/10%10;
      a[3]=n%10;
      n=difference(a);
    }
  return 0;
}
   */

