#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	char c;
	int in, out;
	
	in = open("file.in", O_RDONLY);
	out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	while(read(in,&c,1) == 1)
		write(out,&c,1);

	exit(0);
}

/*注意，#include <unistd.h>行必须首先出现，因为它定义的与POSIX规范有关的
标志可能会影响到其它的头文件。*/
//运行这个程序
//TIMEFORMAT=“” time ./copy_system
//ls -ls file.in file.out
