#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "nitrorepo.h"

#define READ_BUFFER 1024;

int Execute(char *buffer)
{
    if(strcmp(buffer, "exit") == 0)
    {
        return 0;
    }

    if(strcmp(buffer, "test") == 0)
    {
        executeTest();
        return 1;
    }

    return 1;
}

char* parseLine(char* buffer)
{
    char* line = strtok(buffer, "\n");

    return line;
}

char* readLine()
{
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
        char* line = parseLine(buffer);

        //Execute if valid
        alive = Execute(line);

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
    //TODO: BUILD SOME SHIT HERE
    logoInit();
    fflush(stdout);
    cycle();
}


int main()
{
    //Run shell loop
    init();
    return 0;
}

