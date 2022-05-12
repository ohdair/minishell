/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:01:28 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/12 18:27:17 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_env
{
	struct s_env	*next;
	char			*key;
	char			*value;
}   t_env;

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

void	print_error(t_env *env)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(env->key, STDERR_FILENO);
	if (env->value)
	{
		ft_putstr_fd("=", STDERR_FILENO);
		ft_putstr_fd(env->value, STDERR_FILENO);
	}
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

static t_env	*new_envp(char *key, char *value)
{
	t_env	*result;

	if (!ft_malloc((void **)&result, sizeof(t_env)))
		return (NULL);
	result->key = key;
	result->value = value;
	return (result);
}

int	set_envp(t_node *env)
{
	t_env *g_envp;
	
	if (g_envp == NULL)
	{
		// new_envp() parsing에서 사용한 함수 가져오기
		g_envp = new_envp();
		if (g_envp == NULL)
			return (MALLOC_FAIL);
		return (SUCCESS);
	}
	// get_envp() env->key 같과 같은 노드를 들고온다.
	envp = get_envp(value, g_envp);
	if (envp)
	{
		// value 값에 대한 거 삭제
		ft_free(envp->content);
		envp->content = value;
		return (SUCCESS);
	}
	// ft_lstlast() env 마지막 노드 들고오기
	envp = ft_lstlast(g_envp);
	// envp 에 새로운 노드로서 연결 시키기
	envp->next = new_envp(value);
	if (envp->next == NULL)
		return (MALLOC_FAIL);
	return (SUCCESS);
}

int	ft_export(t_node *env)
{
	char	*name;
	int		status;

	status = SUCCESS;
	if (!env)
		// evp 출력
		print_env();
	while (env)
	{
		name = ft_strdup(env->content);
		if (check_envp_name(name) == FAIL)
		{
			print_error(env);
			status = FAIL;
		}
		if (set_envp(env) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		env = env->next;
	}
	return (status);
}