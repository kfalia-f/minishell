/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:17:31 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/05/28 15:56:23 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		main(int ac, char **av)
{
	char	buff[9999];
	char	*str;
	int		ret;

	if (ac > 0)
		av[1] = NULL;
	str = NULL;
	while (1)
	{
		if (str && ft_strcmp(str, "exit") == 0)
			break ;
		if (str != NULL)
			ft_strdel(&str);
		ft_putstr("$>");
		ret = read(1, buff, 100);
		buff[ret - 1] = '\0';
		str = ft_strjoin("", buff);
	}
	return (0);
}
