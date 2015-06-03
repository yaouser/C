/****************************************
技巧11：一数三平方
****************************************/
/*
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
  long i,n,n1,n2,n3,n4,count=0;
  printf ("the result is:\n");
  for (i=100000; i<=999999; i++)
    {
      n=(long)sqrt(i);
      if (i==n*n)
	{
	  n1=i/1000;
	  n2=i%1000;
	  n3=(long)sqrt(n1);
	  n4=(long)sqrt(n2);
	  if (n1==n3*n3&&n2==n4*n4)
	    {
	      count++;
	      printf ("%ld\n",i);
	    }
	}
    }
  printf ("total is : %ld\n",count);
  return 0;
}
*/
/****************************************
技巧12:求等差数列
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j,number,n;
  for(number=1;number<6;number++)
    for(n=1;n<4;n++)
      if ((4*number+6*n==26)&&number*(number+n)*(number+2*n)
	  *(number+3*n)==880)
	{
	  printf ("the result is:\n");
	  for (j=1; j<=20; j++)
	    {
	      printf ("%3d",number);
	      number+=n;
	      if(j%5==0)
		printf ("\n");
	    }
	}
  return 0;
}
 */
/****************************************
技巧13：求整数的绝对值
****************************************/
  /*
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
 {
   int i;
   printf ("please input a number:\n");
   scanf("%d",&i);
   printf ("number:%d\nabsolute value:%d\n",i,abs(i));
   return 0;
 }
  */
/****************************************
技巧14：正玄，余玄，正切值
****************************************/
  /*
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
 {
   float n;
   printf ("please input:\n");
   scanf("%f",&n);
   printf ("the sin of %f is %f\n",n,sin(n));
   printf ("the con of %f is %f\n",n,cos(n));
   printf ("the tan of %f is %f\n",n,tan(n));
   return 0;
 }
  */
/****************************************
技巧15：自然对数的底e的计算 e=1+1/1!+1/2!+1/3!+...
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   float e=1.0,n=1.0;
   int i=1;
   while(1/n>1e-10)
     {
       e+=1/n;
       i++;
       n=i*n;
     }
   printf ("the value of e is %f\n",e);
   return 0;
 }
  */
/****************************************
技巧16：最大公约数及最小公倍数
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   int a,b,c,m,t;
   printf ("please input two numbers:\n");
   scanf("%d%d",&a,&b);
   if (a<b)
     {
       t=a;
       a=b;
       b=t;
     }
   m=a*b;
   c=a%b;
   while(c!=0)   //求最小公约数
     {
       a=b;
       b=c;
       c=a%b;
     }
   printf ("the max commen divisor:%d\n",b);     //输出最小公约数
   printf ("the min commen multiple:%d\n",m/b);  //输出最小公倍数
   return 0;
 }
  */
/****************************************
技巧17：求解二元一次不定方程
****************************************/



/****************************************
技巧18：二分法求解方程
****************************************/
  /*
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
 {
   float x0,x1,x2,f0,f1,f2;
   do
     {
       printf ("enter x1,x2:\n");
       scanf("%f,%f",&x1,&x2);
       f1=sin(x1);
       f2=sin(x2);
     } while (f1*f2>0);    //判断是否有根，若无根重新输入范围
   do
     {
       x0=(x1+x2)/2;       //取中间值
       f0=sin(x0);
       if ((f0*f1)<0)      //判断根在那个范围内
	 {
	   x2=x0;          //范围在（x1，x0）
	   f2=f0;
	 }
       else
	 {
	   x1=x0;          //范围在（x0，x1）
	   f1=f0;
	 }
     } while (fabs(f0)>=1e-5); //判断是否大于精度10的负5次方
   printf ("x=%6.2f\n",x0);
   return 0;
 }
  */
/****************************************
技巧19：牛顿迭代法解方程的根（牛顿迭代公式）
****************************************/
  /*
#include <stdio.h>
#include <math.h>
  //自定义Newton函数，实现迭代法求解方程的根
 float Newton(float a,float b,float c,float d)
 {
   float x=1,x0,f,f1;
   do
     {
       x0=x;
       f=((a*x0+b)*x0+c)*x0+d;  //三元一次方程，求出f（x0）
       f1=(3*a*x0+2*b)*x0+c;    //求f（x0）的导数
       x=x0-f/f1;               //套用牛顿迭代公式
     } while (fabs(x-x0)>=1e-5);
   return (x);
 }
int main(int argc, char *argv[])
{
  float a,b,c,d;
  printf ("please input four numbers a b c d:\n");
  scanf("%f%f%f%f",&a,&b,&c,&d);
  printf ("%.2fx^3+%.2fx^2+%.2fx+%.2f=0\n",a,b,c,d);
  printf ("x=%.5f\n",Newton(a,b,c,d));
  return 0;
}
  */
/****************************************
技巧20：打印特殊方阵
****************************************/

#include <stdio.h>
main()
{
  int a[10][10],i,j;
  for(i=1;i<=5;i++)
    for (j=1; j<=10-i; j++)
      {
	a[i][j]=i;
	a[10-i][j]=i;
	a[j][i]=i;
	a[j][10-i]=i;
      }
  for (i=1; i<=9; i++)
    {
      for(j=1;j<=9;j++)
	printf ("%d ",a[i][j]);
      printf ("\n");
    }
  return 0;
}

