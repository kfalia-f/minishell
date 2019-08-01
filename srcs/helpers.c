/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:27:25 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/01 18:04:58 by kfalia-f         ###   ########.fr       */
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
	ft_putnbr(len);
	cmd = ft_memalloc(len + 1);
	if (len == 2)
		return (NULL);
	return (ft_tabsdel_continue(&cmd, str, len));
}

void	ft_tild(char **path, char ***env)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strlen(*path) == 1)
		return ;
	while ((*env)[i])
	{
		if (!ft_strncmp((*env)[i], "HOME", 4))
			break ;
		i++;
	}
	tmp = ft_strjoin((*env)[i] + 5, *path + 1);
	ft_strdel(path);
	*path = tmp;
}
