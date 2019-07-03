/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binares.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:12:59 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/03 16:27:18 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**ft_get_args(char *cmd)
{
	char	**res;

	res = ft_strsplit(cmd, ' ');
	return (res);
}

int		ft_execute(char *bin, char **args, char **env)
{
	int i;

	i = 1;
	if (fork() == 0)
	{
		if (execve(bin, args, env) == -1)
			i = 0;
	}
	else
		wait (NULL);
	if (i)
		return (1);
	return (0);
}

int		ft_binaries(char *cmd, char **av, char **env)
{
	//char	**env;
	char	**args;
	char	*bin;
	char	*fw;
	int		i;

	if (ft_strcmp(cmd, "stop") == 0)
		return (1);
	if ((bin = ft_check_binaries(cmd, av)) == NULL)
		return (0);
	i = ft_num_env(av);
	fw = ft_first_word(cmd);
	//env = ft_pull_env(av, i);
	args = ft_get_args(cmd);
	i = 0;
	if (ft_execute(bin, args,env))
		i = 1;
	free(bin);
	free(fw);
	ft_mass2del(&env);
	ft_mass2del(&args);
	if (i)
		return (1);
	return (0);
}
