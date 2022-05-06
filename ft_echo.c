/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:27:16 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/06 19:57:25 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SUCCESS 0
#define FAIL 1
typedef struct s_ast
{
	char *content;
	void *next;
}	t_ast;

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
        cur = cur->next;
    }
    if (!cur)
    {
        printf("\n");
        return (0);
    }
    while (cur)
    {
        printf("%s", cur->content);
        cur = cur->next;
        if (cur)
            printf(" ");
    }
    if (!option)
        printf("\n");
    return (0);
}