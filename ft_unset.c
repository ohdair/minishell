#define SUCCESS 0
#define FAIL 1

typedef struct s_node
{
    char *content;
    struct s_node *next;
}   t_node;

int is_right(t_node *env)
{
    if (*(env->content)) // 영어 소문자, 대문자, _ 인지 확인
        return (FAIL);
    
    while (*(env->content)) // 영어 소문자, 대문자, _, 숫자 인지 확인
    {
        env = env->next;
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
        if (!is_env(env))
        {
            status = FAIL;
            print_error(env);
        }
        else
        {
            node = find_env(env);
            remove(node);
        }
        env = env->next;
    }
    return (status);
}