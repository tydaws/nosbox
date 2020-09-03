#include <stdio.h>
#include <unistd.h>
#include <argp.h>
#include "../../disk/disk.h"

int diskSize;
int fileDescriptor;
char *filename;

void setFileName(char *fileName)
{
    if(fileName == NULL)
    {

    }
}


int main(int argc, char *argv[])
{
    int i;
    while ((i = getopt (argc, argv, "co:")) != -1)
    {
        switch(i)
        {
            case 'c':
                setFileName(optarg);
                break;
            case 's':
                break;
            default:
                printf("Executed Disk Manager");


        }
    }

}