/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:25:39 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 14:43:22 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_unsetenv(char *cmd, char ***env)
{
	char	*line;
	int		len;
	int		i;

	if (!(line = ft_2nd_word(cmd)))
		return ;
	len = ft_strlen(line);
	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], line, len) == 0)
		{
			free((*env)[i]);
			(*env)[i] = ft_strjoin("#DEL",  "");
			break ;
		}
		i++;
	}
	free(line);
}

void	ft_env(char *cmd, char **env)
{
	//	char	**env;
	char	*fw;
	int		i;

	i = 0;
	fw = ft_first_word(cmd);
	//env = ft_pull_env(av, ft_num_env(av));
	if (ft_strcmp(fw, "unsetenv") == 0)
	{
		ft_unsetenv(cmd, &env);
		free(fw);
		return ;
	}
	if (ft_strcmp(fw, "setenv") == 0)
	{
		ft_setenv(cmd, &env);
		free(fw);
		return ;
	}
	while (env[i])
	{
		if (ft_strcmp(env[i], "#DEL") != 0)
			ft_putendl(env[i], 0);
		i++;
	}
	free(fw);
}
