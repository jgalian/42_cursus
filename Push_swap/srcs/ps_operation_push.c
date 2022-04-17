#include "header.h"

/*
** This function pushses a new element at the top of list A
*/

void	ft_pa(t_all *all)
{
	int	n;

	if (all->b)
	{
		n = all->b->value;
		ft_del_top(&all->b);
		ft_push_top(&all->a, n);
	}
	write(1, "pa\n", 3);
}

/*
** This function pushses a new element at the top of list B
*/

void	ft_pb(t_all *all)
{
	int	n;

	if (all->a)
	{
		n = all->a->value;
		ft_del_top(&all->a);
		ft_push_top(&all->b, n);
	}
	write(1, "pb\n", 3);
}
