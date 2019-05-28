/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:59:44 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/05/28 18:57:43 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*ft_2nd_word(char *cmd)
{
	int		i;
	int		len;
	char	*path;

	i = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	len = i;
	while (cmd[len])
		len++;
	if (i == len)
		return (NULL);
	len -= i;
	path = ft_memalloc(len);
	len = 0;
	while (cmd[i] && cmd[i] != ' ')
		path[len++] = cmd[i++];
	path[len] = '\0';
	return (path);
}

static void	ft_error(char *cmd, int en)
{
	char *fw;
	char *sw;

	sw = ft_2nd_word(cmd);
	fw = ft_first_word(cmd);
	ft_putstr_base(fw, 2);
	if (en == 1)
		ft_putstr_base(": string not in pwd: ", 2);
	if (en == 2)
		ft_putstr_base(": no such file or directory: ", 2);
	ft_putstr_base(sw, 2);
	ft_putchar_base('\n', 2);
	free(sw);
	free(fw);
}

static int ft_valid_command(char *cmd)
{
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			ct++;
		while (cmd[i] && cmd[i] == ' ')
			i++;
		if (ct == 2)
		{
			ft_error(cmd, 1);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_cd(char *cmd)
{
	char	*path;

	if (!ft_valid_command(cmd))
		return ;
	path = ft_2nd_word(cmd);
	if (path == NULL)
		chdir("/Users/kfalia-f");
	else if(chdir(path) == -1)
		ft_error(cmd, 2);
}
