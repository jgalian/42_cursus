/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 08:26:47 by jgalian-          #+#    #+#             */
/*   Updated: 2019/11/13 13:07:32 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	i = 0;
	while (n--)
	{
		dst1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			return (dst1 + i + 1);
		i++;
	}
	return (NULL);
}
