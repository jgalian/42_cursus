/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:03:38 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 19:06:33 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percentage(t_var *var)
{
	if (var->width > 1)
	{
		var->spaces = var->width - 1;
		if (var->minus == 1)
		{
			ft_putchar_fd('%', 1);
			print_spaces(var);
		}
		else
		{
			if (var->zero == 1)
				print_zeros(var);
			else
				print_spaces(var);
			ft_putchar_fd('%', 1);
		}
	}
	else
		ft_putchar_fd('%', 1);
	var->printed_chars_counter++;
	var->str_pos++;
}
