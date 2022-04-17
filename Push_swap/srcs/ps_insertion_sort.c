#include "header.h"

/*
** This function searchs for the smallest value in the stack A and pushes it to
** the stack B. In order to do that more efficiently, it should check if the
** smallest value is in the upper half of the list or in the lower half. And
** depending on that, is going to use rotate() o reverse_rotate() functions to
** move it to the first place, where it can be pushed to list B.
*/

void	ft_insertion_sort_a(t_all *all)
{
	int	n_elements;
	int	position;
	int	middle;
	int	rotations;

	position = ft_list_smallest_value_position(all->a);
	n_elements = ft_list_lenght(all->a);
	middle = n_elements / 2;
	if (position <= middle)
		rotations = position;
	else
		rotations = n_elements - position;
	if (position <= middle)
		while (rotations--)
			ft_ra(all);
	else
		while (rotations--)
			ft_rra(all);
	ft_pb(all);
}

/*
** This function searchs for the smallest value in the stack B and pushes it to
** the stack A. In order to do that more efficiently, it should check if the
** smallest value is in the upper half of the list or in the lower half. And
** depending on that, is going to use rotate() o reverse_rotate() functions to
** move it to the first place, where it can be pushed to list A.
*/

void	ft_insertion_sort_b(t_all *all)
{
	int	n_elements;
	int	position;
	int	middle;
	int	rotations;

	position = ft_list_greatest_value_position(all->b);
	n_elements = ft_list_lenght(all->b);
	middle = n_elements / 2;
	if (position <= middle)
		rotations = position;
	else
		rotations = n_elements - position;
	if (position <= middle)
		while (rotations--)
			ft_rb(all);
	else
		while (rotations--)
			ft_rrb(all);
	ft_pa(all);
}
