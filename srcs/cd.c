/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:59:44 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/01 18:00:33 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char		*ft_2nd_word(char *cmd, char ***env)
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
	while (cmd[len] && cmd[len] != ' ' && cmd[len] != '\t')
		len++;
	if (i == len)
		return (NULL);
	len -= i;
	path = ft_memalloc(len + 1);
	len = 0;
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
		path[len++] = cmd[i++];
	path[len] = '\0';
	if (ft_strchr(path, '~') != NULL)
		ft_tild(&path, env);
	return (path);
}

static void	ft_error(char *cmd, int en, char ***env)
{
	char		*fw;
	char		*sw;

	sw = ft_2nd_word(cmd, env);
	if (en == 2 && !ft_strncmp(sw, "$", 1))
	{
		ft_cd_doll(sw, env);
		free(sw);
		return ;
	}
	fw = ft_first_word(cmd);
	ft_putstr_base(fw, 2);
	if (en == 1)
		ft_putstr_base(": string not in pwd: ", 2);
	if (en == 2)
		ft_putstr_base(": no such file or directory: ", 2);
	if (en == 3)
		ft_putstr_base(": permission dinaed: ", 2);
	if (en == 4)
		ft_putstr_base(": not a directory: ", 2);
	ft_putstr_base(sw, 2);
	ft_putchar_base('\n', 2);
	free(sw);
	free(fw);
}

static int	ft_valid_command(char *cmd)
{
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	while (cmd[i])
	{
		while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
			i++;
		if (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
			ct++;
		if (ct > 2)
		{
			ft_error(cmd, 1, NULL);
			return (0);
		}
		while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
			i++;
	}
	return (1);
}

char		*ft_find_home(char **av)
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

void		ft_cd(char **av, char ***env, char *cmd)
{
	struct stat	buff;
	char		*path;

	if (!ft_valid_command(cmd))
		return ;
	path = ft_2nd_word(cmd, env);
	if (!path || (ft_strlen(path) == 1 && !ft_strncmp(path, "~", 1)))
	{
		chdir(path = ft_find_home(av));
		ft_change_path(env);
	}
	else if (!ft_strncmp(path, "-", 1) && ft_strlen(path) == 1)
		ft_cd_past(env);
	else if (stat(path, &buff) < 0)
		ft_error(cmd, 2, env);
	else if (!S_ISDIR(buff.st_mode))
		ft_error(cmd, 4, env);
	else if (chdir(path) == -1)
		ft_error(cmd, 3, env);
	else
		ft_change_path(env);
	if (path)
		free(path);
}
