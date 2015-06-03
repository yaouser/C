#include <stdio.h>
int main(int argc, char *argv[])
{
  long int i;
  int bonus1,bonus2,bonus4,bonus6,bonus10,bonus;
  scanf ("%ld",&i);
  bonus1=100000*0.1;
  bonus2=bonus1+100000*0.075;
  bonus4=bonus2+200000*0.05;
  bonus6=bonus4+200000*0.03;
  bonus10=bonus6+400000*0.015;
  if(i<=100000)
    bonus=i*0.1;
  else if(i<=200000)
      bonus=bonus1+(i-100000)*0.075;
  else if(i<=400000)
    bonus=bonus2+(i-200000)*0.05;
  else if(i<=600000)
    bonus=bonus4+(i-400000)*0.03;
  else if(i<=1000000)
    bonus=bonus6+(i-600000)*0.015;
  else 
    bonus=bonus10+(i-1000000)*0.01;
  printf ("bonus=%d\n",bonus);
  return 0;
}
