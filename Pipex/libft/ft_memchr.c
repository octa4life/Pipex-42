/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:34:13 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/23 10:19:02 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	char	test;
	size_t	i;

	i = 0;
	test = (char)c;
	string = (char *)s;
	while (i < n)
	{
		if (string[i] == test)
			return ((void *)(string + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char str[] = "Hello, World!";
	char s = 'W';
	char *result;

	result = (char *)ft_memchr(str, s, strlen(str));

	if (result != NULL)
		printf("Le caractère '%c' est dans la chaîne: %s\n", s, result);
	else
		printf("Le caractère '%c' n'est pas été trouvé dans la chaîne.\n", s);

	return (0);
}
*/