/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:15:36 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 18:17:27 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width_value(const char *format, t_var *var)
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
	var->width = ft_atoi(str);
	var->str_pos--;
	free(str);
	str = NULL;
}

void	get_width(const char *format, t_var *var)
{
	if (ft_isdigit(format[var->str_pos]) == 1)
		get_width_value(format, var);
	else if (format[var->str_pos] == '*')
	{
		var->width = va_arg(var->args, int);
		if (var->width < 0)
		{
			var->minus = 1;
			var->width *= -1;
		}
	}
}
