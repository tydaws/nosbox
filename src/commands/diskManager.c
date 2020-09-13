#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../disk/disk.h"

int diskSize = NULL;
int fileDescriptor = NULL;
char *fileName = NULL;
int cflag = 0;
int rflag = 0;
int sflag = 0;
int mflag = 0;
int uflag = 0;



int main(int argc, char *argv[])
{
    int i;

    chdir("..");

    while ((i = getopt(argc, argv, "r:c:s:m:u:")) != -1)
    {
        switch(i)
        {
            case 'c':
                fileName = optarg;
                cflag = 1;
                break;
            case 's':
                diskSize = atoi(optarg);
                sflag = 1;
                break;
            case 'r':
                fileName = optarg;
                rflag = 1;
                break;
            case 'm':
                fileName = optarg;
                mflag = 1;
            case 'u':
                fileName = optarg;
                uflag = 1;
        }
    }

    if(rflag)
    {
        removeDisk(fileName);
    }
    if(cflag && sflag)
    {
        createDisk(fileName, diskSize);
    }
    else if(cflag && !sflag)
    {
        printf("Error: please specify file size\n");
    }
    else if(!cflag && sflag)
    {
        printf("Error: please specify a command\n");
    }

    if(mflag)
    {
        mountDisk(fileName);
    }
    if(uflag)
    {
        unmountDisk(fileName);
    }

    printf("Disk Manager Exiting\n");
    fflush(stdout);
    return 0;

}