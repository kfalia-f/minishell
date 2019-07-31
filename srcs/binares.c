/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binares.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:12:59 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/31 19:48:53 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**ft_get_args(char *cmd)
{
	char	**res;

	res = ft_strsplit(cmd, ' ');
	return (res);
}

int		ft_execute(char *bin, char **args, char ***env)
{
	int i;

	i = 1;
	if (fork() == 0)
	{
		if (execve(bin, args, *env) == -1)
			i = 0;
	}
	else
		wait(NULL);
	if (i)
		return (1);
	return (0);
}

int		ft_check_bin(char *cmd, char ***env)
{
	struct stat	buff;
	char		**args;
	char		*fw;
	int			i;

	i = 0;
	fw = ft_first_word(cmd);
	args = ft_get_args(cmd);
	stat(fw, &buff);
	if (!access(fw, 1) && S_ISREG(buff.st_mode))
	{
		i = 1;
		ft_execute(fw, args, env);
	}
	free(fw);
	ft_mass2del(&args);
	return (i);
}

int		ft_binaries(char *cmd, char ***env)
{
	char	**args;
	char	*bin;
	char	*fw;
	int		i;

	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	if (ft_check_bin(cmd, env) == 1)
		return (1);
	if ((bin = ft_check_binaries(cmd, env)) == NULL)
		return (0);
	fw = ft_first_word(cmd);
	args = ft_get_args(cmd);
	i = 0;
	if (ft_execute(bin, args, env))
		i = 1;
	free(bin);
	free(fw);
	ft_mass2del(&args);
	if (i)
		return (1);
	return (0);
}
