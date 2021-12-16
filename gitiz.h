#ifndef _GITIZ_H_
#define _GITIZ_H
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "string.h"

extern char **environ;

/**
 * struct cmd - a new struct defining command
 *  @name: name of the command
 *  @f: function pointer to the command
 */

typedef struct cmd_s
{
    char *name;
    int (*f)(char **args);
} cmd_t;

typedef struct git_cmd_s
{
    char **cmd;
    char *loc;
} git_cmd_t;
void run_cmd(int argc, char **str);
int gitiz_init(char **);
#endif