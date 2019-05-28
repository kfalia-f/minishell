/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:33:17 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/05/28 17:55:33 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_first_word(char *str)
{
	char	*fw;
	int		i;

	i = 0;
	fw = NULL;
	while (str[i] && str[i] != ' ')
		i++;
	fw = (char *)malloc(sizeof(char) * (i + 1));
	fw = ft_strncpy(fw, str, i);
	fw[i] = '\0';
	return (fw);
}
