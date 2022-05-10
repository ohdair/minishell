/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:17:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/10 16:51:21 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	change_to_number(char *str)
{
	int	flag;
	int	ret;

	flag = 1;
	ret = 0;
	if (*str == '-' && *str++)
		flag = -1;
	while (*str && ('0' <= *str && *str <= '9'))
		ret = (ret * 10) + *str++ - '0';
	return (ret * flag);
}

static int	is_number(char *str)
{
	while (*str)
	{
		if (*str < '0' && *str > '9')
			return (1);
		*str++;
	}	
	return (0);
}

static int	check_arg(t_ast *ast)
{
	unsigned char	exit_code;
	char			*str;

	str = ast->content;
	if (is_number(*str))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(ast->content, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	else
	{
		exit_code = change_to_number(str);
		if (ast->right)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
		exit(exit_code);
	}
	return (0);
}

int	ft_exit(t_ast *ast)
{
	write(1, "exit\n", 5);
	if (ast)
		return (check_arg(ast));
	exit(0);
	return (0);
}
