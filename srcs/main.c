/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:17:31 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/05/28 17:25:21 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		main()
{
	char	*str;

	str = NULL;
	while (1)
	{
		if (str && ft_strcmp(str, "exit") == 0)
			break ;
		if (str != NULL)
			ft_strdel(&str);
		ft_putstr("$>");
		str = ft_readline(0);
		ft_interpretator(str);
	}
	free(str);
	return (0);
}
