/****************************************
技巧11：特殊等式 xyz+yzz=532
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int x,y,z,i;
  for (x=1; x<10; x++)
      for (y=1; y<10; y++)
	  for (z=0; z<10; z++)
	    {
	      i=100*x+10*y+z+100*y+10*z+z;
	      if(i==532)
		printf ("x=%d,y=%d,z=%d\n",x,y,z);
	    }
  return 0;
}
*/
/****************************************
技巧12：统计各种字符个数
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  char c;
  int letter=0,digit=0,space=0,other=0;
  printf ("please input some characters\n");
  //当输入的不是回车时执行while循环体
  while((c=getchar())!='\n')
    {
      if(c>='a'&&c<='z'||c>='A'&&c<='Z')
	letter++;
      else if(c>='0'&&c<='9')
	digit++;
      else if(c==' ')
	space++;
      else
	other++;
    }
  printf ("letter=%d,digit=%d,space=%d,other=%d\n",letter,digit,space,other);
  return 0;
}
 */
/****************************************
技巧13：猴子吃桃
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int day,x1,x2;
  day=9;
  x2=1;
  while(day>0)
    {
      x1=(x2+1)*2;
      x2=x1;
      day--;
    }
  printf ("the total is %d\n",x1);
  return 0;
}
  */
/****************************************
技巧14：删除字符串中连续字符
****************************************/
   /*
#include <stdio.h>
char del(char s[],int pos,int len)   //自定义删除函数，这里采用覆盖方法
 {
   int i;
   for (i=pos+len-1; s[i]!='\0'; i++,pos++)
     s[pos-1]=s[i];   //用删除部分后的字符依次从删除部分开始覆盖
   s[pos-1]='\0';
   return s;
 }
int main(int argc, char *argv[])
{
  char str[50];
  int position,length;
  printf ("please input string:\n");
  gets(str);   //使用gets函数获得字符串
  printf ("please input delete position:");
  scanf("%d",&position);
  printf ("please input delete length:");
  scanf("%d",&length);
  del(str,position,length);
  printf ("the final string:%s\n",str);
  return 0;
}
   */
/****************************************
技巧15：求同学的平均身高
****************************************/
/*
#include <stdio.h>
float average(float array[],int n)
{
  int i;
  float aver,sum=0;
  for(i=0;i<n;i++)
    sum+=array[i];
  aver=sum/n;
  return(aver);
}
int main(int argc, char *argv[])
{
  float average(float array[],int n);
  float height[100],aver;
  int i,n;
  printf ("please input the number of students:\n");
  scanf("%d",&n);
  printf ("please input student's height:\n");
  for(i=0;i<n;i++)
    scanf("%f",&height[i]);
  printf ("\n");
  aver=average(height,n);
  printf ("average height is %6.2f\n",aver);
  return 0;
}
*/
/****************************************
技巧16：灯塔数量（利用了穷举发）
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int n=1,m,sum,i;
  while(1)
    {
      m=n;
      sum=0;
      for (i=1; i<8; i++)
{
  m=m*2;
  sum+=m;
 }
      sum+=n;
      if (sum==765)
{
  printf ("the first floor has %d\n",n);
  printf ("the eight floor has %d\n",m);
  break;
 }
      n++;
    }
  return 0;
}
*/
/****************************************
技巧17：老师分糖果
****************************************/

/****************************************
技巧18：小球下落问题
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  float i,h=100,s=100;
  for (i=1; i<=9; i++)
    {
      h=h/2;
      s+=h*2;
    }
  printf ("the total length is %f\n",s);
  printf ("the lenght of tenth time is %f\n",h/2);
  return 0;
}
 */
/****************************************
技巧19:彩球问题
****************************************/

#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j,count;
  puts("the result is:\n");   //向屏幕上输出提示信息
  printf ("time  red ball  white ball  black ball\n");
  count = 1;
  for(i=0;i<=3;i++)
    for(j=0;j<=3;j++)
      if((8-i-j)<=6)
	printf ("%3d%7d%12d%12d\n",count++,i,j,8-i-j);
  return 0;
}

