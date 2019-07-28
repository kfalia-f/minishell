/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 20:48:33 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/28 21:38:48 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_get_oldpwd(char ***env, int flag)
{
	int		i;
	int		j;
	char	*opwd;

	i = 0;
	j = 0;
	if (flag)
		while (ft_strncmp((*env)[i], "PWD", 3))
			i++;
	else
		while (ft_strncmp((*env)[i], "OLDPWD", 6))
			i++;
	while ((*env)[i][j] && (*env)[i][j] != '=')
		j++;
	opwd = ft_strdup((*env)[i] + j + 1);
	return (opwd);
}

void	ft_change_path(char ***env)
{
	char	*new_pwd;
	char	*new_opwd;
	char	*opwd;
	char	dir[999];

	getcwd(dir, 999);
	opwd = ft_get_oldpwd(env, 1);
	new_pwd = ft_strjoin("t PWD=", dir);
	new_opwd = ft_strjoin("t OLDPWD=", opwd);
	ft_setenv(new_pwd, env);
	ft_setenv(new_opwd, env);
	free(opwd);
	free(new_pwd);
	free(new_opwd);
}

void	ft_cd_past(char ***env)
{
	char	*path;

	path = ft_get_oldpwd(env, 0);
	chdir(path);
	ft_putendl(path, 0);
	ft_change_path(env);
	free(path);
}
