/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:27:16 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/09 18:14:41 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_echo(t_ast *ast)
{
    t_ast   *cur;
    int     option;

    option = 0;
    if (!ast)
    {
        printf("\n");
        return (0);
    }
    cur = ast;
    while (ft_strncmp(cur->content, "-n", 3) == 0)
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
        printf("%s", cur->content);
        cur = cur->right;
        if (cur)
            printf(" ");
    }
    if (!option)
        printf("\n");
    return (0);
}