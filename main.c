#include "gitiz.h"

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("Usage: gitiz <cmd> [args...]\n");
        return (-1);
    }
    run_cmd(argc, argv);
    return (0);
}