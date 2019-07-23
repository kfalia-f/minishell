/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_binaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:30:06 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/23 18:50:21 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_find_line(char ***av, char *line)
{
	int		i;
	int		j;

	i = 0;
	while ((*av)[i])
	{
		j = 0;
		while (line[j])
		{
			if (line[j] != (*av)[i][j])
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
	char	**arr;
	char	*res;
	int		i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == '\0')
		return (NULL);
	res = ft_strjoin(str + i + 1, "");
	arr = ft_strsplit(res, ':');
	free(res);
	return (arr);
}

char	*ft_find_bin(char *cmd, char **dirs)
{
	DIR				*dirp;
	struct dirent	*dp;
	char			*fw;
	char			*res;
	int				i;

	i = 0;
	dirp = NULL;
	fw = ft_first_word(cmd);
	while (dirs[i])
	{
		dirp = opendir(dirs[i]);
		while ((dp = readdir(dirp)))
			if (ft_strcmp(fw, dp->d_name) == 0)
			{
				res = ft_str_path(dirs[i], fw);
				closedir(dirp);
				free(fw);
				return (res);
			}
		closedir(dirp);
		i++;
	}
	free(fw);
	return (NULL);
}

int		ft_exception(char *cmd)
{
	char	*fw;

	fw = NULL;
	fw = ft_first_word(cmd);
	if (ft_strcmp(fw, "cd") == 0 || ft_strcmp(fw, "env") == 0)
	{
		free(fw);
		return (1);
	}
	free(fw);
	return (0);
}

char	*ft_check_binaries(char *cmd, char ***env)
{
	char	**dirs;
	char	*bin;
	char	*path;
	int		i;

	if (ft_exception(cmd))
		return (NULL);
	bin = NULL;
	if ((i = ft_find_line(env, "PATH=")) == 0)
		return (NULL);
	path = ft_strdup((*env)[i]);
	dirs = ft_cut(path, '=');
	free (path);
	bin = ft_find_bin(cmd, dirs);
	ft_mass2del(&dirs);
	return (bin);
}
