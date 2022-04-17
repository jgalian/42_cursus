#include "header.h"

/*
** This function points out if in the stack passed there is a node with equal
** or smaller value than the number passed as argument.
*/

int	ft_found_equal_or_smaller(t_stack *head, int num)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->value <= num)
			return (TRUE);
		tmp = tmp->prev;
	}
	return (FALSE);
}

/*
** This function points out if in the stack passed there is a node with equal
** or bigger value than the number passed as argument.
*/

int	ft_found_equal_or_bigger(t_stack *head, int num)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->value >= num)
			return (TRUE);
		tmp = tmp->prev;
	}
	return (FALSE);
}
