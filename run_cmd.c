#include "gitiz.h"

int run(char *cmd, char **arg)
{
    cmd_t cmds[] = {
        {"init", gitiz_init},
        {NULL, NULL}};
    int i = 0;
    while (cmds[i].name)
    {
        if (strcmp(cmd, cmds[i].name) == 0)
            break;
        i++;
    }
    return (cmds[i].f(arg));
}

void run_cmd(int argc, char **str)
{
    char **cmd;
    int i = 0;
    cmd = malloc(sizeof(char *) * argc);
    str++;
    while (i < argc)
    {
        *(cmd + i) = *(str + i);
        i++;
    }
    cmd[i] = NULL;
    run(cmd[0], cmd + 1);

    free(cmd);
}