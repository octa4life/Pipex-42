/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:42:26 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/24 11:23:01 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strng;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	strng = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strng)
		return (NULL);
	while (s1[i] != '\0')
	{
		strng[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		strng[j] = s2[i];
		j++;
		i++;
	}
	strng[j] = '\0';
	return (strng);
}
