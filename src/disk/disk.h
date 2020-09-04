
#ifndef NOSBOX_C_DISK_H
#define NOSBOX_C_DISK_H

int createDisk(char* filename, int numberOfBytes);
int removeDisk(char* filename);
int mountDisk();
int readBlock(int disk, int blockNumber, void *block);
int writeBlock(int disk, int blockNumber, void *block);

#endif //NOSBOX_C_DISK_H
