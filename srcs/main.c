/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:17:31 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/25 19:05:02 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int     ft_num_env(char **av)
{
	int     i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	**ft_copy_env(char **env)
{
	char	**dst;
	int		i;

	i = 0;
	dst = (char **)malloc(sizeof(char *) * (ft_num_env(env) + 1));
	while (env[i])
	{
		dst[i] = ft_strdup(env[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

int		main(int ac, char **av, char **env)
{
	char	**my_env;
	char	**str;
	int		i;

	str = NULL;
	my_env = ft_copy_env(env);
	while (1)
	{
		i = ac - ac;
		if (str && ft_strcmp(str[0], "exit") == 0)
			break ;
		if (str != NULL)
			ft_mass2del(&str);
		ft_putstr("$> ");
		str = ft_readline(0);
		while (str[i])
		{
			ft_interpretator(str[i], av, &my_env);
			i++;
		}
	}
	ft_mass2del(&str);
	ft_mass2del(&my_env);
	return (0);
}
