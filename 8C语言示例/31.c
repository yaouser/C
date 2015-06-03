#include <stdio.h>
main()
{
  char letter;
  printf ("please input the first letter of someday\n");
  while((letter=getchar())!='y')
    {
      if((letter=getchar())=='s')
	printf ("please input second letter\n");
	else  if((letter=getchar())=='a')
	    printf ("saturday\n");
	  else if((letter=getchar())=='u')
		  printf ("sunday\n");
		  else printf ("data error\n");
      if((letter=getchar())=='f')
	  printf ("friday\n");
      if((letter=getchar())=='m')
          printf ("monday\n");
      if((letter=getchar())=='t')
          printf ("please input second letter\n");
      else  if((letter=getchar())=='u')
		    printf ("tuesday\n");
      else if((letter=getchar())=='h')
	  printf ("thursday\n");
      else 
	  printf ("data error\n");
      if((letter=getchar())=='w')
          printf ("wednesday\n");
      printf ("data error\n");
    }
  return 0;
}


//这个程序没有很好的运行
