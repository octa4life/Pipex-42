/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:30:40 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/23 10:17:54 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char buffer[10] = "";
	ft_bzero(buffer, 10);
	int all_zero = 1;

	if (all_zero) 
	{

		printf("ok");
    
	} 
	else 
    {
	    printf("erreur");
    }

	return 0;
}
*/