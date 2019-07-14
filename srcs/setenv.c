/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:43:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 18:15:13 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_env_name(char *sc_word)
{
	char	*env_name;
	int		i;
	int		k;

	i = 0;
	while (sc_word[i] && sc_word[i] != '=')
		i++;
	if (sc_word[i] == '\0' || sc_word == NULL)
	{
		ft_putendl_fd("usage: setenv [ENV]=[value]", 2);
		free(sc_word);
		return (NULL);
	}
	env_name = ft_memalloc(i);
	k = 0;
	while (k < i)
	{
		env_name[k] = sc_word[k];
		k++;
	}
	return (env_name);
}

void	ft_add_env(char ***env, char *sc_word)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = (char **)malloc(sizeof(char *) * (ft_num_env(*env) + 3));
	while ((*env)[++i])
		tmp[i] = ft_strjoin((*env)[i], "");
	tmp[i] = NULL;
	ft_mass2del(env);
	*env = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (tmp[++i])
		(*env)[i] = ft_strjoin(tmp[i], "");
	(*env)[i] = ft_strjoin(sc_word, "");
	(*env)[i + 1] = NULL;
}

void	ft_setenv(char *cmd, char ***env)
{
	char	*line;
	char	*env_name;
	int		i;
	int		len;

	if (!(line = ft_2nd_word(cmd)))
		return ;
	if (!(env_name = ft_env_name(line)))
		return ;
	i = 0;
	len = ft_strlen(env_name);
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], env_name, len) == 0)
		{
			ft_strdel(&((*env)[i]));
			(*env)[i] = ft_strjoin(line, "");
			break ;
		}
		i++;
	}
	if ((*env)[i] == NULL)
		ft_add_env(env, line);
	free(line);
	free(env_name);
}
