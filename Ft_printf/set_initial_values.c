/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:22:14 by jgalian-          #+#    #+#             */
/*   Updated: 2020/03/07 13:36:40 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_initial_values(t_var *var)
{
	var->printed_chars_counter = 0;
	var->str_pos = 0;
	var->data_type = ' ';
	var->minus = 0;
	var->zero = 0;
	//var->point = 0;
	var->width = 0;
	var->precision = 0;
	var->precision_value = 0;
	var->spaces = 0;
	var->zero_pad = 0;
}
