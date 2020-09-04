#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "nitrorepo.h"

#define READ_BUFFER 1024
#define DELIM " \t\r\n\a"

int executeCommand(char *buffer, char *args[])
{
    //Compares input buffer to command names and then executes them
    if(strcmp(buffer, "exit") == 0)
    {
        return 0;
    }
    if(strcmp(buffer, "test") == 0)
    {
        executeTest();
        return 1;
    }
    if(strcmp(buffer, "diskmanager") == 0)
    {
        executeDiskManager(args);
        return 1;
    }
    return 1;
}

char** parseLine(char* buffer)
{
    char* line;
    char **argument = malloc(64 * sizeof(char*));
    int i = 0;

    line = strtok(buffer, DELIM);
    while(line != NULL)
    {
        argument[i] = line;
        i++;

        line = strtok(NULL, DELIM);
    }
    return argument;
}

char* readLine()
{
    //TODO: Handle case where input exceeds buffer size
    int bufferSize = READ_BUFFER;
    char *buffer = malloc(sizeof(char) * bufferSize);
    read(STDIN_FILENO, buffer, bufferSize);
    return buffer;
}

void cycle()
{
    char *buffer;
    int alive;
    do
    {
        //Setup our prompt
        printf("NITROSH - $ ");
        fflush(stdout);

        //Get input from user
        buffer = readLine();

        //Parse user input
        char** line = parseLine(buffer);

        //executeCommand if valid
        alive = executeCommand(line[0], line);

        free(buffer);
    }
    while(alive);
}

void logoInit()
{
    printf("           *---------------------------------------------* \n");
    printf("           |  /\\ \\ \\\\_   \\/__   \\/__\\  /___\\ / __\\ /\\  /\\|\n");
    printf("           | /  \\/ / / /\\/  / /\\/ \\// //  // \\ \\  / /_/ /|\n");
    printf("           |/ /\\  /\\/ /_   / / / _  \\/ \\_// __\\ \\/ __  / |\n");
    printf("           |\\_\\ \\/\\____/   \\/  \\/ \\_/\\___/  \\___/\\/ /_/  |\n");
    printf("           *---------------------------------------------* \n");
    printf("                                                      v0.1 \n\n");
}


void init()
{
    logoInit();
    cycle();
}


int main()
{
    init();
    return 0;
}

