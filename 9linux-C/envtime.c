#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int i;
	time_t the_time;
	
	for(i = 1; i <= 10; i++) {
		the_time = time((time_t *)0);
		printf("The time is %ld\n", the_time);
		sleep(2);
	}
	exit(0);
}

