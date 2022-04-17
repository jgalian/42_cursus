/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:03:47 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 18:05:57 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_var var;

	set_initial_values(&var);
	va_start(var.args, format);
	while (format[var.str_pos] != '\0')
	{
		if (format[var.str_pos] == '%')
		{
			if (!(percentage_found(format, &var)))
				return (0);
			reset_temp_values(&var);
		}
		else
		{
			ft_putchar_fd(format[var.str_pos], 1);
			var.str_pos++;
			var.printed_chars_counter++;
		}
	}
	va_end(var.args);
	return (var.printed_chars_counter);
}
