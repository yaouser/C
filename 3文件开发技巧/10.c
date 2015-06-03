/****************************************
技巧01：读取磁盘文件
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  FILE *fp;
  char ch, filename[50];
  printf ("please input file's name:\n");
  gets(filename);  //获取文件名
  fp=fopen(filename,"r");
  ch=fgetc(fp);
  while(ch!=EOF)    //当读入的字符值等于EOF时结束循环
    {
      putchar(ch);
      ch=fgetc(fp);
    }
  fclose(fp);
  return 0;
}
*/
/****************************************
技巧02：将数据写入磁盘文件
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  FILE *fp;
  char ch, filename[50];
  printf ("please input filename:\n");
  scanf("%s",filename);
  if((fp=fopen(filename,"w"))==NULL)
    {
      printf ("cannot open file\n");
      exit(0);
    }
  ch=getchar();
  while(ch!='#')
    {
      fputc(ch,fp);  //将读入的字符写到磁盘文件上去
      ch=getchar();
    }
  fclose(fp);
  return 0;
}
 */
/****************************************
技巧03:格式化读写文件
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   int i,flag=1;
   char str[80],filename[50];
   FILE *fp;
   printf ("please input filename:\n");
   scanf("%s",filename);
   if ((fp=fopen(filename,"w"))==NULL)
     {
       printf ("cannot open!\n");
       exit(0);
     }
   while(flag==1)
     {
       printf ("\ninput string:\n");
       scanf("%s",str);
       fprintf(fp,"%s",str);  //将str字符串内容以%s形式写到fp所指文件上
       printf ("continue:?\n");
       if((getchar()=='N')||(getchar()=='n'))
	  flag=0;
     }
   fclose(fp);
   fp=fopen(filename,"r");
   while(fscanf(fp,"%s",str)!=EOF)
     {
       for(i=0;str[i]!='\0';i++)
	 if((str[i]>='a')&&(str[i]<='z'))
	   str[i]-=32;
       //将小写字母转换为大写字母
       printf ("%s\n",str);
     }
   fclose(fp);
   return 0;
 }
  */
/****************************************
技巧04:成块读写操作
****************************************/
  /*
#include <stdio.h>
struct student_score
{
  char name[20];
  int num;
  int china;
  int math;
  int english;
}score[100];
//作用是将输入的一组数据输出到指定的磁盘文件中去
void save(char *name,int n)
{
  FILE *fp;
  int i;
  if ((fp=fopen(name,"wb"))==NULL)
    {
      printf ("cannot open file\n");
      exit(0);
    }
  for(i=0;i<n;i++)
    if(fwrite(&score[i],sizeof(struct student_score),1,fp)!=1)
      printf ("file write error\n");
  fclose(fp);
}
//作用是将从指定的文件中读入的一组输出显示到屏幕上。
void show(char *name,int n)
{
  int i;
  FILE *fp;
  if ((fp=fopen(name,"rb"))==NULL)
    {
      printf ("cannot open file\n");
      exit(0);
    }
  for (i=0; i<n; i++)
    {
      fread(&score[i],sizeof(struct student_score),1,fp);
      printf ("%-10s%4d%4d%4d%4d\n",score[i].name,score[i].num
	      ,score[i].china,score[i].math,score[i].english);
    }
  fclose(fp);
}
int main(int argc, char *argv[])
{
  int i,n;
  char filename[50];
  printf ("how many students in your class?\n");
  scanf("%d",&n);
  printf ("please input name,number,china,math,english:\n");
  for (i=0; i<n; i++)
    {
      printf ("NO%d\n",i+1);
      scanf("%s%d%d%d%d",score[i].name,&score[i].num,
	    &score[i].china,&score[i].math,
	    &score[i].english);
      save(filename,n);
    }
  show(filename,n);
  return 0;
}
  */
/****************************************
技巧05：随机读写文件
****************************************/


/****************************************
技巧06：复制文件内容到另一个文件
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  FILE *in,*out;
  char ch,infile[50],outfile[50];
  printf ("enter the infile name:\n");
  scanf("%s",infile);
  printf ("enter the outfile name:\n");
  scanf("%s",outfile);
  if ((in=fopen(infile,"r"))==NULL)
    {
      printf ("cannot open infile\n");
      exit(0);
    }
  if ((out=fopen(outfile,"w"))==NULL)
    {
      printf ("cannot open outfile\n");
      exit(0);
    }
  ch=fgetc(in);
  while(ch!=EOF)
    {
      fputc(ch,out);
      ch=fgetc(in);
    }
  fclose(in);
  fclose(out);
  return 0;
}
*/
/****************************************
技巧07:合并两个文件信息
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  char ch,filename1[50],filename2[50];
  FILE *fp1,*fp2;
  printf ("please input filename1:\n");
  scanf("%s",filename1);
  if ((fp1=fopen(filename1,"a+"))==NULL)
    {
      printf ("cannot open\n");
      exit(0);
    }
  printf ("file1:\n");
  ch=fgetc(fp1);
  while(ch!=EOF)
    {
      putchar(ch);
      ch=fgetc(fp1);
    }
  printf ("\nplease input filename2:\n");
  scanf("%s",filename2);
  if ((fp2=fopen(filename2,"r"))==NULL)
    {
      printf ("cannot open\n");
      exit(0);
    }
  printf ("file2:\n");
  ch=fgetc(fp2);
  while(ch!=EOF)
    {
      putchar(ch);
      ch=fgetc(fp2);
    }
  fseek(fp2,0L,0);      //将文件2中的位置指针移到文件开始处
  ch=fgetc(fp2);
  while(!feof(fp2))
    {
      fputc(ch,fp1);   //将文件2中的内容输出到文件1中
      ch=fgetc(fp2);
    }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
*/
/****************************************
技巧08：文件分割(未成功）
****************************************/
  /*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 FILE *in, *out;
char filename[50],ch,cfilename[50];
void space()     //分隔文件函数
{
  char ext[6][6]=
    {
      "a.txt","b.txt","c.txt","d.txt","e.txt","f.txt"
    };     //分割出来的文件扩建名
  unsigned long int n=1,k,byte=0;
  unsigned int j=0,i=0;
  printf ("please input filename:\n");
  scanf("%s",filename);
  strcpy(cfilename,filename);
  if ((in=fopen(filename,"r"))==NULL)
    {
      printf ("cannot open file\n");
      exit(0);
    }
  printf ("please input file size after space(kb):\n");
  scanf("%d",&n);
  n=n*1024;
  while(filename[j]!='.')
    j++;
  filename[j]='\0';   //遇到'.'时，在该处加字符串结束符
  if ((out=fopen(strcat(filename,ext[i]),"w"))==NULL)
    //生成分割后文件所在路径及名称
    {
      printf ("cannot open file\n");
      exit(0);
    }
  fseek(in,0,2);   //将位置指针移到文件末尾
  k=ftell(in);    //k存放当前位置，也就是整个文件的大小
  fseek(in,0,0);
  while(k>0)
    {
      ch=fgetc(in);
      fputc(ch,out);
      byte++;
      k--;
      if (byte==n)
{
  fclose(out);
  byte=0;
  strcpy(filename,cfilename);  //filename恢复初始状态
  while(filename[j]!='.')
    j++;
  filename[j]='\0';
  i++;
  if ((out=fopen(strcat(filename,ext[i]),"w"))==NULL)
    {
      printf ("cannot open file\n");
      exit(0);
    }
 }
    }
  fclose(in);
  printf ("file succeed space!\n\n\n");
}
  */
/****************************************
技巧09：文件加密
****************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void encrypt(char *s_file,char *pwd,char *c_file)
//自定义encrypt用于加密
{
  int i=0;
  FILE *fp1,*fp2;
  register char ch;
  fp1=fopen(s_file,"rb");
  if (fp1==NULL)
    {
      printf ("cannot open s_file.\n");
      exit(1);
    }
  fp2=fopen(c_file,"wb");
  if (fp2==NULL)
    {
      printf ("cannot open or create c_file.\n");
      exit(1);
    }
  ch = fgetc(fp1);
  while(!feof(fp1))  //测试文件是否结束
    {
      ch=ch^*(pwd+i);  //采用异或方法进行加密
      i++;
      fputc(ch,fp2);   //异或后写入fp2文件
      ch=fgetc(fp1);
      if(i>9)
	i=0;
    }
  fclose(fp1);
  fclose(fp2);
}
int main(int argc, char *argv[])
{
  char sourcefile[50];
  char codefile[50];
  char pwd[10];   //用来保存密码
  if (argc != 4)  //容错处理
    {
      printf ("please input encode file name:\n");
      gets(sourcefile);  //得到加密文件
      printf ("please input password\n");
      gets(pwd);   //得到密码
      printf ("please input saved file name:\n");
      gets(codefile);   //得到加密后你要的文件名
      encrypt(sourcefile,pwd,codefile);
    }
  else
    {
      strcpy(sourcefile,argv[1]);
      strcpy(pwd,argv[2]);
      strcpy(codefile,argv[3]);
      encrypt(sourcefile,pwd,codefile);
    }
  return 0;
}
*/
/****************************************
技巧10：统计文件内容
****************************************/
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
  FILE *fp1,*fp2;
  char filename1[50],filename2[50],ch;
  long character,space,other,digit;
  character=space=digit=other=0;
  printf ("enter file name\n");
  scanf("%s",filename1);
  if ((fp1=fopen(filename1,"r"))==NULL)
    {
      printf ("cannot open file\n");
      exit(1);
    }
  printf ("enter file name for write data:\n");
  scanf("%s",filename2);
  if ((fp2=fopen(filename2,"w"))==NULL)
    {
      printf ("cannot open file\n");
      exit(1);
    }
  while((ch=fgetc(fp1))!=EOF)
    {
      if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')
	character++;
      else if(ch==' ')
	space++;
      else if(ch>='0'&&ch<='9')
	digit++;
      else
	other++;
    }
  close(fp1);
  fprintf(fp2,"character:%ld space:%ld digit:%ld other:%ld\n"
	  ,character,space,digit,other);
  fclose(fp2);
  return 0;
}
*/

