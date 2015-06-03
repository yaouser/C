/****************************************
技巧21：求3*3矩阵对角元素之和
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int a[4][4],i,j,sum=0;
  printf ("please input numbers:\n");
  for(i=1;i<=3;i++)
    for(j=1;j<=3;j++)
      scanf("%d",&a[i][j]);
  printf ("this 3*3 matrix is:\n");
  for (i=1; i<=3; i++)
    {
      for(j=1;j<=3;j++)
	printf ("%d ",a[i][j]);
      printf ("\n");
    }
  for (i=1; i<=3; i++)
      for(j=1;j<=3;j++)
	if(i==j)
	  sum+=a[i][j];
      printf ("diagonal's sum is %d\n",sum);
  return 0;
}
*/
/****************************************
技巧22：矩阵的加法运算
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int a[3][3],b[3][3],c[3][3],i,j;
  printf ("please input matrix a:\n");
  for(i=0;i<=2;i++)
    for(j=0;j<=2;j++)
      scanf("%d",&a[i][j]);
  printf ("please input matrix b:\n");  
  for(i=0;i<=2;i++)
    for(j=0;j<=2;j++)
      scanf("%d",&b[i][j]);
  for(i=0;i<=2;i++)
    for(j=0;j<=2;j++)
      c[i][j]=a[i][j]+b[i][j];
  printf ("the sum is:\n");
  for (i=0; i<=2; i++)
    {
      for(j=0;j<=2;j++)
	printf ("%d ",c[i][j]);
      printf ("\n");
    }
  return 0;
}
 */
/****************************************
技巧23：矩阵的乘法运算
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   int a[2][3],b[3][2],c[2][2],i,j,k,sum;
   printf ("please input martrix a:\n");
   for(i=0;i<=1;i++)
     for(j=0;j<=2;j++)
       scanf("%d",&a[i][j]);    //输入2*3矩阵到数组a中
   printf ("please input martrix b:\n");
   for(i=0;i<=2;i++)
     for(j=0;j<=1;j++)
       scanf("%d",&b[i][j]);    //输入3*2矩阵到数组b中
   for(i=0;i<=1;i++)            //a矩阵的行数
     for(k=0;k<=1;k++)          //b矩阵的列数
       {
	 sum=0;
	 for(j=0;j<=2;j++)
	   sum+=a[i][j]*b[j][k];
	 c[i][k]=sum;          //每次求得的和放入指定的行列中
       }
   printf ("the product is:\n");
   for (i=0; i<=1; i++)
     {
       for(j=0;j<=1;j++)
	 printf ("%d ",c[i][j]);
       printf ("\n");
     }
   return 0;
 }
  */
/****************************************
技巧24：打印n阶螺旋方阵
上面a[i][j]右面a[j][n-i-1]下面a[n-i-1]左面a[j][i]
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   int i,j,k=0,a[10][10],m,n;
   printf ("please input n:\n");
   scanf("%d",&n);
   if(n%2==0)
     m=n/2;                //判断是否为偶数
   else
     m=n/2+1;
   for (i=0; i<m; i++)
     {
       for (j=i; j<n-i; j++)
	 {
	   k++;
	   a[i][j]=k;   //将每圈中上面的行中的数据存入数组中
	 }
       for (j=i+1; j<n-i; j++)
	 {
	   k++;
	   a[j][n-i-1]=k;    //将每圈中右面的列中的数据存入数组中
	 }
       for (j=n-i-2; j>=i; j--)
	 {
	   k++;
	   a[n-i-1][j]=k;    //将每圈中下面行中的数据存入数组中
	 }
       for (j=n-i-2; j>=i+1; j--)
	 {
	   k++;
	   a[j][i]=k;       //将每圈中左面的列中的数据存入数组中
	 }
     }
   for (i=0; i<n; i++)
     {
       for(j=0;j<n;j++)
	 printf ("%d\t",a[i][j]);
       printf ("\n");
     }
   return 0;
 }
  */
/****************************************
技巧25：求车运行速度(没有很好的运行）
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   int j=0,a[5];
   long k=100000,i=95860;
   while(1)
     {
       k=100000;
       while(k>=10)
	 {
	   a[j]=(i%k)/(k/10);
	   k/=10;
	   j++;
	 }
       if ((a[0]==a[4])&&(a[1]==a[3]))
	 {
	   printf ("the new number kelometers is:%d%d%d%d%\n",
		   a[0],a[1],a[2],a[3],a[4]);
	   printf ("an average speed is:%.2f\n",(i-95859)/2.0);
	 }
       break;
     }
   i++;
   return 0;
 }
  */
/****************************************
技巧26:分西瓜
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   int day,x1,x2;
   day=0;
   x1=1020;
   while(x1)
     {
       x2=x1/2-2;
       x1=x2;
       day++;
     }
   printf ("day=%d\n",day);
   return 0;
 }
  */
/****************************************
技巧27：巧分苹果
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   int x[7],y[7],s,i;
   s=2520/6;
   for (i=2; i<=6; i++)
     //求从老二到老六得到哥哥分来的苹果却未分给弟弟时的苹果数
     y[i]=s*(9-i)/(8-i);
   y[1]=x[1]=(s-y[6]/3)*8/7;
   //老大得到老六分来的苹果却未分给弟弟的苹果数   
   for(i=2;i<=6;i++)
     x[i]=y[i]-y[i-1]/(10-i);
   for(i=1;i<=6;i++)
     printf ("x[%d]=%d\n",i,x[i]);
   return 0;
 }
  */

