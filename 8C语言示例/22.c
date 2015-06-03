#include <stdio.h>
main()
{
  char i,j,k;/*i,j,k order a,b,c*/
  for (i='x'; i<'z'; i++)
      for (j='x'; j<'z'; j++)
	{
	  if (i!=j)
	      for (k='x'; k<'z'; k++)
		{
		  if (i!=k&&j!=k)
		    {
		      if (i!='x'&&k!='x'&&k!='z')
			{
			  printf ("order is a--%c\tb--%c\tc--%c\n",i,j,k);
			}
		    }
	        }
	}
  return 0;  
}
//这个程序不正确
