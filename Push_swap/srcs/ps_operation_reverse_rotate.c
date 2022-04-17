#include "header.h"

/*
** This function calls the reverse rotation function for stack A
*/

void	ft_rra(t_all *all)
{
	ft_reverse_rotate(&all->a);
	write(1, "rra\n", 4);
}

/*
** This function calls the reverse rotation function for stack B
*/

void	ft_rrb(t_all *all)
{
	ft_reverse_rotate(&all->b);
	write(1, "rrb\n", 4);
}

/*
** This function calls the reverse rotation function for both stack A and B
*/

void	ft_rrr(t_all *all)
{
	ft_reverse_rotate(&all->a);
	ft_reverse_rotate(&all->b);
	write(1, "rrr\n", 4);
}
