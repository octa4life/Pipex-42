/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:23:45 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/31 16:54:03 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char*	get_next_line(int fd)
{
	static char	stocker [BUFFER_SIZE + 1] = {};
	char*newline;
	int	to_read;

	newline = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);
	if (ft_gnlchr(stocker))
			(ft_gnlclean(stocker), newline = ft_gnljoin(newline, stocker));
	to_read = 1;
	while (to_read > 0 && ft_gnlchr(stocker) == 0)
	{
		to_read = read(fd, stocker, BUFFER_SIZE);
		if (to_read < 0)
		return (free(newline), NULL);
	if (to_read == 0)
	{
	if (newline != NULL && newline[0] != '\0')
	return (newline);
	return (free(newline), NULL);
	}
	stocker[to_read] = '\0';
	newline = ft_gnljoin(newline, stocker);
	}
	return (newline);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*newline;

// 	fd = open("giant_line.txt", O_RDONLY);
// 	newline = get_next_line(fd);
// 	while (newline)
// 	{
// 		printf("%s", newline);
// 		free(newline);
// 		newline = get_next_line(fd);
// 	}
// 	free(newline);
// 	close(fd);
// 	return (0);
// }
