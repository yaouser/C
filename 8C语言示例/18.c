#include <stdio.h>
int main(int argc, char *argv[])
{
  int a,n,count=1;
  long int sn=0,tn=0;
  printf ("please input a and n(请用逗号分隔开）:\n");
  scanf("%d,%d",&a,&n);
  printf ("a=%d,n=%d\n",a,n);
  while(count<=n)
    {
      tn=tn+a;
      sn=sn+tn;
      a=a*10;
      ++count;
    }
  printf ("a+aa+...=%ld\n",sn);
  return 0;
}
