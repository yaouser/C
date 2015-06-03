#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
/*我们先定义一个RECORD数据结构，然后创建出NRECORDS个记录，每个记录中保存
着它们各自的编号。然后把这些记录都追加到文件records.dat里去。*/
typedef struct {
	int integer;
	char string[24];
} RECORD;

#define NRECORDS (100)

int main()
{
	RECORD record, *mapped;
	int i, f;
	FILE *fp;
	
	fp = fopen("records.dat","w+");
	for(i=0; i<NRECORDS; i++) {
		record.integer = i;
		sprintf(record.string,"RECORD-%d",i);
		fwrite(&record,sizeof(record),1,fp);
}
fclose(fp);
/*我们把第43条记录中的整数值由43修改为143，并把它写入第43条记录中的字符串。*/
fp = fopen("records.dat","r+");
fseek(fp,43*sizeof(record),SEEK_SET);
fread(&record,sizeof(record),1,fp);

record.integer = 143;
sprintf(record.string,"RECORD-%d",record.integer);

fseek(fp,43*sizeof(record),SEEK_SET);
fwrite(&record,sizeof(record),1,fp);
fclose(fp);
/*现在把这些记录映射到内存中，然后访问第43条记录，把它的整数值修改为243（同时
更新该记录中的字符串），使用的还是内存映射的方法。*/
f = open("records.dat",O_RDWR);
mapped = (RECORD *)mmap(0, NRECORDS*sizeof(record),
			PROT_READ|PROT_WRITE, MAP_SHARED, f, 0);

mapped[43].integer = 243;
sprintf(mapped[43].string,"RECORD-%d",mapped[43].integer);

msync((void *)mapped, NRECORDS*sizeof(record), MS_ASYNC);
munmap((void *)mapped, NRECORDS*sizeof(record));
close(f);

exit(0);
}
