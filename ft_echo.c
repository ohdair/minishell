/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:27:16 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/20 15:01:21 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_astnode *ast)
{
	t_astnode	*cur;
	int			option;

	option = 0;
	cur = ast;
	while (cur && ft_strncmp(cur->data, "-n", 3) == 0)
	{
		option = 1;
		cur = cur->right;
	}
	if (!cur)
	{
		printf("\n");
		return (0);
	}
	while (cur)
	{
		printf("%s", cur->data);
		cur = cur->right;
		if (cur)
			printf(" ");
	}
	if (!option)
		printf("\n");
	return (0);
}
