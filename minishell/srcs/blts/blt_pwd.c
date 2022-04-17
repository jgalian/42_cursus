#include "../../includes/minishell.h"

/*
** This simple function print the actual work directory. In order to do that
** it checks the environment variable PWD.
*/

void	blt_pwd(t_minishell *s)
{
	int	i;

	i = ft_find_env_var(s, "PWD=");
	if (i >= 0)
	{
		ft_putstr_fd(s->env[i] + 4, s->fd);
		write(s->fd, "\n", 1);
	}
	s->exit_status = 0;
}
