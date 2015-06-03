/****************************************
技巧11：用指向函数的指针比较大小
一个函数在编译时被分配一个入口地址，这个地址就称为
函数的指针。所以可以使用指针变量指向一个函数，然后
通过该指针变量调用这个函数。
****************************************/
/*
#include <stdio.h>
min(int a,int b)
{
  if(a<b)
    return a;
  else 
    return b;
}
int main(int argc, char *argv[])
{
  int(*pmin)();     //定义指针
  int a,b,m;
  pmin = min;  //函数指针变量赋值，只用给出函数名即可
  printf ("please input two integer numbers:\n");
  scanf("%d%d",&a,&b);
  m = (*pmin)(a,b);
  printf ("min=%d\n",m);
  return 0;
}
*/
/****************************************
技巧12：使用返回指针的函数查找最大值
****************************************/
/*
#include <stdio.h>
*FindMax(int *p,int n)  //定义指针函数
{
  int i, *max;
  max=p;
  for(i=0;i<n;i++)
    if(*(p+i)>*max)
      max=p+i;
  return max;
}
int main(int argc, char *argv[])
{
  int a[10],*max,i;
  printf ("please input ten integer:\n");
  for (i=0; i<10; i++)
    {
      scanf("%d",&a[i]);
    }
  max = FindMax(a,10);
  printf ("the max number is: %d\n",*max);
  return 0;
}
*/
/****************************************
技巧13：用指针函数实现求学生成绩
****************************************/
/*
#include <stdio.h>
float *search(float(*p)[4],int n)
{
  float *pt;
  pt = *(p+n);
  return (pt);
}
int main(int argc, char *argv[])
{
  float score[][4]={
    {60,75,82,91},
    {75,81,91,90},
    {51,65,78,84},
    {65,51,78,72},
  };
  float *p;
  int i,j;
  printf ("enter the student's number you want to search:");
  scanf("%d",&j);
  printf ("this student's scores are:\n");
  p = search(score,j-1);
  for(i=0;i<4;i++)
    printf ("%5.1f\t",*p);
  printf ("\n");
  return 0;
}
*/
/****************************************
技巧14：寻找指定元素的指针（程序没能很好运行）
****************************************/
/*
#include <stdio.h>
int a[]=
{
  1,2,3,4,5,6,7,8,9,10,20,30,40,50,60
};
search(int *pt,int n,int key)
{
  int *p;
  for(p=pt;p<pt+n;p++)
    if(*p==key)
      return (p-pt);
}
*find(int *pt,int n,int key)
{
  int *p;
  for(p=pt;p<pt+n;p++)
    if(*p==key)
      return p;
  return 0;
}
main()
{
  int i,key;
  int *j;
  printf ("the elements of array a:\n");
  for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
    printf ("%d ",a[i]);
  printf ("\nthe address of a[0] is:%x\n",&a[0]);
  printf ("please input the key number you want to search:");
  i=search(a,sizeof(a)/sizeof(a[0]),key);
  scanf("%d",&key);
  printf ("the label number of the key number %d in the array is:%d\n",key,i);
  j=find(a,sizeof(a)/sizeof(a[0]),key);
  printf ("the point value of the key number %d in the array is:%x\n",key,j);
  return 0;
}
*/
/****************************************
技巧15：寻找相同元素的指针
****************************************/
/*
#include <stdio.h>
int *find(int *pa,int *pb,int an,int bn)
{
  int *pta,*ptb;
  pta=pa;ptb=pb;
  while(pta<pa+an&&ptb<pb+bn)
    {
      if (*pta<*ptb)
	pta++;
      else if(*pta>*ptb)
	ptb++;
      else 
	return pta;
    }
  return 0;
}
int main(int argc, char *argv[])
{
  int *p,i;
  int a[]=
    {
      1,3,5,7,9,13,15
    };
  int b[]=
    {
      2,4,6,8,11,15,17
    };
  printf ("the elemens of array a:\n");
  for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
    printf ("%d ",a[i]);
  printf ("\nthe elements of array b:\n");
  for(i=0;i<sizeof(b)/sizeof(b[0]);i++)
    printf ("%d ",b[i]);
  p=find(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]));
  if(p)
    printf ("\nthe first element in both arrays is %d\n",*p);
  else
    printf ("doesn't found the same element!\n");
  return 0;
}
*/
/****************************************
技巧16：使用指针的指针输出字符串
****************************************/
/****************************************
 **p就相当与*（*p），*p表示p所指向的另一个指针变量
，即一个地址。**p是p间接指向的对象的值。
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  char *strings[]={"Clanguage",
		   "Basic",
		   "World wide",
		   "Olympic",
		   "Great wall"};  //使用指针数组创建字符串数组
  char **p,i;
  p=strings;    //指针指向字符串数组首地址
  for (i=0; i<5; i++)
    {
      printf ("%s\n",*(p+1));
    }
  return 0;
}
*/
/****************************************
技巧17：实现输入月份输出该月份英文名
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  char *Month[]={
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "Junly",
    "August",
    "September",
    "October",
    "Nobember",
    "December"
  };
  int i;
  char **p;  //声明指向指针的指针变量
  p=Month;   //将数组首地址值附给指针变量
  printf ("Input a number for month\n");
  scanf("%d",&i);
  printf ("the month is:");
  printf ("%s\n",*(p+i-1));  //使用指向指针的指针输出对应的字符数组中字符串
  return 0;
}
 */
/****************************************
技巧18：使用指向指针的指针对字符串排序
****************************************/
  /*
#include <stdio.h>
#include <string.h>
 sort(char *strings[],int n)
{
  char *temp;
  int i,j;
  for (i=0; i<n; i++)
    {
      for (j=i+1; j<n; j++)
{
  if (strcmp(strings[i],strings[j])>0)
    {
      temp=strings[i];
      strings[i]=strings[j];
      strings[j]=temp;
    }
 }
    }
}
int main(int argc, char *argv[])
{
  int n=5;
  int i;
  char **p;
  char *strings[]=
    {
      "C language","Basic","World wide","Hello world","Great Wall"
    };
  p=strings;
  sort(p,n);
  for(i=0;i<n;i++)
    printf ("%s\n",strings[i]);
  return 0;
}
  */

