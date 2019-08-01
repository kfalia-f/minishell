/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:58:56 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/01 22:29:38 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_find_env(char *str, char **env)
{
	char	*name;
	char	*tmp;
	int		i;
	int		len;

	i = -1;
	tmp = NULL;
	while (str[++i])
		if (!ft_isalpha(str[i]) || str[i] == 47)
			break ;
	tmp = ft_memalloc(i + 1);
	ft_strncpy(tmp, str, i);
	name = ft_strjoinre(tmp, "=");
	len = i;
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], name, ft_strlen(name)))
		{
			free(name);
			return (ft_strdup(env[i] + len + 1));
		}
	}
	free(name);
	return (ft_strdup(""));
}

void	ft_find_doll(char **arr, char **env)
{
	char	*tmp;
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_memalloc(1000);
	while ((*arr)[i])
	{
		if ((*arr)[i] == '$')
		{
			i++;
			dst = ft_find_env(*arr + i, env);
			tmp = ft_strcat(tmp, dst);
			j += ft_strlen(dst);
			while ((*arr)[i] && (ft_isalpha((*arr)[i]) || (*arr)[i] == 47))
				i++;
			free(dst);
		}
		tmp[j++] = (*arr)[i];
		i++;
	}
	tmp = ft_strjoinre(tmp, "");
	free(*arr);
	*arr = tmp;
}

void	ft_change_line(char ***arr, char **env)
{
	int		i;

	i = 0;
	while ((*arr)[i])
	{
		ft_find_doll(&(*arr)[i], env);
		i++;
	}
}

char	**ft_readline(int ret, char **env)
{
	char	buff[9999];
	char	**str;

	ret = read(1, buff, 9999);
	buff[ret - 1] = '\0';
	str = ft_strsplit(buff, ';');
	ft_change_line(&str, env);
	return (str);
}
