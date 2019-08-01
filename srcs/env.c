/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:25:39 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/01 17:59:58 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_unsetenv(char *cmd, char ***env)
{
	char	**tmp;
	char	*line;
	int		len;
	int		i;
	int		k;

	if (!(line = ft_2nd_word(cmd, env)))
		return ;
	len = ft_strlen(line);
	i = 0;
	k = 0;
	tmp = (char **)malloc(sizeof(char *) * ft_num_env(*env));
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], line, len) != 0)
		{
			tmp[k] = ft_strdup((*env)[i]);
			k++;
		}
		i++;
	}
	tmp[k] = NULL;
	ft_mass2del(env);
	free(line);
	*env = tmp;
}

void	ft_env(char *cmd, char ***env)
{
	char	*fw;
	int		i;

	i = 0;
	fw = ft_first_word(cmd);
	if (ft_strcmp(fw, "unsetenv") == 0)
	{
		ft_unsetenv(cmd, env);
		free(fw);
		return ;
	}
	if (ft_strcmp(fw, "setenv") == 0)
	{
		ft_setenv(cmd, env);
		free(fw);
		return ;
	}
	while ((*env)[i])
	{
		ft_putendl((*env)[i], 0);
		i++;
	}
	free(fw);
}
