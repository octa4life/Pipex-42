/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:55:54 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/28 11:18:16 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (src[n] != '\0')
	{
		n++;
	}
	if (size == 0)
	{
		return (n);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (n);
}
/*
int	main(void)
{
	char	src[] = "Octa, on top";

	char dest[50]; // je creer un tabl pour la dest
	printf ("Source: %s\n", src);
	printf ("Dest: %s\n", dest);
	printf ("%ld",ft_strlcpy(dest, src, strlen(src)+1));
	return (0);
}
*/