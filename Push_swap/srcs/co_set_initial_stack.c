#include "header.h"

/*
** This function receives the stack A in order to push to it the numbers gotten
** as arguments for the program. It uses two arrays of ints to check if any of
** those mumbers are duplicated. One array is for the positive and the other for
** the negative nubers. Function starts setting all the positions in the array
** with 0. Then calls function process_arguments() in order to convert the
** strigs passed as arguments to ints. Inside that function also is checked if
** the numbers are too big or too small. Finally, this function push to the top
** of the stack A the number after checks that it is not duplicated.
*/

void	ft_set_initial_stack(t_stack **head, int argc, char **argv)
{
	int		i;
	int		num;
	int		positives[SHRT_MAX];
	int		negatives[SHRT_MAX];
	char	**args;

	ft_initialize_array(positives, SHRT_MAX);
	ft_initialize_array(negatives, SHRT_MAX);
	while (--argc > 0)
	{
		args = ft_split(argv[argc], ' ');
		i = ft_matrix_len(args);
		while (--i >= 0)
		{
			num = process_arguments(args, i);
			if (num >= 0 && !positives[num])
				positives[num] = 1;
			else if (num < 0 && !negatives[num * -1])
				negatives[num * -1] = 1;
			else
				ft_error();
			ft_push_top(head, num);
		}
		ft_free_matrix(args);
	}
}

void	ft_initialize_array(int *array, int num)
{
	int	i;

	i = -1;
	while (++i <= num)
		array[i] = 0;
}

/*
** This function gets the reference of one of the arguments in the program and
** get it converted from string to int using atoi(). If the conversion goes
** well and the number is not bigger or smaller than it is required, would be
** returned to the caller function. When atoi() returns 0 the function should
** check if it is because the argument was number 0 or because the argument
** was no numeric and so it could not be converted.
*/

int	process_arguments(char **argv, int i)
{
	int	atoi_ret_val;
	int	j;

	atoi_ret_val = ft_atoi(argv[i]);
	if (atoi_ret_val == 0)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (argv[i][j] != '0')
				ft_error();
		}
	}
	else if (atoi_ret_val == -1)
	{
		if (argv[i][0] != '-' || argv[i][1] != '1')
			ft_error();
	}
	if (atoi_ret_val < INT_MIN || atoi_ret_val > INT_MAX)
		ft_error();
	return (atoi_ret_val);
}
