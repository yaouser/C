/****************************************
技巧01：冒泡排序
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j,t,a[11];
  printf ("please input 10 numbers:\n");
  for(i=1;i<11;i++)
    scanf("%d",&a[i]);
  for(i=1;i<10;i++)        //i代表比较的趟数
    for(j=1;j<11-i;j++)    //j代表每趟两两比较的次数
      if (a[j]>a[j+1])
	{
	  t=a[j];
	  a[j]=a[j+1];
	  a[j+1]=t;
	}
  printf ("the sorted numbers:\n");
  for(i=1;i<=10;i++)
    printf ("%5d",a[i]);
  return 0;
}
*/
/****************************************
技巧02：选择排序
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j,t,a[11];
  printf ("please input 10 numbers:\n");
  for(i=1;i<11;i++)
    scanf("%d",&a[i]);
  for(i=1;i<=9;i++)
    for(j=i+1;j<=10;j++)
      if (a[i]>a[j])
	{
	  t=a[i];
	  a[i]=a[j];
	  a[j]=t;
	}
  printf ("the sorted numbers:\n");
  for(i=1;i<=10;i++)
    printf ("%5d",a[i]);
  return 0;
}
 */
/****************************************
技巧03：直接插入排序
****************************************/
  /*
#include <stdio.h>
 void insort(int s[],int n)
 {            //数组的下标从2开始，0做监视哨，1 一个数据无可比性
   int i,j;
   for (i=2; i<=n; i++)
     {
       s[0]=s[i];
       j=i-1;
       while(s[0]<s[j])
	 {
	   s[j+1]=s[j];
	   j--;
	 }
       s[j+1]=s[0];
     }
 }
int main(int argc, char *argv[])
{
  int a[11],i;
  printf ("please input number:\n");
  for(i=1;i<=10;i++)
    scanf("%d",&a[i]);
  printf ("the original order:\n");
  for(i=1;i<11;i++)
    printf ("%5d",a[i]);
  insort(a,10);
  printf ("\nthe sorted numbers:\n");
  for(i=1;i<11;i++)
    printf ("%5d",a[i]);
  return 0;
}
  */
/****************************************
技巧04：归并排序(没有很好的运行）
****************************************/
/*
#include <stdio.h>
void merge(int r[],int s[],int x1,int x2,int x3)
{              //实现一次归并排序函数
  int i,j,k;
  i=x1;        //第一部分的开始位置
  j=x2+1;      //第二部分的开始位置
  k=x1;
  while((i<=x2)&&(j<=x3))  
    //当i和j都在两个要合并的部分中
    if (r[i]<=r[j])   //筛选两部分中较小的元素放到数组s中
      {
	s[k]=r[j];
	i++;
	k++;
      }
    else
      {
	s[k]=r[j];
	j++;
	k++;
      }
  while(i<=x2)        //将x1，x2范围内的未比较的数顺次加到数组r中
    s[k++]=r[i++];
  while(j<=x3)        //将x2，x3范围内的未比较的数顺次加到数组r中
    s[k++]=r[j++];
}
void merge_sort(int r[],int s[],int m,int n)
{
  int p;
  int t[20];
  if(m==n)
    s[m]=r[m];
  else
    {
      p=(m+n)/2;
      merge_sort(r,t,m,p);
      //递归调用merge_sort函数将r[m],r[p]归并成有序的t[m],t[p]
      merge_sort(r,t,p+1,n);
      //递归调用merge_sort函数将r[p+1],r[n]归并成有序的t[p+1],t[n]
      merge(t,s,m,p,n);
      //调有函数将前两部分归并到s[m],s[n]
    }
}
main()
{
  int a[11];
  int i;
  printf ("please input 10 numbers:\n");
  for(i=1;i<=10;i++)        //从键盘中输入10个数
    scanf("%d",&a[i]);     
  merge_sort(a,a,1,10);     //调用merge_sort函数进行归并排序
  printf ("the sorted numbers:\n");
  for(i=1;i<=10;i++)
    printf ("%5d",a[i]);    //将排序后的结构输出
  return 0;
}
*/
/****************************************
技巧05：希尔排序(插入排序的改进）
****************************************/
/*
#include <stdio.h>
void shsort(int s[],int n)
{
  int i,j,d;
  d=n/2;            //确定固定增量值
  while(d>=1)
    {
      for (i=d+1; i<=n; i++)  //数组下标从d+1开始进行直接插入排序
	{
	  s[0]=s[i];          //设置监视哨
	  j=i-d;              //确定要进行比较的元素的最右边位置
	  while((j>0)&&(s[0]<s[j]))
	    {
	      s[j+d]=s[j];    //数据右移
	      j=j-d;          //向左移d个位置
	    }
	  s[j+d]=s[0];        //在确定的位置插入s[i]
	}
      d=d/2;                  //增量变为原来的一半
    }
}
int main(int argc, char *argv[])
{
  int a[11],i;
  printf ("please input numbers:\n");
  for(i=1;i<=10;i++)
    scanf("%d",&a[i]);
  shsort(a,10);
  printf ("the sorted numbers:\n");
  for(i=1;i<=10;i++)
    printf ("%5d",a[i]);
  return 0;
}
*/
/****************************************
技巧06:快速排序(冒泡排序的改进）
主要的算法思想是在带排序的n个数据中取第一个数据作为基准值，将所有的记录分为3组，使得
第一组中各数据值均小于或等于基准值，第二组便是做基准值的数据，第三组中个数举值均大于
或等于基准值。这便实现了第一趟分隔，然后再对第一组和第三组分别重复上述方法。
****************************************/
/*
#include <stdio.h>
void qusort(int s[],int start,int end)
{          //自定义快排函数
  int i,j;                   
  i=start;
  j=end;
  s[0]=s[start];            //设置基准值
  while(i<j)
    {
      while(i<j&&s[0]<s[j])
	j--;                //位置左移
      if (i<j)
	{
	  s[i]=s[j];        //将s[j]放到s[i]的位置上
	  i++;              //位置右移
	}
      while(i<j&&s[i]<=s[0])
	i++;                //位置右移
      if (i<j)
	{
	  s[j]=s[i];        //将大于基准值的s[j]放到s[i]位置
	  j--;              //位置右移
	}
    }  
  s[i]=s[0];                //将基准值放入指定位置
  if(start<i)
    qusort(s,start,j-1);    //对分隔出的部分递归调用函数qusort()
  if(i<end)
    qusort(s,j+1,end);
}
int main(int argc, char *argv[])
{
  int a[11],i;
  printf ("please input numbers:\n");
  for(i=1;i<=10;i++)
    scanf("%d",&a[i]);
  qusort(a,1,10);
  printf ("the sorted numbers:\n");
  for(i=1;i<=10;i++)
    printf ("%5d",a[i]);
  return 0;
}
*/
/****************************************
技巧07：顺序查找
****************************************/
/*
#include <stdio.h>
void search(int key,int a[],int n)
{
  int i,count = 0,count1=0;
  for (i=0; i<n; i++)
    {
      count++;
      if (a[i]==key)
	{
	  printf ("serch %d times a[%d]=%d\n",count,i,key);
	  count1++;
	}
    }
  if(count1==0)
    printf ("no found!\n");
}
int main(int argc, char *argv[])
{
  int n,key,a[100],i;
  printf ("please input the length of array:\n");
  scanf("%d",&n);
  printf ("please input element:\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf ("please input the number which do you want to search:\n");
  scanf("%d",&key);
  search(key,a,n);
  return 0;
}
*/
/****************************************
技巧08：二分查找
****************************************/
/*
#include <stdio.h>
void binary_search(int key,int a[],int n)
{
  int low,high,mid,count=0,count1=0;
  low = 0;
  high = n-1;
  while(low<high)
    {
      count++;              //记录查找次数
      mid=(low+high)/2;     //求出中间位置
      if(key<a[mid])        //当key小于中间值
	high=mid-1;         //确定左子表范围
      else if(key>a[mid])   //当key大于中间值
	low=mid+1;          //确定右子表范围
      else if(key==a[mid])  //当key等于中间值证明查找成功
	{
	  printf ("success!\nsearch %d times! a[%d]=%d\n",count,mid,key);
	  count1++;         //count1记录查找成功次数
	  break;
	}
    }
  if(count1==0)
    printf ("no found!\n");
}
int main(int argc, char *argv[])
{
  int i,key,a[100],n;
  printf ("please input the length of array:\n");
  scanf("%d",&n);
  printf ("please input the element:\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf ("please input the number which do you want to serch:\n");
  scanf("%d",&key);
  binary_search(key,a,n);
  return 0;
}
*/
/****************************************
技巧09：分块查找
****************************************/
/*
#include <stdio.h>
struct index           //定义块的结构
{
  int key;
  int start;
  int end;
}index_table[4];       //定义结构体数组
int block_search(int key,int a[])          //自定义实现分块查找
{
  int i,j;
  i=1;
  while(i<=3&&key>index_table[i].key)      //确定在哪个块中
    i++;
  if(i>3)                                  //大于分得的块数，则返回0
    return 0;
  j=index_table[i].start;                  //j等于块范围的起始值
  while(j<=index_table[i].end&&a[j]!=key)  //在确定的块内进行查找
    j++;
  if(j>index_table[i].end)    //如果大于块范围的结束值，则说明没有要查找的数
    j=0;
  return j;
}
int main(int argc, char *argv[])
{
  int i,j=0,k,key,a[16];
  printf ("please input the number:\n");
  for(i=1;i<16;i++)
    scanf("%d",&a[i]);
  for (i=1; i<=3; i++)
    {
      index_table[i].start=j+1;    //确定每个范围的起始行
      j=j+1;
      index_table[i].end=j+4;      //确定每个块范围的结束值
      j=j+4;
      index_table[i].key=a[j];     //确定每个块范围中元素的最大值
    }
  printf ("please inpu the number whick do you want to search:\n");
  scanf("%d",&key);
  k=block_search(key,a);
  if(k!=0)
    printf ("success ! the position is :%d\n",k);
  else
    printf ("no found!\n");
  return 0;
}
*/
/****************************************
EMACS中的C-m作用，当光标在一行的开头时，此快捷键为此行上边添加一空白行，
当光标在一行的末尾时，此快捷键为此行的下边添加一空白行。
****************************************/
/****************************************
技巧10:哈系查找（没能很好的运行）
****************************************/
/*
#include <stdio.h>
#include <time.h>
#define Max 11
#define N 8
int hashtable[Max];
int func(int value)
{
  return value % Max;           //哈希函数
}
int search(int key)              //自定义函数实现哈希函数
{
  int pos,t;
  pos=func(key);                //哈希函数确定出的位置
  t=pos;                        //t存放确定出的位置
  while(hashtable[t]!=key && hashtable[t]!=-1)
       //如果该位置上不等与要查找的关键字且不为空
    {
      t=(t+1)%Max;              //利用线性探测求出下一个位置
      if(pos==t)
       //如果经多次探测又回到原来用哈希函数求出的位置则
       //说明要查找的数不存在
	return -1;
    }
  if(hashtable[t]==-1)          //如果探测的位置是-1则说明要查找的数不存在
    return 0;
  else 
    return t;
}
void creathash(int key)         //自定义函数创建哈系表
{
  int pos,t;
  pos = func(key);              //哈希函数确定元素的位置
  t = pos;
  while(hashtable[t]!=-1)
       //如果该位置有元素存在则在则进行线性探测再散列
    {
      t=(t+1)%Max;
      if(pos==t)
       //如果冲突处理后确定的位置与原位置相同则说明哈系表已满
	{
	  printf ("hash table is full\n");
	  return ;
	}
    }
  hashtable[t]=key;              //将元素放入确定的位置
}
int main(int argc, char *argv[])
{
  int flag[50];
  int i,j,t;
  for(i=0;i<Max;i++)
    hashtable[i]=-1;             //哈希表中初始化位置全置-1
  for(i=0;i<50;i++)
    flag[i]=0;                   //50以内所有数未产生时均标志为0
  rand((unsigned long)time(0));  //利用系统时间做种子产生随机数
  i=0;
  while(i != N)
    {
      t=rand()%50;               //产生一个50以内的随机数附给t
      if (flag[t]=0)             //查看t是否产生过
	{
	  creathash(t);          //调用函数创建哈希表
	  printf ("%2d:\n",t);   //将该元素输出
	  for (j=0; j < Max; j++)
	    printf ("(%2d) \n",hashtable[j]);    //输出哈希表的内容
	  printf ("\n");
	  flag[t]=1;             //将产生的这个数标志为1
	  i++;                   //i自加
	}
    }
  printf ("please input number whick do you want to search:\n");
  scanf("%d",&t);                //输入要查找的元素
  if (t>0&&t<50)
    {
      i=search(t);               //调用search进行哈系查找
      if(i != -1)
	printf ("success! the position is:%d\n",i); //若找到该元素则输出其位置
      else
	printf ("sorry,no found!\n");               //未找到输出提示信息
    }
  else 
    printf ("input error!\n");
  return 0;
}
*/

