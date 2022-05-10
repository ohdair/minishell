/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:56:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/10 16:57:12 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <limits.h>

# define FAIL 1
# define SUCCESS 0

typedef struct s_ast
{
	char			*content;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}	t_node;

// libft
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s);

// type
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isboth(int c);

// builtin
int		ft_chdir_update(t_ast *ast);
int		ft_echo(t_ast *ast);
int		ft_exit(t_ast *ast);
int		ft_pwd(void);
int		ft_unset(t_node *env);

#endif