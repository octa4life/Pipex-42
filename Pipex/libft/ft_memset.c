/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:49:53 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/23 13:32:31 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*i;
	size_t			b;

	b = 0;
	i = (unsigned char *)s;
	while (b < n)
	{
		i[b] = (unsigned char)c;
		b++;
	}
	return (s);
}
/*
int	main(void)
{
	char str[20] = "ouistiti";
	ft_memset(str, 'A', 4);
	printf("%s\n",str);
	return 0;
}
*/