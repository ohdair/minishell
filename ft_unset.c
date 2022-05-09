/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:17:10 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/09 19:18:28 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_error(t_node *env)
{
	ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
	ft_putstr_fd("'", STDERR_FILENO);
	ft_putstr_fd(env->content, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

int is_env(t_node *env)
{
    if (!ft_isalpha(*(env->content)) && *(env->content) != '_')
    {
        printf("TRUE");
        return (FAIL);
    }
    while (*(env->content))
    {
        if (!ft_isboth(*(env->content)) && *(env->content) != '_')
            return (FAIL);
        env->content++;
    }
    return (SUCCESS);
}

int ft_unset(t_node *env)
{
    int status;
    t_node *node;

    status = SUCCESS;
    while (env)
    {
        if (is_env(env))
        {
            status = FAIL;
            print_error(env);
        }
        else
        {
            // env 찾는 것과 환경변수 삭제하는 함수 필요
            node = find_env(env);
            remove(node);
        }
        env = env->next;
    }
    return (status);
}