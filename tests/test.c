#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "../libft/includes/libft.h"

int		main(int ac, char **av)
{
	char *env_args[] = { (char*)0 };
	char *args[] = {"/bin/ls", "-lG", "../../../", (char *)0};

	execve(args[0], args, env_args);
	return (0);
}
