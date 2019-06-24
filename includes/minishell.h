/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:16:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/06/24 16:29:42 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define CN 3

# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <libft.h>

char	*ft_readline(int ret);
void	ft_interpretator(char *cmd, char **av);
void	ft_cd(char *cmd);
void	ft_env(char *cmd, char **av);
int		ft_binaries(char *cmd, char **av);
int		ft_check_binaries(char *cmd, char **av);
#endif
