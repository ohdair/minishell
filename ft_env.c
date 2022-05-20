/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:59:43 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/20 15:02:15 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// g_envp 필요
extern t_info	g_info;

int	ft_env(void)
{
	t_env	*env;

	env = g_info.env;
	while (env)
	{
		if (env->value)
		{
			ft_putendl_fd(env->key, STDOUT_FILENO);
			ft_putendl_fd("=", STDOUT_FILENO);
			ft_putendl_fd(env->value, STDOUT_FILENO);
		}
		env = env->next;
	}
	return (SUCCESS);
}
