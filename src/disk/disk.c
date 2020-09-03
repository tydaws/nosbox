#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>


int createDisk(char* filename, int numberOfBytes)
{
    FILE *disk;
    int fileDescriptor;
    struct stat buf;

    //Check to see if "disk" already exists
    if (stat(filename, &buf) == 0)
    {
        printf("File already exists.");
        return -1;
    }

    //Create new file to serve as disk
    disk = fopen(filename, "w");

    //Get the file descriptor to return
    fileDescriptor = fileno(disk);

    //Set "disk" size by seeking to size offset and storing NULL values
    fseek(disk, numberOfBytes - 1, SEEK_SET);
    fprintf(disk, NULL);

    fclose(disk);

    return fileDescriptor;
}