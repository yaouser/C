#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL,
};

int getchoice(char *greet, char *choices[], FILE *in, FILE *out);
int main()
{
	int choice = 0;
	FILE *input;
	FILE *output;
	struct termios initial_settings, new_settings;

	if(!isatty(fileno(stdout))) {
		fprintf(stderr,"You are not a terminal, OK.\n");
	}

	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");
	if(!input || !output) {
		fprintf(stderr, "Unable to open /dev/tty\n");
		exit(1);
	}
	tcgetattr(fileno(input),&initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_lflag &= ~ISIG;
	if(tcsetattr(fileno(input), TCSANOW, &new_settings) != 0) {
		fprintf(stderr,"could not set attributes\n");
	}
	do {
		choice = getchoice("Please select an action", menu, input,output);
		printf("You have chosen: %c\n", choice);
	} while (choice != 'q');
	tcsetattr(fileno(input), TCSANOW,&initial_settings);
	exit(0);
}

int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
	int chosen = 0;
	int selected;
	char **option;

	do {
		fprintf(out, "Choice: %s\n", greet);
		option = choices;
		while(*option) {
			fprintf(out, "%s\n", *option);
			option++;
		}
		do {
			selected = fgetc(in);
		} while (selected == '\n' || selected == '\r');
		option = choices;
		while(*option) {
			if(selected == *option[0]) {
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen) {
			fprintf(out, "Incorrect choice, select again\n");
		}
	} while(!chosen);
	return selected;
}
