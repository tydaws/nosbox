#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BACK ".."
#define DOUBLEBACK "../.."

struct stat buf;

int folderSetup()
{
    int root = mkdir("drivebay", 0000711);

    if(root == 0 || errno == EEXIST)
    {
        chdir("drivebay");
        int mount = mkdir("mounted", 0000711);
        if(mount != 0 && errno != EEXIST)
        {
            perror("Folder setup failed");
            return 0;
        }

        int unmount = mkdir("unmounted", 0000711);
        if(unmount != 0 && errno != EEXIST)
        {
            perror("Folder setup failed");
            return 0;
        }

        chdir("..");
    }
    else
    {
        perror("Folder setup failed");
        return 0;
    }

    return 1;
}


int createDisk(char* filename, int numberOfBytes)
{
    FILE *disk;
    int fileDescriptor;
    int setup = folderSetup();

    //return error if folder setup fails
    if(setup == 0)
    {
        return -1;
    }

    //change directory to unmounted
    chdir("drivebay/unmounted");


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

    //navigate back to root folder
    chdir(DOUBLEBACK);

    return fileDescriptor;
}

void removeDisk(char* fileName)
{
    int nav= chdir("drivebay/unmounted");

    if(nav == -1)
    {
        printf("Error: could not navigate to disk directory\n");
    }
    else
    {
        if(stat(fileName, &buf) == 0)
        {
            remove(fileName);
            printf("\"%s\" removed.\n", fileName);
        }
        else
        {
            printf("Disk \"%s\" is mounted or does not exist.\n", fileName);
        }
    }
}

int mountDisk(char* fileName)
{
    int nav = chdir("drivebay/mounted");

    if(nav == -1)
    {
        printf("Error: could not navigate to disk directory\n");
        return 0;
    }
    else if(stat(fileName, &buf) == 0)
    {
        printf("\"%s\" is already mounted.\n", fileName);
        return 0;
    }

    chdir(BACK);

    nav = chdir("unmounted");

    if(nav == -1)
    {
        perror("Navigation error");
        chdir(BACK);
        return 0;
    }
    else if(stat(fileName, &buf) == 0)
    {

        char newLocation[1024] = "../mounted/";
        strcat(newLocation, fileName);

        int result = rename(fileName, newLocation);

        if (result != 0)
        {
            perror("Mount failure");
            chdir(DOUBLEBACK);
            return 0;
        }

        printf("\"%s\" mounted.\n", fileName);
        fflush(stdout);
        chdir(DOUBLEBACK);
        return 1;
    }

    chdir(DOUBLEBACK);
    printf("mount failed3\n");
    perror("Mount failure");
    fflush(stdout);
    return 0;
}

int unmountDisk(char* fileName)
{
    int nav = chdir("drivebay/mounted");

    if(nav == -1)
    {
        printf("Error: could not navigate to disk directory\n");
        return 0;
    }
    else if(stat(fileName, &buf) == 0)
    {
        char newLocation[1024] = "../unmounted/";
        strcat(newLocation, fileName);

        int result = rename(fileName, newLocation);

        if (result != 0)
        {
            perror("Unmount failure");
            chdir(DOUBLEBACK);
            return 0;
        }

        printf("\"%s\" unmounted.\n", fileName);
        fflush(stdout);
        chdir(DOUBLEBACK);
        return 1;
    }
}