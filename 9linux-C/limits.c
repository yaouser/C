#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*void work()函数将一个字符串写入一个临时文件10000次，然后做一些算术运算以产生
CPU负载*/
void work()
{
	FILE *f;
	int i;
	double x = 4.5;

	f = tmpfile();
	for(i=0; i < 10000; i++) {
		fprintf(f,"Do some output\n");
		if(ferror(f)) {
			fprintf(stderr,"Error writing to temporary file\n");
			exit(1);
		}
	}
	for(i=0;i<1000000;i++)
		x = log(x*x + 3.21);
}
/*main按数调用work函数，然后用getrusage函数来发现它耗费的CPU时间，并把该信息
显示在屏幕上*/
int main()
{
	struct rusage r_usage;
	struct rlimit r_limit;
	int priority;

	work();
	getrusage(RUSAGE_SELF, &r_usage);

	printf("CPU usage: User = %ld.%06ld, System = %ld.%06ld\n",
		r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,
		r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);
	/*接着，main函数分别调用getpriority和getrlimit来发现它的当前优先级
	和文件大小限制*/
	priority = getpriority(PRIO_PROCESS, getpid());
	printf("Current priority = %d\n", priority);

	getrlimit(RLIMIT_FSIZE, &r_limit);
	printf("Current FSIZE limit: soft = %ld, hard = %ld\n",
		r_limit.rlim_cur, r_limit.rlim_max);
	/*最后，我们用setrlimit设置文件大小限制并再次调用work，这次work函数
	的执行会失败，因为它试图创建一个太大的文件*/
	r_limit.rlim_cur = 2048;
	r_limit.rlim_max = 4096;
	printf("Setting a 2K file size limit\n");
	setrlimit(RLIMIT_FSIZE, &r_limit);

	work();
	exit(0);
}

