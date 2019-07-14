/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:16:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 17:47:12 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define CN 5

# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <libft.h>

char	*ft_readline(int ret);
void	ft_interpretator(char *cmd, char **av, char **env);
void	ft_cd(char **av, char *cmd);
void	ft_env(char *cmd, char **env);
int		ft_binaries(char *cmd, char **env);
char	*ft_check_binaries(char *cmd, char **env);
char	**ft_pull_env(char **av, int i);
int		ft_num_env(char **av);
char	*ft_2nd_word(char *cmd);
void	ft_setenv(char *cmd, char ***env);
#endif
