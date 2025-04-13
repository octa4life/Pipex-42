/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:15:37 by obellil-          #+#    #+#             */
/*   Updated: 2024/11/11 18:25:01 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	mod;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	mod = (n % 10) + '0';
	write(fd, &mod, 1);
}
/*
int	main(void)
{

	//printf("I made the impossible possible! %d\n", INT_MIN);
	fuck_the_rules(INT_MIN);
	ft_putchar('\n');
	ft_putnbr(INT_MIN);
	ft_putchar('\n');
	ft_putnbr(INT_MAX);
	ft_putchar('\n');
	ft_putnbr(11);
	ft_putchar('\n');
	ft_putnbr(-7458);
	ft_putchar('\n');
	ft_putnbr(11120);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(10);
	ft_putchar('\n');
	ft_putnbr(9);
	ft_putchar('\n');
	ft_putnbr(-9);
	ft_putchar('\n');
	ft_putnbr(-11120);
	ft_putchar('\n');
	ft_putnbr(2147483648);
	ft_putchar('\n');
	ft_putnbr(420);
	ft_putchar('\n');
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(99998);
	ft_putchar('\n');
	ft_putnbr(999900);
	ft_putchar('\n');
	ft_putnbr(INT_MAX / 2);
	ft_putchar('\n');
	ft_putnbr(INT_MIN + 2);
	ft_putchar('\n');

	return (0);
}*/
