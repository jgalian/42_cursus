/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:58:45 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 19:01:02 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexadecimal(t_var *var, unsigned int n)
{
	char	*str;
	int		len;

	int_to_hex(var, n, &str);
	len = ft_strlen(str);
	if (var->precision == 1 && var->precision_value == 0 && n == 0)
	{
		var->spaces = var->width;
		print_hex_special(var);
		return ;
	}
	if (var->precision == 1)
	{
		var->zero = 0;
		if (var->precision_value >= len)
			var->zero_pad = var->precision_value - len;
		var->spaces = (var->width - (len + var->zero_pad));
	}
	else
		var->spaces = var->width - len;
	var->minus == 1 ? print_hex_l(var, str, len) : print_hex_r(var, str, len);
	free(str);
	var->str_pos++;
}

void	print_hex_l(t_var *var, char *str, int len)
{
	print_zeros_pad(var);
	ft_putstr_fd(str, 1);
	var->printed_chars_counter += len;
	print_spaces(var);
}

void	print_hex_r(t_var *var, char *str, int len)
{
	if (var->zero == 1)
		print_zeros(var);
	else
		print_spaces(var);
	print_zeros_pad(var);
	ft_putstr_fd(str, 1);
	var->printed_chars_counter += len;
}

void	print_hex_special(t_var *var)
{
	print_spaces(var);
	var->str_pos++;
}
