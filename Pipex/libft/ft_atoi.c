/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:38:37 by obellil-          #+#    #+#             */
/*   Updated: 2024/10/29 14:01:39 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	vartempo;

	i = 0;
	sign = 1;
	vartempo = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign -= (nptr[i] == '-') * 2;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		vartempo = vartempo * 10 + (nptr[i++] - '0');
	return (vartempo * sign);
}
/*
int	main(void)
{
	char	*c;
	int		n;

	c = "+1234ab567";
	//printf("%d",);
	n = ft_atoi(c);
	printf("%d",n);
}
*/