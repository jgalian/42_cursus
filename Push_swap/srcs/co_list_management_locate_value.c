#include "header.h"

/*
** This function locates in the stack passed as argument the smallest value
** and returns it to the caller function.
*/

int	ft_list_smallest_value(t_stack *head)
{
	t_stack	*tmp;
	int		ret;

	tmp = head;
	ret = tmp->value;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		if (tmp->value < ret)
			ret = tmp->value;
	}
	if (tmp->value < ret)
		ret = tmp->value;
	return (ret);
}

/*
** This function locates in the stack passed as argument the smallest value
** and returns its position in the list to the caller function.
*/

int	ft_list_smallest_value_position(t_stack *head)
{
	t_stack	*tmp;
	int		smallest;
	int		position;
	int		i;

	tmp = head;
	smallest = tmp->value;
	position = 0;
	i = 0;
	while (tmp->prev != NULL)
	{
		i++;
		tmp = tmp->prev;
		if (tmp->value < smallest)
		{
			smallest = tmp->value;
			position = i;
		}
	}
	if (tmp->value < smallest)
		position = i;
	return (position);
}

/*
** This function locates in the stack passed as argument the smallest value
** and returns it to the caller function.
*/

int	ft_list_greatest_value(t_stack *head)
{
	t_stack	*tmp;
	int		ret;

	tmp = head;
	ret = tmp->value;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		if (tmp->value > ret)
			ret = tmp->value;
	}
	if (tmp->value > ret)
		ret = tmp->value;
	return (ret);
}

/*
** This function locates in the stack passed as argument the greatest value
** and returns its position in the list to the caller function.
*/

int	ft_list_greatest_value_position(t_stack *head)
{
	t_stack	*tmp;
	int		greatest;
	int		position;
	int		i;

	tmp = head;
	greatest = tmp->value;
	position = 0;
	i = 0;
	while (tmp->prev != NULL)
	{
		i++;
		tmp = tmp->prev;
		if (tmp->value > greatest)
		{
			greatest = tmp->value;
			position = i;
		}
	}
	if (tmp->value > greatest)
		position = i;
	return (position);
}
