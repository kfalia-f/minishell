/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:03:39 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/06/19 17:34:40 by kfalia-f         ###   ########.fr       */
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
	arr[0] = ft_strjoin("", "exit");
	arr[1] = ft_strjoin("", "pwd");
	arr[2] = ft_strjoin("", "cd");
	arr[3] = ft_strjoin("", "echo");
	arr[4] = ft_strjoin("", "env");
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

void			ft_interpretator(char *cmd, char **av)
{
	char	*fw;

	fw = ft_first_word(cmd);
	if (!ft_check_command(fw))
		ft_error(fw);
	if (ft_strcmp(fw, "cd") == 0)
		ft_cd(cmd);
	if (ft_strcmp(fw, "pwd") == 0)
		ft_pwd(cmd);
	if (ft_strcmp(fw, "echo") == 0)
		ft_echo(cmd);
	if (ft_strcmp(fw, "env") == 0)
		ft_env(cmd, av);
	ft_binaries(cmd, av);
	free(fw);
}
