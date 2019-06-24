/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:17:31 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/06/24 16:28:03 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		main(int ac, char **av)
{
	char	*str;

	str = NULL;
	(void)ac;
	while (1)
	{
		if (str && ft_strcmp(str, "stop") == 0)
			break ;
		if (str != NULL)
			ft_strdel(&str);
		ft_putstr("$> ");
		str = ft_readline(0);
		ft_interpretator(str, av);
	}
	free(str);
	return (0);
}
