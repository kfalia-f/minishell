/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:59:44 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/03 16:00:31 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char		*ft_2nd_word(char *cmd)
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
	path = ft_memalloc(len + 1);
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

char	*ft_find_home(char **av)
{
	int		i;
	int		j;
	char	*path;

	i = 2;
	j = 0;
	path = NULL;
	while (av[i])
	{
		if (ft_strncmp(av[i], "HOME", 4) == 0)
			break ;
		i++;
	}
	if (av[i] == NULL)
		return (".");
	while (av[i][j] && av[i][j] != '=')
		j++;
	path = ft_strjoin(av[i] + j + 1, "");
	return (path);
}

void	ft_cd(char **av, char *cmd)
{
	char	*path;

	if (!ft_valid_command(cmd))
		return ;
	path = ft_2nd_word(cmd);
	if (path == NULL)
		chdir(path = ft_find_home(av));
	else if(chdir(path) == -1)
		ft_error(cmd, 2);
	if (path)
		free(path);
}
