#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat buf;

int createDisk(char* filename, int numberOfBytes)
{
    FILE *disk;
    int fileDescriptor;

    //Check to see if "disk" already exists
    if (stat(filename, &buf) == 0)
    {
        printf("File already exists.\n");
        return -1;
    }

    //Create new file to serve as disk
    disk = fopen(filename, "w");

    //Get the file descriptor to return
    fileDescriptor = fileno(disk);

    //Set "disk" size by seeking to size offset and storing "x"
    fseek(disk, numberOfBytes - 1, SEEK_SET);
    fprintf(disk, "x");

    fclose(disk);

    printf("Create Disk Executed\n");
    fflush(stdout);
    return fileDescriptor;
}

void removeDisk(char* fileName)
{
    if(stat(fileName, &buf) == 0)
    {
        remove(fileName);
        printf("\"%s\" removed.\n", fileName);
    }
    else
    {
        printf("Disk \"%s\" does not exist.\n", fileName);
    }
}