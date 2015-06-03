/****************************************
技巧11：从链表中删除节点（没很好的运行）
****************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct student
{
  int num;
  struct student *next;
}LNode,*LinkList;
struct student *create(int n)
{
  int i;
  struct student *head,*p1,*p2;
  int a;
  head=NULL;
  printf ("the record:\n");
  for (i=n; i>0; --i)
    {
      p1=(struct student*)malloc(sizeof(struct student));
      scanf("%d",&a);
      p1->num=a;
      if (head=NULL)
	{
	  head=p1;
	  p2=p1;
	}
      else
	{
	  p2->next=p1;
	  p2=p1;
	}
    }
  p2->next=NULL;
  return head;
};
struct student *delnode(struct student *head,int i)
{
  int j=0;
  struct student *p,*r;
  p=head;
  while(p&&j<i-1)           //找到要删除的位置
    {
      p=p->next;
      ++j;
    }
  if(!p->next||j>i-1)
    exit(1);
  r=p->next;
  p->next=r->next;           //删除节点
  free(r);
};
main()
{
  int n,i;
  struct student *q;
  printf ("input the count of the nodes you want to creat:\n");
  scanf("%d",&n);
  q=create(n);
  i=2;
  delnode(q,i);
  printf ("the third record is deleted!\nthe result is:\n");
  while(q)
    {
      printf ("%d ",q->num);
      q=q->next;
    }
  return 0;
}
*/
/****************************************
技巧12：合并两个链表
****************************************/
/*
#include <stdio.h>
#include <malloc.h>
typedef struct student
{
  int num;
  struct student *next;
}LNode,*LinkList;
LinkList create(void)
{
  LinkList head;
  LNode *p1,*p2;
  char a;
  head=NULL;
  a=getchar();
  while(a!='\n')
    {
      p1=(LNode*)malloc(sizeof(LNode));
      p1->num=a;
      if(head==NULL)
	head=p1;
      else
	p2->next=p1;
      p2=p1;
      a=getchar();
    }
  p2->next=NULL;
  return head;
}
LinkList coalition(LinkList L1,LinkList L2)
{
  LNode *temp;
  if(L1==NULL)
    return L2;
  else
    {
      if (L2 !=NULL)
	{
	  for(temp=L1;temp->next != NULL;temp=temp->next);
	  temp->next=L2;
	}
    }
  return L1;
}
int main(int argc, char *argv[])
{
  LinkList L1,L2,L3;
  printf ("please input two linklist:\n");
  printf ("the first linklist:\n");
  L1=create();
  printf ("the second linklist:\n");
  L2=create();
  coalition(L1,L2);
  printf ("the resultant linklist is:\n");
  while(L1)
    {
      printf ("%c",L1->num);
      L1=L1->next;
    }
  return 0;
}
*/
/****************************************
技巧13：应用栈实现进制转换
****************************************/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct DataType
{
  DataType *base;
  DataType *top;
  int stacksize;
}SeqStack;
void Initial(SeqStack *s)
{
  //构造一个空栈
  s->base=(DataType *)malloc(stacksize *sizeof(DataType));
  if(!s->base)
    exit(-1);
  s->top=s->base;
  s->stacksize=stacksize;
}
//判栈空
int IsEmpty(SeqStack *s)
{
  return s->top==s->base;
}
//判栈满
int IsFull(SeqStack *s)
{
  return s->top - s->base==stacksize-1;
}
//进栈
void Push(SeqStack *S,DataType x)
{
  if (IsFull(S))
    {
      printf ("栈上溢\n"); //上溢，退出运行
      exit(1);
    }
  *S->top++ = x;    //栈顶指针加1后将x入栈
}
//出栈
DataType Pop(SeqStack *S)
{
  if (IsEmpty(S))
    {
      printf ("栈为空\n");  //下溢，退出运行
      exit(1);
    }
  return *--S->top; //栈顶元素返回后将栈顶指针减1
}
//取栈顶元素
DataType Top(SeqStack *S)
{
  if (IsEmpty(S))
    {
      printf ("栈为空\n");   //下溢，退出运行
      exit(1);
    }
  return *(S->top-1);
}
void conversion(int N,int B)
{          //假设N是非负的十进制整数，输出等值的B进制数
  int i;
  SeqStack *S;
  Initial(S);
  while(N)
    {      //从右向左产生B进制的各位数字，并将其进栈
      Push(S,N%B);     //将bi进栈0<=i<=j
      N=N/B;
    }
  while(!IsEmpty(S))
    {
      i=Pop(S);        //栈非空时退栈输出
      printf ("%d\n",i);
    }
}
void main()
{
  int n,d;
  printf ("Input the integer you want to transform:\n");
  scanf("%d",&n);
  printf ("Input the integer of the system:\n");
  scanf("%d",&d);
  printf ("result:\n");
  conversion(n,d);
}

