/****************************************
技巧11:创建文件
****************************************/
/*
#include <stdio.h>
#include <cpio.h>
int main(int argc, char *argv[])
{
  int handle;
  char filename[50];
  printf ("please input filename:\n");
  scanf("%s",filename);
  if ((handle=creat(filename,0))==-1)
    {
      printf ("\nerror! cannot vreat!\n");
    }
  else
    {
      printf ("\nthis file has created!\n");
    }
  close(handle);
  return 0;
}
*/
/****************************************
技巧12：创建临时文件
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  FILE *temp;
  char c;
  if ((temp=tmpfile())!=NULL)
    {
      fputs("hello world\nhello mingri\n",temp);//向临时文件中写入要求内容
    }
  rewind(temp);  //文件指针返回文件首
  while((c=fgetc(temp))!=EOF)//读取临时文件中内容
    printf ("%c",c);
  fclose(temp);
  return 0;
}
 */
/****************************************
技巧13：重命名文件
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   FILE *fp;
   char filename1[20],filename2[20];
   printf ("please input the file name which do you want to change:\n");
   scanf("%s",filename1);
   if ((fp=fopen(filename1,"r"))!=NULL)
     {
       printf ("%s open successfully\n",filename1);
       printf ("please input new name!\n");
       scanf("%s",filename2);
       rename(filename1,filename2);
       fclose(fp);
     }
   else
     {
       printf ("cannot find!!!\n");
       exit(0);
     }
   return 0;
 }
  */
/****************************************
技巧14：删除文件
****************************************/
  /*
#include <stdio.h>
int main(int argc, char *argv[])
 {
   FILE *fp;
   char filename[50];
   printf ("please input the name of the file whick do you want to delete:\n");
   scanf("%s",filename);
   if ((fp=fopen(filename,"r"))!=NULL)
     {
       printf ("%s open successfully!\n",filename);
       fclose(fp);
     }
   else
     {
       printf ("%s cannot open!\n",filename);
       exit(0);
     }
   remove(filename);
   if((fp=fopen(filename,"r"))==NULL)
     printf ("%s has removed!\n",filename);
   else 
     printf ("error\n");
   return 0;
 }
  */
/****************************************
技巧15：删除文件中的记录
****************************************/
  /*
#include <stdio.h>
#include <string.h>
 struct emploee  //定义结构体，存放员工工资信息
{
  char name[10];
  int salary;
}emp[20];
main()
{
  FILE *fp1,*fp2;
  int i,j,n,flag,salary;
  char name[10],filename[50];//定义数组为字符类型
  printf ("please input filename:\n");
  scanf("%s",filename); //输入要录入的人数
  printf ("please input the number of emploees:\n");
  scanf("%d",&n);
  printf ("input name and salary:\n");
  for (i=0; i<n; i++)
    {
      printf ("NO%d:\n",i+1);
      scanf("%s%d",emp[i].name,&emp[i].salary);
      //输入员工姓名及工资
    }
  if ((fp1=fopen(filename,"ab"))==NULL)//以追加的方式打开指定的二进制文件
    {
      printf ("can not open the file\n");
      exit(0);
    }
  for (i=0; i<n; i++)
    //将输入的员工信息输出到磁盘文件上
    if(fwrite(&emp[i],sizeof(struct emploee),1,fp1)!=1)
      printf ("error\n");
  fclose(fp1);
  if ((fp2=fopen(filename,"rb"))==NULL)
    {
      printf ("can not open file\n");
      exit(0);
    }    
  printf ("original data:\n");
  //读取磁盘文件上的信息到emp数组中
  for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp2)!=0;i++)
    printf ("%8s%7d\n",emp[i].name,emp[i].salary);
  n=i;
  fclose(fp2);
  printf ("input name which do you want to delete:\n");
  scanf("%s",name);  //输入要删除的员工姓名
  for (flag=1,i=0; flag&&i<n; i++)
    {
      if (strcmp(name,emp[i].name)==0)  //查找与输入姓名相匹配的位置
{
  for (j=i; j<n-1; j++)
    {
      //查找到要删除信息的位置后将后面信息前移
      strcpy(emp[j].name,emp[j+1].name);
      emp[j].salary=emp[j+1].salary;
    }
  flag=0;//标志位置0
 }
    }
  if (!flag)
    n=n-1;  //记录个数减一
  else
    printf ("not found\n");
  printf ("now,the content of file:\n");
  fp2=fopen(filename,"wb");  //以只写方式打开指定二进制文件
  for(i=0;i<n;i++)
    //将数组中的员工工资信息输出到磁盘文件上
    fwrite(&emp[i],sizeof(struct emploee),1,fp2);
  fclose(fp2);
  fp2=fopen(filename,"rb");  //以只读方式打开指定二进制文件
  //以只读方式打开指定二进制文件
  for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp2)!=0;i++)
    //输出员工工资信息
    printf ("%8s%7d\n",emp[i].name,emp[i].salary);
  fclose(fp2);
  return 0;
}
  */
/****************************************
技巧16：查找文件(没有成功）
****************************************/
/*
#include <stdio.h>
#include <dirent.h>
main()
{
  char *ptr,filename[50];
  printf ("please input the file name you want to search:\n");
  scanf("%s",filename);
  if((ptr=searchpath(filename))!=NULL)
    printf ("the path is:%s\n",ptr);
  else
    printf ("cannot find\n");
  return 0;
}
*/
/****************************************
技巧17:显示目录内同类型文件
****************************************/


/****************************************
技巧18：关闭打开的所有文件
****************************************/
 /*
#include <stdio.h>
int main(int argc, char *argv[])
{
  FILE *fp1,*fp2,*fp3;
  char file1[20],file2[20],file3[20],ch;
  int file_number;
  printf ("please input file1:\n");
  scanf("%s",file1);
  if ((fp1=fopen(file1,"rb"))!=NULL)
    {
      ch=fgetc(fp1);
      while(ch!=EOF)
	{
	  putchar(ch);
	  ch=fgetc(fp1);
	}
    }
  else
    {
      printf ("can not open!\n");
      exit(1);
    }
   printf ("please input file2:\n");
   scanf("%s",file2);
   if ((fp2=fopen(file2,"rb"))!=NULL)
     {
       ch=fgetc(fp2);
       while(ch!=EOF)
	 {
	   putchar(ch);
	   ch=fgetc(fp2);
	 }
     }
   else
     {
       printf ("can not open!\n");
       exit(1);
     }
   printf ("please input file3:\n");
   scanf("%s",file3);
   if ((fp3=fopen(file3,"rb"))!=NULL)
     {
       ch=fgetc(fp3);
       while(ch!=EOF)
	 {
	   putchar(ch);
	   ch=fgetc(fp3);
	 }
     }
   else
     {
       printf ("can not open!\n");
       exit(1);
     }
   file_number=fcloseall();
   printf ("%d files closed\n",file_number);
  return 0;
}
 */
/****************************************
技巧19：错误处理
****************************************/
  /*
#include <stdio.h>
#include <stdio.h>
 void error(int e)
 {
   if(e==0)
     printf ("input error\n");
   else
     printf ("output error\n");
   exit(1);
 }
int main(int argc, char *argv[])
{
  FILE *in,*out;
  int tab,i;
  char ch,filename1[30],filename2[30];
  printf ("please input the filename1:\n");
  scanf("%s",filename1);
  printf ("please input the filename2:\n");
  scanf("%s",filename2);
  if ((in=fopen(filename1,"rb"))==NULL)
    {
      printf ("can not open the file %s.\n",filename1);
      exit(1);    // 跳出程序
    }
  if ((out=fopen(filename2,"wb"))==NULL)
    {
      printf ("can not open the file %s.\n",filename2);
      exit(1);    // 跳出程序
    }
  tab=0;
  ch=fgetc(in);
  while(!feof(in))   //检测是否有读入错误
    {
      if(ferror(in))
	error(0);
      if(ch=='\t')
	{
	  for (i=tab; i<8; i++)
	    {
	      putc(' ',out);
	      if(ferror(out))
		error(1);
	    }
	  tab=0;
	}
      else
	{
	  putc(ch,out);
	  if(ferror(out))
	    error(1);
	  tab++;
	  if(tab==8)
	    tab==0;
	  if(ch=='\n'||ch=='\r')
	    tab=0;
	}
      ch=fgetc(in);
    }
  fclose(in);
  fclose(out);
  return 0;
}
  */

