#include "nitrorepo.h"
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

void launch(char* task, char* args[])
{
    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0)
    {
        if (execvp(task, args) == -1) {
            perror("exec failed");
        }
    }
    else if(pid < 0)
    {
        perror("nitrosh fork failed");
    }
    else
    {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

}

void executeTest()
{
    launch(TEST, NULL);
}

void executeDiskManager(char* args[])
{
    launch(DISKMANAGER, args);
}