static void	ft_print(char **array, int starting_from)
{
	int	i;

	i = starting_from;
	while (array[i])
	{
		if (i != starting_from)
			printf(" ");
		printf("%s", array[i++]);
	}
}

void	ft_echo(t_state *state, t_cmd *current_cmd)
{
	int	i;

	i = 1;
	if (current_cmd->num_of_args >= 2)
	{
		if (!ft_strncmp(current_cmd->args[i], "-n", 3))
		{
			while (!ft_strncmp(current_cmd->args[i], "-n", 3))
				i++;
			if (current_cmd->num_of_args < 3)
				return ;
			ft_print(current_cmd->args, i);
			return ;
		}
		ft_print(current_cmd->args, 1);
	}
	printf("\n");
	state->status = 0;
}