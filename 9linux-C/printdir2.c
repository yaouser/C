int main(int argc, char* argv[])
{
	char *topdir = ".";
	if (argc >= 2)
		topdir=argv[1];

	printf("Directory scan of %s\n",topdir);
	printdir(topdir,0);
	printf("done.\n");

	exit(0);
}

