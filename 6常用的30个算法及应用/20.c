/****************************************
技巧11：斐波那锲数列
斐波那锲数列的特点第1，2两个数为1，1，从第三个数开始
该数是前两个数之和。
****************************************/
/*
#include <stdio.h>
main()
{
  int i;
  long f[31];
  f[1]=1,f[2]=1;
  for(i=3;i<31;i++)
    f[i]=f[i-1]+f[i-2];
  for (i=1; i<31; i++)
    {
      printf ("\t%ld",f[i]);
      if(i%5==0)
	printf ("\n");
    }
  return 0;
}
*/
/****************************************
技巧12：角谷猜想
任给一个自然数，若为偶数则除以2，若为奇数则乘3加1，
得到一个新的自然数后按照上面的算法继续演算若干次计算
后结果一定为1.
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  long i,n;
  printf ("please input a number:\n");
  scanf("%ld",&n);
  while(n!=1)
    {
      if (n%2==0)
	{
	  printf ("%ld/2=%ld\n",n,n/2);
	  n=n/2;
	}
      else
	{
	  printf ("%ld*3+1=%ld\n",n,n*3+1);
	  n=n*3+1;
	}
    }
  return 0;
}
 */
/****************************************
技巧13：歌德巴赫猜想
任意正偶数都能分解为两个素数之和
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
  int i,j,k,flag1,flag2,n=0;
  for(i=6;i<100;i+=2)
    for (k=2; k<=i/2; k++)
      {
	j=i-k;
	flag1=ss(k);
	if (flag1)
	  {
	    flag2=ss(j);
	    if (flag2)
	      {
		printf ("%3d=%3d+%3d",i,k,j);
		n++;
		if(n%5==0)
		  printf ("\n");
	      }
	  }
      }
  return 0;
}
  */
/****************************************
技巧14：四方定理
所有的自然数至多只要用4个数的平方和就可以表示
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  long i,j,k,l,n;
  printf ("please input a number:\n");
  scanf("%ld",&n);
  for(i=0;i<=n;i++)
    for(j=0;j<=i;j++)
      for(k=0;k<=j;k++)
	for(l=0;l<=k;l++)
	  if(i*i+j*j+k*k+l*l == n)
	    {
	      printf ("%ld*%ld+%ld*%ld+%ld*%ld+%ld*%ld=%ld\n",i,i,j,j,k,k,l,l,n);
	    }
  return 0;
}
*/
/****************************************
技巧15：尼科彻斯定理
任何一个整数的立方都可以写成一串连续奇数的和
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i,j,k=0,l,n,m,sum,flag=1;
  printf ("please input a number:\n");
  scanf("%d",&n);                //从键盘中任意输入一个树
  m=n*n*n;                       //计算该数的立方
  i=m/2;                         //一个数的一半最容易找到这样的数了
  if(i%2==0)                     //当i为偶数时i值加1
    i=i+1;
  while(flag==1&&i>=1)           //当i大于等于1且flag=1时执行循环体语句
    {
      sum=0;
      k=0;
      while(1)
	{
	  sum+=(i-2*k);          //奇数累加求和
	  k++;
	  if (sum==m)            //如果sum与m相等，则输出累加过程
	    {
	      printf ("%d*%d*%d=%d=",n,n,n,m);
	      for(l=0;l<k-1;l++)
		printf ("%d+",i-l*2);
	      printf ("%d\n",i-(k-1)*2); //输出累加过程的最后一个数
	      flag=0;
	      break;
	    }
	  if(sum>m)
	    break;
	}
      i-=2;                       //i等于下一个奇数继续上面过程
    }
  return 0;
}
 */
/****************************************
技巧16：创建单项链表
第0个节点称为整个链表的头节点，它一般不存放数据，只是存放第一个节点的地址
也称为头指针，最后一个节点的指针域设置为空（NULL),作为链表的结束标志，表
示没有后继节点。使用结构体变量作为链表中的节点，因为结构体变量成员可以是
数值类型，字符类型，数组类型，指针类型，这样就可以使用指针类型成员来存放
下一个节点的地址，使用其他类型成员存放数据信息。
*****************************************/
  /*
#include <stdio.h>
#include <malloc.h>
struct LNode
{
  int data;
  struct LNode *next;
};
struct LNode *create(int n)
{
  int i;
  struct LNode *head,*p1,*p2;
  int a;
  head = NULL;
  printf ("input the integers:\n");
  for (i=n; i>0; --i)
    {
      p1=(struct LNode*)malloc(sizeof(struct LNode));//分配空间
      scanf("%d",&a);                //输入数据
      p1->data=a;                    //数据域赋值
      if (head == NULL)              //指定头节点
	{
	  head=p1;
	  p2=p1;
	}
      else
	{
	  p2->next=p1;               //指定后继指针
	  p2=p1;
	}
    }
  p2->next=NULL;
  return head;
};
int main(int argc, char *argv[])
{
  int n;
  struct LNode *q;
  printf ("input the count of the nodes you want to creat:");
  scanf("%d",&n);                    //输入链表节点个数
  q=create(n);
  printf ("the result is:\n");
  while(q)
    {
      printf ("%d ",q->data);      //输出链表
      q=q->next;
    }
  return 0;
}
  */
/****************************************
技巧17：约瑟夫环（循环链表）//没有很好的运行
n个人围成一圈，每个人都有一个互不相同的密码，该密码是一个整数值，选择一个人作为起点，
然后顺时针从1到k（k为起点人手中的密码值）数数。数到k的人退出圈子，然后从下一个人开始
继续从1到j（刚退出圈子的人的密码）数数，数到j的人退出圈子。重复上面的过程。直到剩下
最后一个人。
****************************************/
/*
#include <stdio.h>
#include <malloc.h>
#define N 9
#define OVERFLOW 0
#define OK 1
  int KeyW[N]={4,7,5,9,3,2,6,1,8};
typedef struct LNode
{
  int keyword;
  struct LNode *next;
}LNode,*LinkList;
void Joseph(LinkList p,int m,int x)//实现约瑟夫环算法
{
  LinkList q;                     //声明变量
  int i;
  if(x==0)
    return;
  q=p;
  m%=x;
  if(m==0)
    m=x;
  for (i=1; i<=m; i++)            //找到下一个节点
    {
      q=p;
      p=q->next;
    }
  p->next=q->next;
  i=q->keyword;
  printf ("%d \n",q->keyword);
  free(q);                       //释放选中节点
  Joseph(p,i,x-1);               //递归调用
}
int main(int argc, char *argv[])
{
  int i,m;
  LinkList Lhead,p,q;
  Lhead=(LinkList)malloc(sizeof(LNode));    //申请节点空间
  if(!Lhead)
    return OVERFLOW;
  Lhead->keyword=KeyW[0];                   //数据域赋值
  Lhead->next=NULL;                         
  p=Lhead;
  for (i=1; i<9; i++)                       //创建循环链表
    {
      if (!(q=(LinkList)malloc(sizeof(LNode))))
	  return OVERFLOW;
      q->keyword=KeyW[i];
      p->next=q;
      p=q;
    }
  p->next=Lhead;
  printf ("please input the first record m:\n");
  scanf("%d",&m);
  printf ("the output alignment is:\n");
  Joseph(p,m,N);
  return OK;
}
*/
/****************************************
技巧18：双链表逆序输出//没有很好运行
因为双链表有两条指针链，一条可以看成是从头节点出发直到尾节点的指针链，
另一条可以看成是从尾节点出发直到指向头节点的指针链。
****************************************/
/*
#include <stdio.h>
#include <malloc.h>
#define N 10
typedef struct node           // 双向链表的结构定义
{
  char name[20];
  struct node *prior,*next;
}stud;
stud *creat(int n)            //双向链表的创建
{
  stud *p,*h,*s;              //声明双向链表结构类型的指针
  int i;
  h=(stud*)malloc(sizeof(stud));  //创建头节点
  h->name[0]='\0';
  h->prior=NULL;
  h->next=NULL;
  p=h;                        //p指向头节点
  printf ("input the records:\n");
  for (i=0; i<n; i++)
    {
      s=(stud*)malloc(sizeof(stud));  //申请节点空间
      p->next=s;
      scanf("%s",s->name);    //输入数据
      s->prior=p;             //指定前驱节点
      s->next=NULL;           //指定后继节点
      p=s;
    }
  p->next=NULL;
  return (h);                 //返回头节点
}
stud *gettp(stud *head)      //实现一个指向双向链表尾节点的指针
{
  stud *p,*r;
  while(p->next != NULL)
    {
      p=p->next;
    }
  return p;                 //返回尾节点指针
}
int main(int argc, char *argv[])
{
  int n,i;
  int x;
  stud *q;
  printf ("input the count of the nodes you want to creat:\n");
  scanf("%d",&n);           //输入要创建链表的节点数
  q=creat(n);               //创建双向链表
  q=gettp(q);               //找到双向链表的尾节点
  printf ("the result:\n");
  while(q)
    {
      printf ("  %s\n",& *(q->name));   //逆序输出
      q=q->prior;                      //从尾节点开始向前遍历链表节点
    }
  return 0;
}
*/
/****************************************
技巧19：二叉树的遍历
构造一颗二叉树，分别采用先序遍历，中序遍历和后续遍历来遍历该二叉树
先序遍历：若二叉树非空，则先访问根节点，再安先序遍历左子树，最后右子树。
中序遍历：若二叉树非空，左-》根-》右
后序遍历：若二叉树非空，右-》根-》左
****************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node           //二叉链表结构声明
{
  struct node *lchild;
  char data;
  struct node *rchild;
}bitnode, *bitree;           //bitnode，bitree为该结构体类型
bitree CreatTree()           //构造二叉树
{
  char a;
  bitree new;
  scanf("%c",&a);
  if(a=='#')
    return NULL;
  else
    {
      new=(bitree)malloc(sizeof(bitnode));
      new->data=a;
      new->lchild=CreatTree();   //递归创建左子树
      new->rchild=CreatTree();   //递归创建右子树
    }
  return new;
}
void preorderTraverse(bitree bt)  //先序遍历二叉树
{
  if(bt!=NULL)
    {
      printf ("%c",bt->data);      //访问跟节点
      preorderTraverse(bt->lchild);  //访问左子树
      preorderTraverse(bt->rchild);  //访问右子树
    }
}
void InorderTraverse(bitree bt) //中序遍历二叉树
{
  if (bt!=NULL)
    {
      InorderTraverse(bt->lchild);   //访问左子树
      printf ("%c",bt->data);      //访问根节点
      InorderTraverse(bt->rchild);   //访问右子树
    }
}
void postorderTraverse(bitree bt)         //后序遍历二叉树
{
  if (bt!=NULL)
    {
      postorderTraverse(bt->lchild);   //访问左子树
      postorderTraverse(bt->rchild);   //访问右子树
      printf ("%c",bt->data);        //访问根节点
    }
}
int main(int argc, char *argv[])
{
  bitree root;
  root=CreatTree();                    //构造二叉树
  printf ("preorder traversal:\n");
  preorderTraverse(root);              //先序遍历二叉树
  printf ("\n");
  printf ("inorder traversal：\n");     
  InorderTraverse(root);              //中序遍历二叉树
  printf ("\n");
  printf ("postorder traversal:\n");   
  postorderTraverse(root);             //后序遍历二叉树
  printf ("\n");
  return 0;
}
*/
/****************************************
技巧20：用栈设置密码
应用到了栈的定义，初始化，进栈，出栈等功能
****************************************/
/*
#include <stdio.h>
inc
*/
/****************************************
技巧21：链队列
队列的链式存储结构是通过由节点构成的单链表实现的，只允许在单链表的表首进行删除，
在单链表的表尾进行插入，因此需要两个指针：队首指针front和队尾指针rear。用
front指向队首的存储位置，用rear指向队尾节点的存储位置。
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node            //定义节点
{
  int data;               //存放元素内容
  struct node *next;           //指向下一个节点
}quenode;
struct quefr                   //定义节点存放队首队尾指针
{
  quenode *front,*rear;
};
void creat(struct quefr *q)    //自定义函数初始化链队列
{
  quenode *h;
  h=(quenode*)malloc(sizeof(quenode));    //为头节点分配空间
  h->next=NULL;
  q->front=h;                  //队首指针队尾指针均指向头节点
  q->rear=h;
}
void enqueue(struct quefr *q,int x)   //自定义函数，元素x入对
{
  quenode *s;
  s=(quenode*)malloc(sizeof(quenode));
  s->data=x;                         //x放到节点的数据域中
  s->next=NULL;                      //next域为空
  q->rear->next=s;
  q->rear=s;                         //队尾指向s节点
}
int dequeue(struct quefr *q)    //自定义函数实现元素出队
{
  quenode *p;
  int x;
  p=(quenode*)malloc(sizeof(quenode));
  if (q->front == q->rear)
    {
      printf ("queue is NULL \n");
      x=0;
    }
  else
    {
      p=q->front->next;
      q->front->next=p->next;       //指向出队元素所在节点的后一个节点
      if(p->next==NULL)
	q->rear=q->front;
      x=p->data;
      free(p);                      //释放p节点
    }
  return (x);
}
void display(struct quefr dq)       //自定义函数显示队列中元素
{
  quenode *p;
  p=(quenode*)malloc(sizeof(quenode));
  p=dq.front->next;                 //指向第一个数据元素节点
  while(p!=NULL)
    {
      printf ("data=%d\n",p->data);
      p=p->next;                    //指向下一个节点
    }
  printf ("end \n");
}
int main(int argc, char *argv[])
{
  struct quefr *que;
  int n,i,x,sel;
  void display();               //显示队列中元素
  void creat();                 //创建队列
  void enqueue();               //元素队列
  int dequeue();           //元素出队列
  do
    {
      printf ("\n");
      printf ("    1 creat queue     \n");
      printf ("    2 into the queue   \n");
      printf ("    3 delete from queue  \n");
      printf ("    4 display  \n");
      printf ("    5 exit      \n");
      printf ("--------------------------------\n");
      printf ("please choose (1,2,3,4,5) \n");
      scanf("%d",&sel);                //输入相关功能所对应的标号
      switch(sel)
	{
	case 1:
	  //分配内存空间
	  que=(struct quefr*)malloc(sizeof(struct quefr));
	  creat(que);                  //初始化队列
	  printf (
    "plese input the number of element which do you want to creat:");
	  scanf("%d",&n);              //输入队列元素个数
	  for (i=1; i<=n; i++)
	    {
	      scanf("%d",&x);          //输入元素
	      enqueue(que,x);          //元素入队
	    }
	  break;
	case 2:
	  printf ("please input the element:");
	  scanf("%d",&x);              //输入元素
	  enqueue(que,x);              //元素入对
	  break;
	case 3:
	  printf ("x=%d\n",dequeue(que));    //元素出队
	  break;
	case 4:
	  display(*que);                     //显示队列中元素
	  break;
	case 5:
	  exit(0);
	}
    } while (sel<=4);
  return 0;
}

