#ifndef PIPELIBRARY_HPP
#define PIPELIBRARY_HPP

#include <iostream>

// Deletes old files if they exist and creates the named pipes folder
void initFifo(std::string dirName, mode_t permissions);
void fifoCreate(std::string fileName, mode_t permissions);
// Returns fd of the opened file to write
int fifoOpenWrite(std::string fileName);
// Returns fd of the opened file to read
int fifoOpenRead(std::string fileName);
void fifoClose(int fd);
void fifoWrite(int fd, void *message, size_t bufferSize);
void fifoRead(int fd, void *message, size_t bufferSize);

#endif