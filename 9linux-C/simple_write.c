#include <unistd.h>
#include <stdlib.h>
/*write系统调用*/
int main()
{
	if ((write(1,"Here is some data\n",18)) != 18)
		write(2,"A write error has occurred on file descriptor 1\n",46);

	exit(0);
}
