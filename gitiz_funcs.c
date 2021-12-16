#include "gitiz.h"
int gitiz_init(char **repo)
{
    int status = 0;
    int i = 0, j = 0;
    int childpid;
    char *git_cmds[100][100] = {
        {"/usr/bin/touch", "touch", "README.md", NULL},
        {
            "/usr/bin/git",
            "git",
            "init",
            NULL,
            NULL,
        },
        {"/usr/bin/git", "git", "add", "README.md", NULL},
        {"/usr/bin/git", "git", "remote", "add", "origin", "https://github.com/mbukeRepo/gitiz.git", NULL},

        {NULL, NULL}};
    (void)repo;
    git_cmds[3][5] = repo[0];
    while (git_cmds[i][0])
    {
        childpid = fork();
        if (childpid == -1)
        {
            return (-1);
        }
        else if (childpid == 0)
        {
            execve(git_cmds[i][0], (git_cmds[i] + 1), NULL);
        }
        else
        {
            wait(&status);
        }
        i++;
    }
    // printf("Added an empty README.md\ngit add .\ngit commit -m \"initial commit\" \n");
    // printf("git remote add origin\n");
    return (status);
}
