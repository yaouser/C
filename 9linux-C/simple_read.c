#include <unistd.h>
#include <stdlib.h>
/*read系统调用*/
/*这个程序把标准输入的前128个字节复制到标准输出。
如果输入少于128个字节，就把它们全体复制过去。*/
int main()
{
	char buffer[128];
	int nread;

	nread = read(0,buffer,128);
	if ( nread == -1)
		write(2,"A read error has occurred\n",26);

	if ((write(1,buffer,nread)) != nread)
		write(2,"A write error has occurred\n",27);

	exit(0);
}

/*运行echo hello there | ./simple_read*/
