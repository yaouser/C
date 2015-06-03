#include <stdio.h>
varfunc()
{
  int var=0;
  static int static_var=0;
  printf ("var equal %d\n",var);
  printf ("static var equal %d\n",static_var);
  printf ("\n");
  var++;
  static_var++;
}
int main(int argc, char *argv[])
{
  int i;
  for (i=0; i<3; i++)
    {
      varfunc();
    }
  return 0;
}

//static 静态的声明是，一但常量被改变后就保存到内存中改变后的值
//而一般声明的常量，再次调用函数时，声明的常量不变
