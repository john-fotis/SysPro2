#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "../../include/PipeLibrary.hpp"

void initFifo(std::string dirName, mode_t permissions) {
    struct stat buf;
    if (dirName.back() != '/') dirName.append("/");

    if (!stat(dirName.c_str(), &buf)) {
        std::cout << "\nDeleting old files...\n";
        system(("rm -rf " + dirName).c_str());
    }

    if (mkdir(dirName.c_str(), permissions) < 0) {
        perror("fifo/init/mkdir");
        exit(10);
    }
}

void fifoCreate(std::string fileName, mode_t permissions) {
    if (mkfifo(fileName.c_str(), permissions) < 0 && errno != EEXIST) {
        perror("fifo/create");
        exit(11);
    }
}

int fifoOpenWrite(std::string fileName) {
    int fd = -1;
    if ((fd = open(fileName.c_str(), O_WRONLY)) < 0) {
        perror("fifo/openWrite");
        exit(12);
    }
    return fd;
}

int fifoOpenRead(std::string fileName) {
    int fd = -1;
    if ((fd = open(fileName.c_str(), O_RDONLY)) < 0) {
        perror("fifo/openRead");
        exit(13);
    }
    return fd;
}

void fifoClose(int fd) {
    if (close(fd) < 0) {
        perror("fifo/close");
        exit(14);
    }
}

void fifoWrite(int fd, void *message, size_t bufferSize) {
    if (write(fd, message, bufferSize) < 0) {
        perror("fifo/write");
        exit(15);
    }
}

void fifoRead(int fd, void *message, size_t bufferSize) {
    if (read(fd, message, bufferSize) < 0) {
        perror("fifo/read");
        exit(16);
    }
}