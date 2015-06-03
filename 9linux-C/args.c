#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int arg;
	
	for(arg=0; arg < argc; arg++) {
		if(argv[arg][0] == '-')
			printf("option: %s\n", argv[arg]+1);
		else
			printf("argument %d: %s\n", arg, argv[arg]);
	}
	exit(0);
}

