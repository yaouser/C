#include <stdio.h>
int main(void)
{
  int score;
  char grade;
  printf ("please input a score:");
  scanf("%d",&score);
  grade=(score>=90?'A':(score>=60?'B':'C'));
  printf ("%d is belongs to %c\n",score, grade);
  return 0;
}
