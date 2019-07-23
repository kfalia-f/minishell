/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:17:31 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/23 18:46:25 by kfalia-f         ###   ########.fr       */
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
	char	*str;

	str = NULL;
	(void)ac;
	my_env = ft_copy_env(env);
	while (1)
	{
		if (str && ft_strcmp(str, "exit") == 0)
			break ;
		if (str != NULL)
			ft_strdel(&str);
		ft_putstr("$> ");
		str = ft_readline(0);
		ft_interpretator(str, av, &my_env);
	}
	free(str);
	ft_mass2del(&my_env);
	return (0);
}
