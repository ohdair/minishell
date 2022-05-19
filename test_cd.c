#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    char	name[PATH_MAX];
	char	*path;

	if (getcwd(name, PATH_MAX) == NULL)
        printf("ERROR DON'T GET CWD\n");
    printf("%s\n", name);
    return (0);
}