#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "../libft/includes/libft.h"
#include <sys/ioctl.h>

int		main(int ac, char **av)
{
	(void)ac;
	if (access(av[1], 1))
		printf("yes");
	else
		printf("no");
	return (0);
}
