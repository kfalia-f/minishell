/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:02:14 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/05/29 17:51:42 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_error(char *cmd)
{
	write(2, "pwd: too many arguments\n", 24);
	(void)cmd;
}

void		ft_pwd(char *cmd)
{
	char	dir[999];
	int		i;

	i = 3;
	while (cmd[i])
	{
		if (cmd[i] != '\0' && cmd[i] != ' ')
		{
			ft_error(cmd);
			return ;
		}
		i++;
	}
	getcwd(dir, 999);
	ft_putendl(dir, 0);
}
