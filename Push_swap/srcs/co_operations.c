#include "header.h"

/*
** This function sends the last element to the top of the list so the first
** element becomes the second one
*/

void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head)->prev)
		return ;
	tmp = *head;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	tmp->prev = *head;
	*head = tmp;
	while (tmp->prev != *head)
		tmp = tmp->prev;
	tmp->prev = NULL;
}

/*
** This function sends the first element to the end of the list so the second
** element becomes the top one
*/

void	ft_rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head)->prev)
		return ;
	tmp = *head;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	tmp->prev = *head;
	tmp = tmp->prev;
	*head = tmp->prev;
	tmp->prev = NULL;
}

/*
** This function swaps first and second element in the list passed as argument
*/

void	ft_swap(t_stack *head)
{
	int	tmp;

	tmp = head->value;
	head->value = head->prev->value;
	head->prev->value = tmp;
}
