/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:54:23 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 18:58:25 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_decimal(t_var *var, int n)
{
	int	n_len;

	n_len = ft_num_len(n);
	if (var->precision == 1 && var->precision_value == 0 && n == 0)
	{
		var->spaces = var->width;
		print_n_special(var);
		return ;
	}
	if (var->precision == 1)
	{
		var->zero = 0;
		if (var->precision_value >= n_len)
		{
			if (n < 0)
				var->zero_pad = var->precision_value - (n_len - 1);
			else
				var->zero_pad = var->precision_value - n_len;
		}
		var->spaces = (var->width - (n_len + var->zero_pad));
	}
	else
		var->spaces = var->width - n_len;
	var->minus == 1 ? print_n_l(var, n, n_len) : print_n_r(var, n, n_len);
}

void	print_n_l(t_var *var, int n, int n_len)
{
	if (n < 0)
		n = print_sign(n);
	print_zeros_pad(var);
	ft_putnbr_fd(n, 1);
	print_spaces(var);
	var->printed_chars_counter += n_len;
	var->str_pos++;
}

void	print_n_r(t_var *var, int n, int n_len)
{
	if (var->zero == 1)
	{
		if (n < 0)
			n = print_sign(n);
		print_zeros(var);
	}
	else
	{
		print_spaces(var);
		if (n < 0)
			n = print_sign(n);
	}
	print_zeros_pad(var);
	ft_putnbr_fd(n, 1);
	var->printed_chars_counter += n_len;
	var->str_pos++;
}

void	print_n_special(t_var *var)
{
	print_spaces(var);
	var->str_pos++;
}

int		print_sign(int n)
{
	ft_putchar_fd('-', 1);
	n = n * -1;
	return (n);
}
