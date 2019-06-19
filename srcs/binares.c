/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binares.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:12:59 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/06/19 18:25:52 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_num_env(char **av)
{
	int		i;

	i = 2;
	while (av[i])
		i++;
	return (i);
}

char	**ft_pull_env(char **av, int n)
{
	char **arr;
	int i;

	i = 2;
	arr = (char **)malloc(sizeof(char *) * n);
	while (av[i])
	{
		arr[i - 2] = ft_strjoin(av[i], "");
		i++;
	}
	arr[i - 2] = NULL;
	return (arr);
}

char	**ft_get_args(char *cmd)
{
	char	*a;
	char	**res;

	a = cmd;
	while (*a != ' ')
		a++;
	a++;
	res = ft_strsplit(a, ' ');
	return (res);
}

void	ft_binaries(char *cmd, char **av)
{
	char	**env;
	char	**args;
	char	*bin;
	char	*fw;
	int		i;

	(void)cmd;
	i = ft_num_env(av);
	fw = ft_first_word(cmd);
	bin = ft_strjoin("/bin/", fw);
	//env = (char **)malloc(sizeof(char *) * i);
	env = ft_pull_env(av, i);
	args = ft_get_args(cmd);
	execve(bin, args, env);
	free(bin);
	free(fw);
	ft_mass2del(&env);
	ft_mass2del(&args);
}
