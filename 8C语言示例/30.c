#include <stdio.h>
int main(int argc, char *argv[])
{
  long ge,shi,bai,qian,wan,x;
  scanf("%ld",&x);
  wan=x/10000;
  qian=x%10000/1000;
  bai=x%1000/100;
  shi=x%100/10;
  ge=x%10;
  if (ge==wan&&shi==qian)
    {
      printf ("thi number is huiwen\n");
    }
  else
    printf ("this number is not huiwen\n");
  return 0;
}
