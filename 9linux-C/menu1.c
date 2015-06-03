#include <stdio.h>
#include <stdlib.h>
/*程序开始部分的语句定义了一个用来显示菜单内容的字符数组和getchoice
函数的原型*/
char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL,
};
	
int getchoice(char *greep, char *choices[]);
/*main函数以刚才定义的样本菜单字符数组menu为参数调用getchoice函数*/
int main()
{
	int choice = 0;
	
	do 
	{
		choice = getchoice("Please select an action", menu);
		printf("You have chosen: %c\n", choice);
	} while(choice != 'q');
	exit(0);
}
/*下面是这个程序的核心代码：负责显示菜单及读取用户输入的函数getchoice*/
int getchoice(char *greet, char *choices[])
{
	int chosen = 0;
	int selected;
	char **option;

	do {
		printf("Choice: %s\n",greet);
		option = choices;
		while(*option) {
			printf("%s\n", *option);
			option++;
		}
		selected = getchar();
		option = choices;
		while(*option) {
			if(selected == *option[0]) {
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen) {
			printf("Incorrect choice, select again\n");
		}
	} while(selected == '\n');
	return selected;
}
