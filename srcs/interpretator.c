/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:03:39 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/31 20:09:11 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		ft_error(char *cmd)
{
	ft_putstr_base("minishell: ", 2);
	ft_putstr_base("command not found: ", 2);
	ft_putstr_base(cmd, 2);
	ft_putchar_base('\n', 2);
}

static char		**ft_commands(int n)
{
	char	**arr;

	n = 0;
	arr = (char **)malloc(sizeof(char *) * (CN + 1));
	arr[0] = ft_strdup("exit");
	arr[1] = ft_strdup("cd");
	arr[2] = ft_strdup("env");
	arr[3] = ft_strdup("unsetenv");
	arr[4] = ft_strdup("setenv");
	arr[5] = ft_strdup("echo");
	arr[CN] = NULL;
	return (arr);
}

static int		ft_check_command(char *cmd)
{
	char	**cmds;
	int		i;

	i = 0;
	cmds = ft_commands(0);
	while (cmds[i])
	{
		if (ft_strcmp(cmd, cmds[i]) == 0)
		{
			ft_del(&cmds, CN + 1);
			return (1);
		}
		i++;
	}
	ft_del(&cmds, CN + 1);
	return (0);
}

void			ft_return(char **fw, char **cmd)
{
	ft_error(*fw);
	free(*fw);
	free(*cmd);
}

void			ft_interpretator(char *str, char **av, char ***env)
{
	char	*fw;
	char	*cmd;

	if ((cmd = ft_tabsdel(str)) == NULL)
		return ;
	if (ft_binaries(cmd, env))
	{
		free(cmd);
		return ;
	}
	fw = ft_first_word(cmd);
	if (!ft_check_command(fw))
	{
		ft_return(&fw, &cmd);
		return ;
	}
	if (!ft_strcmp(fw, "echo"))
		ft_echo(cmd);
	if (ft_strcmp(fw, "cd") == 0)
		ft_cd(av, env, cmd);
	if (!ft_strcmp(fw, "env") || !ft_strcmp(fw, "unsetenv")
			|| !ft_strcmp(fw, "setenv"))
		ft_env(cmd, env);
	free(fw);
	free(cmd);
}
