/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:16:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/01 20:00:37 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define CN 6

# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <libft.h>
# include <sys/stat.h>

# include <fcntl.h>
# include <termios.h>

char	**ft_readline(int ret, char **env);
void	ft_interpretator(char *cmd, char **av, char ***env);
void	ft_cd(char **av, char ***env, char *cmd);
void	ft_env(char *cmd, char ***env);
int		ft_binaries(char *cmd, char ***env);
char	*ft_check_binaries(char *cmd, char ***env);
int		ft_num_env(char **av);
char	*ft_2nd_word(char *cmd, char ***env);
void	ft_setenv(char *cmd, char ***env);
void	ft_echo(char *cmd);
void	ft_change_path(char ***env);
void	ft_cd_past(char ***env);
char	*ft_tabsdel(char *str);
void	ft_cd_doll(char *name, char ***env);
void	ft_tild(char **path, char ***env);
#endif
