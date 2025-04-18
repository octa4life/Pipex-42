/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:20:46 by obellil-          #+#    #+#             */
/*   Updated: 2025/04/18 14:54:37 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		y;
	size_t		little_len;
	char		*p_big;

	i = 0;
	p_big = (char *)big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (p_big);
	while (p_big[i] && i < len)
	{
		y = 0;
		while (p_big[i + y] && little[y]
			&& p_big[i + y] == little[y] && (i + y) < len)
		{
			y++;
		}
		if (y == little_len)
			return (p_big + i);
		i++;
	}
	return (NULL);
}
