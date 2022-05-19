/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:17:21 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/19 17:44:10 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	name[PATH_MAX];

	if (getcwd(name, PATH_MAX) == NULL)
	{
		ft_error_print("pwd", NULL, strerror(errno));
		return (FAIL);
	}
	else
	{
		ft_putstr_fd(name, STDOUT_FILENO);
		write(1, "\n", 1);
	}
	return (SUCCESS);
}
