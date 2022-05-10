/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:27:13 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/10 16:50:12 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ft_strjoin 필요 */
/* set_envp 필요 */
static int	pwd_update(void)
{
	char	name[PATH_MAX];
	char	*path;

	if (getcwd(name, PATH_MAX) == NULL)
		return (FAIL);
	path = ft_strjoin("PWD=", name);
	if (path == NULL)
		return (FAIL);
	if (set_envp(path) == FAIL)
	{
		free(path);
		return (FAIL);
	}
	return (SUCCESS);
}

/* 전역변수 env에서 home 읽어오기 */
/* get_env_home 함수 필요 */
int	ft_chdir_home(void)
{
	char	*path;
	int		stat;

	stat = 0;
	path = get_env_home("HOME");
	if (!path)
	{
		ft_put_error("cd", "HOME not set.\n");
		stat = FAIL;
	}
	if (chdir(path) == -1)
		stat = FAIL;
	free(path);
	return (stat);
}

/* ft_put_error 필수 */
void	ft_put_cderror(char *dir_name)
{
	if (!dir_name)
		return ;
	if (!ft_strncmp(dir_name, ".", 2))
	{
		ft_put_error("cd", "error retrieving current directory\n");
		ft_put_error("getcwd", "cannot access parent directories\n");
		ft_put_error(dir_name, "No such file or directory\n");
	}
	else if (errno == ENOENT)
		ft_put_error(dir_name, "No such file or directory\n");
	else if (errno == EACCES)
		ft_put_error(dir_name, "Permission denied");
	else if (errno == ENOTDIR)
		ft_put_error(dir_name, "Not a directory");
	else
		ft_put_error(NULL, "Error!");
}

int	ft_chdir_update(t_ast *ast)
{
	char	*path;
	int		stat;

	stat = 0;
	path = ft_strdup(ast->content);
	if (!path)
		return (FAIL);
	if (chdir(path) == -1)
	{
		ft_put_cderror(path);
		stat = FAIL;
	}
	free(path);
	return (stat);
}

/* ENOENT(2) :  No such file or directory */
/* cd 인자가 없거나 "~"만 있는 경우 HOME으로 이동 */
/* 그 외의 경우 chdir_update에서 확인 */
int	ft_cd(t_ast *ast)
{
	int	stat;

	stat = 0;
	if (!ast || !ft_strcmp(ast, "~"))
		stat = ft_chdir_home();
	else
		stat = ft_chdir_update(ast);
	if (stat == FAIL)
		return (FAIL);
	if (pwd_update() == FAIL)
		return (FAIL);
	return (stat);
}
