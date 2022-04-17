/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:18:57 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/09 08:30:40 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = (long int)n;
	if (nb == -2147483648)
		ft_putstr_fd("2147483648", fd);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb > 9)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10 + 48), fd);
	}
}

void	ft_putnbr_uns_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_uns_fd(n / 10, fd);
	ft_putchar_fd((n % 10 + 48), fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
