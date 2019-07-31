/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:27:25 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/31 19:30:12 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_tabsdel_continue(char **cmd, char *str, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (j < len)
		(*cmd)[j++] = str[i++];
	(*cmd)[j] = '\0';
	return (*cmd);
}

char	*ft_tabsdel(char *str)
{
	char	*cmd;
	int		i;
	int		j;
	int		len;

	cmd = NULL;
	i = 0;
	len = ft_strlen(str);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	j = len;
	len -= i;
	i = j;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\0'))
		i--;
	len -= (j - i) - 2;
	cmd = ft_memalloc(len + 1);
	if (len == 2)
		return (NULL);
	return (ft_tabsdel_continue(&cmd, str, len));
}
