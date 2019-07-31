/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:02:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/31 17:14:50 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_print_str(char *sc_w)
{
	int		i;

	i = 0;
	while (sc_w[i])
	{
		if (sc_w[i] != 34 && sc_w[i] != 39)
			write(1, &(sc_w[i]), 1);
		i++;
	}
}

void	ft_spdel(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != '\t' && str[i] != ' ')
			ft_putchar(str[i++]);
		if (str[i])
			write(1, " ", 1);
		while (str[i] && (str[i] == '\t' || str[i] == ' '))
			i++;
	}
}

void	ft_print(char **res)
{
	int		i;

	i = 0;
	while (res[i])
	{
		if ((i % 2 == 0) || i == 0)
		{
			if (i > 1)
				write(1, " ", 1);
			ft_spdel(res[i]);
		}
		else
			ft_print_str(res[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_echo(char *cmd)
{
	char	**res;
	char	*sc_w;
	int		i;

	i = 0;
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
		i++;
	sc_w = ft_strdup(cmd + i + 1);
	res = ft_strsplit(sc_w, '"');
	ft_print(res);
	ft_mass2del(&res);
	free(sc_w);
}
