/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:09:54 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 18:11:05 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(const char *format, t_var *var)
{
	var->str_pos++;
	while (ft_isalpha(format[var->str_pos]) != 1 && format[var->str_pos] != '%')
	{
		if (format[var->str_pos] == '-')
			var->minus = 1;
		else if (format[var->str_pos] == '0')
			var->zero = 1;
		else if (ft_isdigit(format[var->str_pos]) == 1)
			get_width(format, var);
		else if (format[var->str_pos] == '*')
			get_width(format, var);
		else if (format[var->str_pos] == '.')
		{
			var->precision = 1;
			get_precision(format, var);
		}
		var->str_pos++;
	}
}
