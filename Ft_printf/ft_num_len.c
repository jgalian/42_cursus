/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:55:42 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 18:00:00 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(long int num)
{
	int i;

	i = 1;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while ((num = num / 10) > 0)
		i++;
	return (i);
}
