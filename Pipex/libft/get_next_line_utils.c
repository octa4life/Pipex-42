/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octavie <octavie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:10:09 by obellil-          #+#    #+#             */
/*   Updated: 2025/04/04 12:57:24 by octavie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnlchr(char *stocker)
{
	int	i;

	i = 0;
	if (stocker == NULL)
		return (0);
	while (stocker[i] != '\0')
	{
		if (stocker[i] == '\n')
			return (1);
	}
	i++;
	return (1);
}

char	*ft_gnljoin(char *nl, char *st)
{
	char		*result;
	size_t		i;
	size_t		j;

	if (!nl)
	{
		nl = malloc(sizeof(char));
		if (!nl)
			return (NULL);
		nl[0] = '\0';
	}
	result = malloc((ft_strleen(nl) + ft_strleen(st) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (nl[++i] != '\0')
		result[i] = nl[i];
	free(nl);
	j = 0;
	while (st[j] && st[j] != '\n')
		result[i++] = st[j++];
	if (st[j] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*ft_gnlclean(char *stocker)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stocker[i] && stocker[i] != '\n')
		i++;
	if (stocker[i] == '\n')
		i++;
	while (stocker[i])
	{
		stocker[j] = stocker[i];
		i++;
		j++;
	}
	stocker[j] = '\0';
	return (stocker);
}

size_t	ft_strleen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
