#define SUCCESS 0
#define FAIL 1

typedef struct s_ast
{
	char *content;
	void *next;
}	t_ast;

static int	change_to_number(char *str)
{
    int flag;
    int ret;

    flag = 1;
    ret = 0;
    if (*str == '-' && *str++)
        flag = -1;
    if ('0' > *str && *str > '9')
        return 0;
    while (*str && ('0' <= *str && *str <= '9'))
		ret = (ret * 10) + *str++ - '0';
	return (ret * flag);
}

static unsigned char return_value(int num)
{
    return num;
}

int check_arg(t_ast *ast)
{
    if (ast->content == '0')
    {
        printf("0\n");
        return (0);
    }
    return (change_to_number(ast->content));
}

int ft_exit(t_ast *ast)
{
    write(1, "exit\n", 5);
    if (ast)
        return (check_arg(ast));
    exit(0);
    return (0);
}