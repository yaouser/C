#include <stdio.h>
#define MAX
#define MIN
#define MAXIMUM(x,y) (x>y)?x:y
#define MINIMUM(x,y) (x>y)?y:x
void main()
{
  int a=10,b=20;

  #ifdef MAX
  printf ("the larger one is %d\n",MAXIMUM(a,b));
  #else
  printf ("the lower one is %d\n",MINIMUM(a,b));
  #endif

  #ifndef MIN
  printf ("the lower one is %d\n",MINIMUM(a,b));
  #else
  printf ("the larger one is %d\n",MAXIMUM(a,b));
  #endif

  #undef MAX
  #ifdef MAX
  printf ("the larger one is %d\n",MAXIMUM(a,b));
  #else
  printf ("the lower one is %d\n",MINIMUM(a,b));
  #endif

  #ifndef MIN
  printf ("the lower one is %d\n",MINIMUM(a,b));
  #else
  printf ("the larger one is %d\n",MAXIMUM(a,b));
  #endif
}
