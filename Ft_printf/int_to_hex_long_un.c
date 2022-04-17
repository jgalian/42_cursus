/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex_long_un.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:17:57 by jgalian-          #+#    #+#             */
/*   Updated: 2020/02/07 18:45:58 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_to_hex_long_un(long unsigned int num, char **str)
{
	long unsigned int	n;
	int					mod;
	char				*temp;
	int					i;

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
