/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:06:39 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 18:11:41 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_data_type(const char *format)
{
	int i;

	i = 1;
	while (!ft_isalpha(format[i]) && format[i] != '%' && format[i] != '\0')
		i++;
	return (format[i]);
}
