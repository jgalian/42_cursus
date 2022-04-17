#include "header.h"

/*
** This function returns the average of all values in the stack
*/

int	ft_list_values_average(t_stack *head)
{
	int	ret;

	ret = ft_list_values_sum(head) / ft_list_lenght(head);
	return (ret);
}

/*
** This function returns the addition of all values in the stack
*/

int	ft_list_values_sum(t_stack *head)
{
	t_stack	*tmp;
	int		ret;

	if (!head)
		return (0);
	tmp = head;
	ret = tmp->value;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		ret += tmp->value;
	}
	return (ret);
}
