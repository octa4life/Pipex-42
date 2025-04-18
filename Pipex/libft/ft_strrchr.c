/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:48:39 by obellil-          #+#    #+#             */
/*   Updated: 2025/04/18 14:54:43 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	char	*last_occurence;
	int		i;

	find = (char)c;
	last_occurence = (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			last_occurence = (char *)s;
		s++;
	}
	if (find == '\0')
		return ((char *)s);
	return (last_occurence);
}
