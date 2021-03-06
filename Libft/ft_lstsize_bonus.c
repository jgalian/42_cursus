/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:40:25 by jgalian-          #+#    #+#             */
/*   Updated: 2019/12/09 11:16:01 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	if (!aux)
		return (0);
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}
