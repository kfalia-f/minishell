/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:02:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/28 19:17:20 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_print(char *sc_w)
{
	int		i;

	i = 0;
	while (sc_w[i])
	{
		if (sc_w[i] != 34 && sc_w[i] != 39)
			write(1, &(sc_w[i]), 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_echo(char *cmd)
{
	char	*sc_w;

	sc_w = ft_2nd_word(cmd);
	ft_print(sc_w);
	free(sc_w);
}
