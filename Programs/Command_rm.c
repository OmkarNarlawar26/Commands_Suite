#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/utsname.h>

// 	./rmx		FileName
// 	argv[0]		argv[1]
// 	argc = 2

/*
	Call the system call unlink
	
*/

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Insufficient Argument\n");
		printf("use as ./rmx Path\n");
		return -1;
	}

	if(access(argv[1], F_OK) == 0)
	{
		if(unlink(argv[1]) == -1)
		{
			printf("Error : Unable to delete\n");
			return -1;
		}
		else
		{
			printf("Success : File gets deleted\n");
		}
	}
	else
	{
		printf("Error : Unable to delete as file is not present\n");
	}
	
	return 0;
}
