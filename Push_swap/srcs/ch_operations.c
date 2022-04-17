#include "header.h"

/*
** This function pushses a new element at the top of list A
*/

void	ft_ch_pa(t_all *all)
{
	int	n;

	if (all->b)
	{
		n = all->b->value;
		ft_del_top(&all->b);
		ft_push_top(&all->a, n);
	}
}

/*
** This function pushses a new element at the top of list B
*/

void	ft_ch_pb(t_all *all)
{
	int	n;

	if (all->a)
	{
		n = all->a->value;
		ft_del_top(&all->a);
		ft_push_top(&all->b, n);
	}
}

/*
** This function calls the reverse rotation function for both stack A and B
*/

void	ft_ch_rrr(t_all *all)
{
	ft_reverse_rotate(&all->a);
	ft_reverse_rotate(&all->b);
}

/*
** This function calls the rotation function for stack A and B
*/

void	ft_ch_rr(t_all *all)
{
	ft_rotate(&all->a);
	ft_rotate(&all->b);
}

/*
** This function swaps first and second element in lists A and B
*/

void	ft_ch_ss(t_all *all)
{
	ft_swap(all->a);
	ft_swap(all->b);
}
