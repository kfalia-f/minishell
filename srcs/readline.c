/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:58:56 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/07/28 20:20:10 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**ft_readline(int ret)
{
//	struct termios	savetty;
//	struct termios	tty;
	char    		buff[9999];
//	char			buff;
//	char			tmp[100];
	char			**str;

/*	tcgetattr (0, &tty);
	savetty = tty;
	tty.c_lflag &= ~(ICANON|ECHO|ISIG);
	tty.c_cc[VMIN] = 1;
	tcsetattr (0, TCSAFLUSH, &tty);
	while (1)
	{
		ret += read(0, &buff, 1);
		if (buff >= 97 && buff <= 122) 
			ft_putchar(buff);
		tmp[ret - 1] = buff;
		if (buff == '\n' || buff == 'Q')
			break ;
	}
	ft_putchar('\n');
	tmp[ret - 1] = '\0';
*/
	ret = read(1, buff, 9999);
	buff[ret - 1] = '\0';
	str = ft_strsplit(buff, ';');

//	tcsetattr (0, TCSAFLUSH, &savetty);
	return (str);
}
