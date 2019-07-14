/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:43:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 16:12:40 by kfalia-f         ###   ########.fr       */
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
	if (sc_word[i] == '\0')
	{
		ft_putstr_base("usage: setenv [ENV]=[value]", 2);
		free(sc_word);
		return (NULL);
	}
	env_name = ft_memalloc(i);
	while (k < i)
	{
		env_name[k] = sc_word[k];
		k++;
	}
	free(sc_word);
	return (env_name);
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
			free((*env)[i]);
			(*env)[i] = ft_strjoin(line, "");
			
		}
	}
}
