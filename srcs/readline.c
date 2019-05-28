/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:58:56 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/05/28 17:00:28 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_readline(int ret)
{
	char    buff[9999];
	char    *str;

	ret = read(1, buff, 9999);
	buff[ret - 1] = '\0';
	str = ft_strjoin("", buff);
	return (str);
}
