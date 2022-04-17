/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage_found.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:51:15 by jgalian-          #+#    #+#             */
/*   Updated: 2020/09/22 13:16:00 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percentage_found(const char *format, t_var *var)
{
	if (!(var->data_type = get_data_type(&format[var->str_pos])))
		return (0);
	get_flags(format, var);
	if (var->data_type == 'c')
		print_caracter(var);
	else if (var->data_type == '%')
		print_percentage(var);
	else if (var->data_type == 's')
		print_string(var, va_arg(var->args, char *));
	else if (var->data_type == 'd' || var->data_type == 'i')
		print_decimal(var, va_arg(var->args, int));
	else if (var->data_type == 'u')
		print_unsigned(var, va_arg(var->args, int));
	else if (var->data_type == 'x' || var->data_type == 'X')
		print_hexadecimal(var, (unsigned int)va_arg(var->args, int));
	else if (var->data_type == 'p')
		print_pointer(var, (long unsigned int)va_arg(var->args, void *));
	return (1);
}
