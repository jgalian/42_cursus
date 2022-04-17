/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:01:15 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 19:03:25 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces(t_var *var)
{
	while (var->spaces > 0)
	{
		ft_putchar_fd(' ', 1);
		var->printed_chars_counter++;
		var->spaces--;
	}
}

void	print_zeros(t_var *var)
{
	while (var->spaces > 0)
	{
		ft_putchar_fd('0', 1);
		var->printed_chars_counter++;
		var->spaces--;
	}
}

void	print_zeros_pad(t_var *var)
{
	while (var->zero_pad > 0)
	{
		ft_putchar_fd('0', 1);
		var->printed_chars_counter++;
		var->zero_pad--;
	}
}
