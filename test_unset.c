#include "minishell.h"

int main(int argc, char **argv)
{
    t_node *head;
    t_node *body;
    t_node *tail;

    head = (t_node*)malloc(sizeof(t_node));
    body = (t_node*)malloc(sizeof(t_node));
    tail = (t_node*)malloc(sizeof(t_node));
    head->content = argv[1];
    head->next = body;
    body->content = argv[2];
    body->next = tail;
    tail->content = argv[3];
    tail->next = NULL;
    ft_unset(head);
    return (0);
}