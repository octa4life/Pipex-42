/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:05:06 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/29 14:14:05 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	u;

	u = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == u)
			return ((char *)s);
		s++;
	}
	if (u == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	const char	*str = "ui tond  ";
	char		c;
	char		*res;

	c = 't';
	res = ft_strchr(str, c);
	if (res != NULL)
	{
		printf(" le caractere '%c'est dans la chaine '%s\n'", c, res);
	}
	else
	{
		printf("le caractere '%c' n'est pas dans la chaine de caractere \n", c);
	}
	return (0);
}
*/