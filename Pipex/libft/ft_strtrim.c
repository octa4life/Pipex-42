/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:11:49 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/30 17:17:11 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	debutindex(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len && ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	return (i);
}

static int	finindex(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len && ft_strchr(set, s1[len - i - 1]) != NULL)
	{
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		debut;
	int		fin;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	debut = debutindex(s1, set);
	fin = finindex(s1, set);
	if (fin <= debut)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (fin - debut + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + debut, fin - debut + 1);
	return (str);
}
