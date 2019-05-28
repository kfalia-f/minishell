#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int		main(int ac, char **av)
{
	char str[10];

	write(1, "$>", 2);
	while (SIGINT)
	{
		scanf("%s", str);
		printf("%s\n", str);
	}
	return (0);
}
