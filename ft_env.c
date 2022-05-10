/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:59:43 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/10 17:30:39 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// g_envp 필요
t_node *g_envp;

int	ft_env(void)
{
	t_node	*env;

	env = g_envp;
	while (env)
	{
		if (strchr(env->content, '=') != 0)
			ft_putendl_fd(env->content, STDOUT_FILENO);
		env = env->next;
	}
	return (SUCCESS);
}
