#include "header.h"

void	ft_error(void)
{
	write(1, "Error\n", 7);
	exit(-1);
}

void	ft_clean_up(t_all *all)
{
	while (all->a)
		ft_del_top(&all->a);
	while (all->b)
		ft_del_top(&all->b);
	free(all);
}
