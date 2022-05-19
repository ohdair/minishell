#include "minishell.h"

extern t_info   g_info;

t_env   *env_search(char *search_key)
{
	t_env *node;

	node = g_info.env;
	if (!ft_strcmp("?", search_key))
	{
		while (node)
		{
			if (!ft_strcmp("?", node->key))
			{
				free(node->value);
				node->value = ft_itoa(g_info.ret);
				return (node);
			}
			node = node->next;
		}
	}
	while (node)
	{
		if (!ft_strcmp(node->key, search_key))
			return (node);
		node = node->next;
	}
	return (NULL);
}