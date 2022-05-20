/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:01:28 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/20 17:37:22 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

static void	print_export(t_env	*env)
{
	while (env)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		if (env->key)
		{
			ft_putstr_fd(env->key, STDOUT_FILENO);
			if (env->value)
			{
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(env->value, STDOUT_FILENO);
				ft_putstr_fd("\"", STDOUT_FILENO);
			}
		}
		env = env->next;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

int	check_envp_name(char *check)
{
	char	*ptr;
	int		len;

	ptr = ft_strchr(check, '=');
	if (ptr)
		len = ptr - check;
	else
		len = ft_strlen(check);
	while (--len >= 0)
	{
		if ((len == 0 && !(ft_isalpha(check[len]) || check[len] == '_')) \
			|| !(ft_isalnum(check[len]) || check[len] == '_'))
			return (FAIL);
	}
	return (SUCCESS);
}

void	print_error(t_env *ast)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(ast->key, STDERR_FILENO);
	if (ast->value)
	{
		ft_putstr_fd("=", STDERR_FILENO);
		ft_putstr_fd(ast->value, STDERR_FILENO);
	}
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

int	set_envp(t_node *ast)
{
	t_env	*new;
	t_env	*old;

	new = env_new(ast->content);
	if (new == NULL)
		return (MALLOC_FAIL);
	old = env_search(new->key);
	if (old)
	{
		if (old->value)
			free(old->value);
		old->value = ft_strdup(new->value);
		free(new);
		return (SUCCESS);
	}
	env_add_back(&(g_info.env), new);
	return (SUCCESS);
}

int	ft_export(t_astnode *ast)
{
	int		status;

	status = SUCCESS;
	if (!ast)
		print_export(g_info.env);
	while (ast)
	{
		if (check_envp_name(ast->data) == FAIL)
		{
			print_error(ast);
			status = FAIL;
		}
		if (set_envp(ast) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		ast = ast->right;
	}
	return (status);
}
