/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:17:31 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/03 19:00:11 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int     ft_num_env(char **av)
{
	int     i;

	i = 2;
	while (av[i])
		i++;
	return (i);
}

char    **ft_pull_env(char **av, int n)
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

int		main(int ac, char **av)
{
	char	**env;
	char	*str;

	str = NULL;
	(void)ac;
	env = ft_pull_env(av, ft_num_env(av));
	while (1)
	{
		if (str && ft_strcmp(str, "exit") == 0)
			break ;
		if (str != NULL)
			ft_strdel(&str);
		ft_putstr("$> ");
		str = ft_readline(0);
		ft_interpretator(str, av, env);
	}
	free(str);
	ft_mass2del(&env);
	return (0);
}
