#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD_LEN 8

int main()
{
	struct termios initialrsettings, newrsettings;
	char password[PASSWORD_LEN + 1];
	/*接下来，增加一行语句获取标准输入的当前设置，并把这些值
	保存到刚才创建的termios结构中*/
	tcgetattr(fileno(stdin), &initialrsettings);
	/*对原始的设置做一份副本以便在程序结束时还原设置。在termios
	结构变量newrsettings中关闭ECHO标志，然后提示用户输入密码*/
	newrsettings = initialrsettings;
	newrsettings.c_lflag &= ~ECHO;
	
	printf("Enter password: ");
	/*接下来，用newrsettings变量中的值设置终端属性并读取用户
	输入的密码。最后，将终端属性还原到原来的样子并输出刚才读取的
	密码（着只是为了说明回显功能恢复了，在实际程序中不要输出密码）。*/
	if(tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings) != 0) {
		fprintf(stderr,"Could not set attributes\n");
	}
	else {
		fgets(password, PASSWORD_LEN, stdin);
		tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
		fprintf(stdout, "\nYou entered %s\n", password);
	}
	exit(0);
}
