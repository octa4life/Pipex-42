/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:50:40 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/23 10:19:13 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	i = 0;
	if (src == NULL && dest == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		d [i] = s[i];
		i ++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "Octa, on top";
	char dest[50]; // je creer un tabl pour la dest
	
	ft_memcpy(dest, src, strlen(src)+1);// je copie la src dans la dest
	
	printf ("Source: %s\n", src);
	printf ("Dest: %s\n", dest);
	return (0);
}
*/