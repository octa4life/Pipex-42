/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:40:31 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/23 10:20:00 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*str
	
	char	c
	
	c	= 't';
	*str	= "t ";
	char *res = ft_strrchr(str, c);

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