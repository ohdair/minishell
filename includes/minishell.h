/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:56:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/19 16:47:42 by jaewpark         ###   ########.fr       */
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

# define MALLOC_FAIL -2

typedef struct			s_env
{
	struct s_env		*next;
	char				*key;
	char				*value;
}						t_env;

typedef struct			s_astnode
{
	int type;
	char *data;
	struct s_astnode *left;
	struct s_astnode *right;
}						t_astnode;

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}	t_node;

typedef struct			s_info
{
	int					ret;
	// t_history			*hist_lst;
	// t_history			*hist_ptr;
	t_env				*env;
	struct termios		term_orig;
	struct termios		term_mod;
	// t_lexer				*lexerbuf;
	t_astnode			*astnode;
}						t_info;

// libft
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);

// type
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isboth(int c);

// builtin
int		ft_chdir_update(t_astnode *ast);
int		ft_echo(t_astnode *ast);
int		ft_exit(t_astnode *ast);
int		ft_pwd(void);
int		ft_unset(t_node *env);

// temp
t_env   *env_search(char *search_key);

#endif