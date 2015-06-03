/****************************************
技巧01：结构体简单应用
****************************************/
/*
#include <stdio.h>
struct student
{
  int num;
  char name[20];
  char sex;
  int age;
  float score;
};
int main(int argc, char *argv[])
{
  struct student student1={1001,"liming",'M',20,93.5};
  printf ("the information of the student is:\n");
  printf ("num:%d\n",student1.num);
  printf ("name:%s\n",student1.name);
  printf ("sex:%c\n",student1.sex);
  printf ("age:%d\n",student1.age);
  printf ("score:%5.1f\n",student1.score);
  return 0;
}
*/
/****************************************
技巧02：找最高分
****************************************/
/*
#include <stdio.h>
struct student
{
  int num;
  char name[20];
  float score;
};
int main(int argc, char *argv[])
{
  int i,m;
  float maxscore;
  struct student stu[5]=
  {
    {101,"liming",89},
    {102,"zhanghong",95},
    {103,"lili",89},
    {104,"weichen",85},
    {105,"yangfan",75}
  };
  m=0;
  maxscore=stu[0].score;
  for (i=1; i<5; i++)
    {
      if (stu[i].score>maxscore)
	{
	  maxscore=stu[i].score;
	  m=i;
	}
    }
  printf ("the maxmum score is :%5.1f\n",maxscore);
  printf ("the student number is:%d\n",stu[m].num);
  printf ("the student name is:%s\n",stu[m].name);
  return 0;
}
*/
/****************************************
技巧03:平均成绩
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  struct student_score
  {
    int mid;
    int end;
    int ave;
  }score;
  printf ("please input score(midterm and end of term:\n");
  scanf("%d%d",&score.mid,&score.end);
  score.ave=(score.mid+score.end)/2;
  printf ("average=%d\n",score.ave);
  return 0;
}
*/
/****************************************
技巧04：比较计数
****************************************/
 /*
#include <stdio.h>
#define N 5
struct order
{
  int num;
  int con;
}a[20];
int main(int argc, char *argv[])
{
  int i,j;
  for (i=0; i<N; i++)
    {
      scanf("%d",&a[i].num);
      a[i].con=0;
    }
  for(i=N-1;i>=1;i--)
    for(j=i-1;j>=0;j--)
      if(a[i].num<a[j].num)
	a[j].con++;
      else
	a[i].con++;
  printf ("the order is:\n");
  for(i=0;i<N;i++)
    printf ("%d\t%d\t\n",a[i].num,a[i].con);
  return 0;
}
 */
/****************************************
技巧05：信息查询
****************************************/
/*
#include <stdio.h>
#include <string.h>
#define MAX 10
struct aa
{
  char name[15];
  char tel[15];
};
int readin(struct aa *a)     //自定义函数，用来存储姓名及电话号码
{
  int i=0,n=0;
  while(1)
    {
      scanf("%s",a[i].name);     //输入姓名
      if(!strcmp(a[i].name,"#")) 
	break;
      scanf("%s",a[i].tel);      //输入电话号码
      i++;
      n++;                       //记录的条数
    }
  return n;                      //返回条数
}
void search(struct aa *b,char *x,int n)
//自定义查找姓名所对应的电话号码函数
{
  int i;
  i=0;
  while(1)
    {
      if (!strcmp(b[i].name,x))   //查找与输入姓名相匹配的记录
	{
	  printf ("name:%s tel:%s\n",b[i].name,b[i].tel);
	  break;
	}
      else
	i++;
      n--;
      if (n==0)
	{
	  printf ("no found!\n");
	  break;
	}
    }
}
int main(int argc, char *argv[])
{
  struct aa s[MAX];
  int num;
  char name[15];
  num=readin(s);
  printf ("please input the name:\n");
  scanf("%s",name);
  search(s,name,num);
  return 0;
}
*/
/****************************************
技巧06：计算开机时间(函数kbhit有问题）
****************************************/
/*
#include <stdio.h>
struct time      //定义结构体time，存储时间信息
{
  int hour;
  int minute;
  int second;
}t;
int main(int argc, char *argv[])
{
  FILE *fp = fopen("time", "r");    //定义文件类型指针fp
  fread(&t,sizeof(struct time),1,fp);  //以只读方式打开文件time
  while(!kbhit())                  //当无按键时执行循环体语句
    {
      rewind(fp);                 //将文件指针设置到文件起点
      sleep(1);                   //程序停止1秒钟
      fread(&t,sizeof(struct time),1,fp);//读取文件中的内容
      if (t.second == 59)          //如果到60秒
	{
	  t.minute=t.minute+1;     //如果到60秒分钟数加1
	  if (t.minute==60)        //判断是否到60分钟
	    {
	      t.hour=t.hour+1;     //到60分钟小时数加1
	      t.minute=0;          //分数置0
	      t.second=0;          //秒数置0
	    }
	}
      else
	t.second=t.second+1;       //秒数加1
      printf ("%d:%d:%d\n",t.hour,t.minute,t.second);//输出积累开机时间
      FILE *fp = fopen("time", "w");        //以可写方式打开time文件
      fwrite(&t,sizeof(struct time),1,fp);  //将结构体中的新内容存储
      fclose(fp);
    }
  return 0;
}
*/
/****************************************
技巧07：创建双向链表
****************************************/

/****************************************
emacs的剪切为C-w；复制为M-w
成员运算符（.）和指向结构体成员的运算符（->）两者都是用来引用结构体变量
成员的，但是他们的应用环境是完全不同的。
成员运算符（.）用在一般结构体变量中，表示结构体变量的成员。
指向结构体成员运算符（->）与指向结构体变量的指针连用，表示指向结构体变量
指针的成员。
strut student
{
  int num;
  char name[10];
};
struct student stu, *s=&stu;
其中，stu.num s->num是正确的引用方法，但是stu->num和s.num是不允许。
其实，s->num就相当于（*s）.num。
****************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node
{
  char name[20];    //存储数据
  struct node *prior,*next;  //指针类型，其指向本结构体类型的数据
}stud;             //双向链表的结构定义
stud *create(int n)
{
  stud *p,*h,*s;   //声明结构体指针
  int i;
  h=(stud*)malloc(sizeof(stud));   //申请节点空间
  h->name[0]='\0';  
  h->prior=NULL;
  h->next=NULL;
  //第0个节点称为整个链表的头节点，它一般不存放具体数据，只是存放第一个
  //节点的地址，也称为头指针
  p=h;
  for (i=0; i<n; i++)
    {
      s=(stud*)malloc(sizeof(stud));
      p->next=s;                   //指定后继节点
      printf ("input the %d student's name: \n",i+1);
      scanf("%s",s->name);
      s->prior=p;               //指定前驱节点
      s->next=NULL;
      p=s;
    }
  p->next=NULL;
  return (h);
}
stud *search(stud *h,char *x)
{
  stud *p;
  char *y;
  p=h->next;
  while(p)
    {
      y=p->name;
      if(strcmp(y,x)==0)  //如果是要删除的节点，则返回地址
	return (p);
      else 
	p=p->next;
    }
  printf ("cannot find data!\n");
}
void del(stud *p)
{
  p->next->prior=p->prior;    //p的下一个节点的前驱指针指向p的前驱节点
  p->prior->next=p->next;     //p的前驱节点的后继指针指向p的后继节点
  free(p);
}
int main(int argc, char *argv[])
{
  int number;             //定义变量
  char sname[20];         //定义字符型数组
  stud *head,*sp;
  puts("please input the size of the list:");
  scanf("%d",&number);    //输入链表节点数
  head=create(number);     //创建链表
  sp=head->next;
  printf ("now the double list is:\n");
  while(sp)               //输出链表中数据
    {
      printf ("%s\n",&*(sp->name));   
      sp=sp->next;
    }
  printf ("please input the name which you want to find:\n");
  scanf("%s",sname);
  sp=search(head,sname);      //查找指定节点
  printf ("the name you want to find is: %s\n",*&sp->name);
  del(sp);                    //删除节点
  sp=head->next;
  printf ("now the double list is:\n");
  while(sp)                   //输出当前链表中数据
    {
      printf ("%s ",&*(sp->name));
      sp=sp->next;
    }
  printf ("\n");
  return 0;
}
*/
/****************************************
技巧08：创建循环链表
****************************************/
/*
#include <stdio.h>
#include <malloc.h>
typedef struct student  //student为结构体名
{
  int num;       //结构体成员
  struct student *next;    //结构体成员
}LNode,*LinkList;      //LNode *LinkList为结构体变量名
LinkList create(void)  //自定义函数，实现创建一个循环列表
{
  LinkList head;
  LNode *p1,*p2;
  char a;
  head = NULL;
  a=getchar();
  while(a!='\n')
    {
      p1=(LNode*)malloc(sizeof(LNode));   //分配空间
      p1->num=a;                    //数据域赋值
      if(head==NULL)
	head=p1;
      else
	p2->next=p1;
      p2=p1;              //将指针p1附给指针p2，相当与前者指向后者
      a=getchar();
    }
  p2->next=head;       //尾节点指向头节点
  return head;         //返回循环链表的头指针
}
int main(int argc, char *argv[])
{
  LinkList L1,head;
  printf ("please input the linklist:\n");
  L1=create();
  head=L1;
  printf ("the resultant linklist is:\n");
  printf ("%c ",L1->num);
  L1=L1->next;         //指向下一个节点
  while(L1!=head)
    {
      printf ("%c ",L1->num);
      L1=L1->next;
    }
  return 0;
}
*/
/****************************************
技巧09：创建顺序表并插入元素
****************************************/
/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define Listsize 100
struct sqlist
{
  int data[Listsize];
  int length;
};
void InsertList(struct sqlist *l,int t,int i)  //创建自定义函数
{
  int j;
  if (i<0||i>l->length)
    {
      printf ("position error\n");
      exit(1);
    }
  if (l->length>=Listsize)
    {
      printf ("overflow\n");
      exit(1);
    }
  for(j=l->length-1;j>=i;j--)       //插入元素
    l->data[j+1]=l->data[j];
  l->data[i]=t;
  l->length++;
}
int main(int argc, char *argv[])
{
  struct sqlist *sq;
  int i,n,t;
  sq=(struct sqlist*)malloc(sizeof(struct sqlist));
  sq->length=0;
  printf ("please input the size of the list:\n");
  scanf("%d",&n);
  printf ("please input the elements of the list:\n");
  for (i=0; i<n; i++)
    {
      scanf("%d",&t);
      InsertList(sq,t,i);
    }
  printf ("now the list is:\n");
  for (i=0; i<sq->length; i++)
    {
      printf ("%d ",sq->data[i]);
    }
  return 0;
}
*/
/****************************************
技巧10:向链表中插入节点
****************************************/
/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct student
{
  int num;
  struct student *next;
};
struct student *create(int n)
{
  int i;
  struct student *head,*p1,*p2;
  int a;                   
  head=NULL;                 //初始化头节点地址
  printf ("the record:\n");
  for (i=n; i>0; --i)
    {
      p1=(struct student*)malloc(sizeof(struct student));
      scanf("%d",&a);
      p1->num=a;
      if (head==NULL)       //（head/p2)-->(p1/p2)-->...
	{
	  head=p1;
	  p2=p1;
	}
      else
	{
	  p2->next=p1;       //指定后继指针
	  p2=p1;
	}
    }
  p2->next=NULL;             //后继指针为空，链表结束
  return head;               //返回头节点
}
struct student *insertnode(struct student *head,char x,int i)
{
  int j=0;
  struct student *p,*s;
  p=head;
  while(p&&j<i-1)     //找到要插入的位置
    {
      p=p->next;
      ++j;            //先对j进行++，然后再用j进行运算
    }
  if(!p||j>i-1)
    exit(1);
  s=(struct student*)malloc(sizeof(struct student));
  s->num=x;
  s->next=p->next;
  p->next=s;
}
int main(int argc, char *argv[])
{
  int n,i;
  int x;
  struct student *q;
  printf ("input the count of the nodes you want to creat:\n");
  scanf("%d",&n);
  q=create(n);
  i=2;
  x=123;
  insertnode(q,x,i);
  printf ("the result is:\n");
  while(q)              //输出插入节点后的链表
    {
      printf ("%d ",q->num);
      q=q->next;
    }
  return 0;
}
*/
/****************************************
EMACS的字符串搜索C-s向后查找，C-r向前查找，重复组合键时会搜索下一个匹配的关键字
而针对替换操作为M-%（alt+shift+5），形式为（被替换操作符）with（替换的操作符）
撤销操作是C-/，而自动补全操作快捷键是M-/，切换buffer快捷键是C-x b。
每行前边加入特定的字符串快捷键为C-x r t，即实际为rectangle操作。
****************************************/

