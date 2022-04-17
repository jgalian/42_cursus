/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:12:22 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 18:15:07 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision_value(const char *format, t_var *var)
{
	int		i;
	int		j;
	char	*str;

	j = var->str_pos;
	i = 0;
	while (ft_isdigit((int)format[var->str_pos]) == 1)
	{
		i++;
		var->str_pos++;
	}
	str = ft_substr(&format[j], 0, i);
	var->precision_value = ft_atoi(str);
	free(str);
	str = NULL;
}

void	get_precision(const char *format, t_var *var)
{
	var->str_pos++;
	if (format[var->str_pos] == '-')
	{
		var->precision = 0;
		while (ft_isalpha(format[var->str_pos]) != 1)
			var->str_pos++;
	}
	else if (ft_isalpha(format[var->str_pos]) == 1)
		var->precision_value = 0;
	else if (ft_isdigit(format[var->str_pos]) == 1)
		get_precision_value(format, var);
	else if (format[var->str_pos] == '*')
	{
		var->precision_value = va_arg(var->args, int);
		var->str_pos++;
		if (var->precision_value < 0)
			var->precision = 0;
	}
	var->str_pos--;
}
