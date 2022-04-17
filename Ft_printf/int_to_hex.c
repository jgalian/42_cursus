/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:50:39 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 18:50:59 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_to_hex(t_var *var, unsigned int num, char **str)
{
	if (var->data_type == 'x' || var->data_type == 'p')
		itox_lower(num, str);
	if (var->data_type == 'X')
		itox_upper(num, str);
}

void	itox_lower(unsigned int num, char **str)
{
	unsigned int	n;
	int				mod;
	char			*temp;
	int				i;

	n = num;
	i = 1;
	while ((n = n / 16) != 0)
		i++;
	temp = (char*)malloc(i + 1);
	temp[i] = '\0';
	i = 0;
	if (num == 0)
		temp[i] = 0 + 48;
	while (num != 0)
	{
		mod = num % 16;
		temp[i++] = mod < 10 ? mod + 48 : mod + 87;
		num = num / 16;
	}
	*str = temp;
	reverse_str(str);
}

void	itox_upper(unsigned int num, char **str)
{
	unsigned int	n;
	int				mod;
	char			*temp;
	int				i;

	n = num;
	i = 1;
	while ((n = n / 16) != 0)
		i++;
	temp = (char*)malloc(i + 1);
	temp[i] = '\0';
	i = 0;
	if (num == 0)
		temp[i] = 0 + 48;
	while (num != 0)
	{
		mod = num % 16;
		temp[i++] = mod < 10 ? mod + 48 : mod + 55;
		num = num / 16;
	}
	*str = temp;
	reverse_str(str);
}
