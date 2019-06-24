/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_binaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:30:06 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/06/24 19:34:03 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_find_line(char **av, char *line)
{
	int		i;
	int		j;

	i = 2;
	while (av[i])
	{
		j = 0;
		while (line[j])
		{
			if (line[j] != av[i][j])
				break ;
			j++;
		}
		if (line[j] == '\0')
			return (i);
		i++;
	}
	return (0);
}

char	**ft_cut(char *str, char c)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == '\0')
		return (NULL);
	res = ft_strjoin(str + i + 1, "");
	return (ft_strsplit(res, ':'));
}

char	*ft_find_bin(char *cmd, char **dirs)
{
	DIR				*dirp;
	struct dirent	*dp;
}

char	ft_check_binaries(char *cmd, char **av)
{
	char	**dirs;
	char	*bin;
	char	*path;
	int		i;

	(void)cmd;
	i = ft_find_line(av, "PATH=");
	path = ft_strjoin(av[i], "");
	dirs = ft_cut(path, '=');
	free (path);
	bin = ft_find_bin(cmd, dirs);
	ft_mass2del(&dirs);
	return (bin);
}
