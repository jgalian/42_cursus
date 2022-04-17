/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_temp_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:21:09 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 19:21:53 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_temp_values(t_var *var)
{
	var->data_type = ' ';
	var->minus = 0;
	var->zero = 0;
	var->point = 0;
	var->width = 0;
	var->precision = 0;
	var->precision_value = 0;
	var->spaces = 0;
	var->zero_pad = 0;
}
