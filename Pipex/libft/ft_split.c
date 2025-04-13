/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:06:17 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/29 15:01:37 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countw(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	*free_all(char **result, int i)
{
	while (i-- > 0)
		free(result[i]);
	free(result);
	return (NULL);
}

static char	*next_word(const char *s, char c, int *start)
{
	int		end;
	char	*word;

	end = *start;
	while (s[end] && s[end] != c)
		end++;
	word = ft_substr(s, *start, end - *start);
	*start = end;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		wordcount;
	char	**result;

	if (!s)
		return (NULL);
	wordcount = countw(s, c);
	result = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < wordcount)
	{
		while (s[start] && s[start] == c)
			start++;
		result[i] = next_word(s, c, &start);
		if (!result[i++])
			return (free_all(result, i - 1));
	}
	result[i] = NULL;
	return (result);
}
