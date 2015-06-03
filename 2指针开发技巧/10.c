/****************************************
技巧01：使用指针实现整数排序
****************************************/
/*
#include <stdio.h>
swap(int *p1,int *p2)
{
  int temp;
  temp=*p1;
  *p1=*p2;
  *p2=temp;
}
exchange(int *pt1,int *pt2,int *pt3)
{
  if(*pt1<*pt2)
    swap(pt1,pt2);
  if(*pt1<*pt3)
    swap(pt1,pt3);
  if(*pt2<*pt3)
    swap(pt2,pt3);
}
int main(int argc, char *argv[])
{
  int a,b,c,*q1,*q2,*q3;
  puts("please input three key numbers you want to rank:");
  scanf("%d%d%d",&a,&b,&c);
  q1=&a;
  q2=&b;
  q3=&c;
  exchange(q1,q2,q3);
  printf ("%d,%d,%d\n",a,b,c);
  puts("press any key to quit ...");
  return 0;
}
*/
/****************************************
技巧02:使用指针实现数据交换
****************************************/
/*
#include <stdio.h>
swap(int *p1,int *p2)
{
  int temp;
  temp=*p1;
  *p1=*p2;
  *p2=temp;
}
int main(int argc, char *argv[])
{
  int a,b;
  int *pointer1,*pointer2;
  printf ("please input two swap numbers:\n");
  scanf("%d%d",&a,&b);
  pointer1=&a;
  pointer2=&b;
  swap(pointer1,pointer2);
  printf ("the result is :%d,%d\n",a,b);
  return 0;
}
*/
/****************************************
技巧03：指向结构体变量的指针
****************************************/
/*
#include <stdio.h>
struct student   //自定义结构体
{
  int num;       //学生学号
  char name[20]; //学生姓名,数组字符串
  char sex;      //学生性别，字符
  int age;       //学生年龄
  float score;   //学生成绩
};
int main(int argc, char *argv[])
{
  //字符串用双引号，字符用单引号
  struct student student1={1001,"liming",'M',20,92.5};//定义结构体变量
  struct student *p;           //定义指针变量指向结构体类型
  p=&student1;
  printf ("number:%d\n",p->num);
  printf ("name:%s\n",p->name);
  printf ("sex:%c\n",p->sex);
  printf ("age:%d\n",p->age);
  printf ("score:%f\n",p->score);
  return 0;
}
*/
/****************************************
技巧04:使用指针输出数组元素
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int a[10];
  int *p,i;
  puts("please input ten integer:\n");
  for(i=1;i<=10;i++)
    scanf("%d",&a[i]);
  printf ("\n");
  for(p=&a;p<(a+10);p++)
    printf ("%d ",*p);
  return 0;
}
*/
/****************************************
技巧05：用指针实现逆序存放数组元素值
****************************************/
 /*
#include <stdio.h>
inverte(int *x,int n)
{
  int *p,temp,*i,*j,m=(n-1)/2;
  i=x;
  j=x+n-1;
  p=x+m;
  for (i=x;i<=p;i++,j--)
    {
      temp=*i;
      *i=*j;
      *j=temp;
    }
  return 0;
}
int main(int argc, char *argv[])
{
  int i,a[10]=
    {1,2,3,4,5,6,7,8,9,0};
  printf ("the elements of original array:\n");
  for(i=0;i<10;i++)
    printf ("%d ",a[i]);
  printf ("\n");
  inverte(a,10);
  printf ("the elements has been inverted:\n");
  for(i=0;i<10;i++)
    printf ("%d ",a[i]);
  printf ("\n");
  return 0;
}
 */
/****************************************
技巧06：使用指针查找数列中最大值/最小值
****************************************/
/*
#include <stdio.h>
void max_min(int a[],int n,int *max,int *min)
{
  int *p;
  *max=*min=*a;
  for(p=a+1;p<a+n;p++)
    {  
      if(*p>*max)
	*max=*p;
      else if(*p<*min)
	*min=*p;
    }
  return 0;
}
int main(int argc, char *argv[])
{
  int i,a[10];
  int max,min;
  printf ("input 10 integer numbers you want to operate:\n");
  for(i=0;i<10;i++)
    scanf("%d",&a[i]);
  max_min(a,10,&max,&min);
  printf ("the maximun number is:%d\n",max);
  printf ("the maxinun number is:%d\n",min);
  return 0;
}
*/
/****************************************
技巧07：使用指针实现字符串复制(复制函数没有写成功）
****************************************/
/*
#include <stdio.h>
copy(char *s,char *q)
{
  int i=0;
  for (;*s!='\0';)
    {
      *q=*s;
      s++;
      q++;
    }
  *q='\0';
}
main()
{
  char *str,*p;
  str="hello world!";
  copy(str,p);
  printf ("%s",p);
  return 0;
}
*/
/****************************************
技巧08：使用指针实现字符串的连接(段错误，未成功）
****************************************/
/*
#include <stdio.h>
connect(char *s,char *t,char *q)
{
  int i=0;
  for ( ; *s!='\0';  )
    {
      *q=*s;
      s++;
      q++;
    }
  for ( ; *t!='\0';  )
    {
      *q=*t;
      t++;
      q++;
    }
  *q='\0';
}
int main(int argc, char *argv[])
{
  char *str,*t,*p;
  str="one world";
  t="one dream";
  printf ("the first string is:%s\n",str);
  printf ("the second string is:%s\n",t);
  connect(str,t,p);
  printf ("the connected string is:\n");
  printf ("%s",p);
  return 0;
}
*/
/****************************************
技巧09：使用指针实现字符串插入(未成功）
****************************************/
/*
#include <stdio.h>
#include <string.h>
insert(char *s,char *q,int n)
{
  int i=0;
  char *str,strcp[50];
  str=strcp;
  for (i=0; *s!='\0'; i++)
    {
      if (i==n-1)
	{
	  for (; q!='\0'; )
	    {
	      str[1]=*q;
	      q++;
	      i++;
	    }
	}
      str[i]=*s;
      s++;
    }
  str[i+1]='\0';
  return str;
}
int main(int argc, char *argv[])
{
  char *strin,*str;
  int i;
  str="hello world!";
  strin ="big";
  printf ("please input the position you want to insert:");
  scanf("%d",&i);
  str=insert(str,strin,i);
  printf ("%s\n",str);
  return 0;
}
*/
/****************************************
技巧10：使用指针实现字符串的匹配
****************************************/
/*
#include <stdio.h>
#include <string.h>
int match(char *B,char *A)
{
  int i,j,start=0;
  int lastB=strlen(B)-1;
  int lastA=strlen(A)-1;
  int endmatch =lastA;
  for (j=0; endmatch<=lastB; endmatch++,start++)
    {
      if(B[endmatch]==A[lastA])
	for(j=0,i=start;j<lastA&&B[i]==A[j];)
	  i++,j++;
      if (j==lastA)
{
  return (start+1);
 }
    }
  if (endmatch>lastB)
    {
      printf ("the string is not matchable!\n");
      return -1;
    }
}
int main(int argc, char *argv[])
{
  char s[]="one world,one dream";
  char t[]="world";
  int p = match(s,t);
  if (p!=-1)
    {
      printf ("Matchable!\n");
      printf ("the start position is %d\n",p);
    }
  printf ("\n");
  return 0;
}
*/

