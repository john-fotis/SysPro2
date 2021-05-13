#ifndef SIGNALLIBRARY_HPP
#define SIGNALLIBRARY_HPP

#include <csignal>
#include <iostream>

volatile sig_atomic_t childDied = false;
volatile sig_atomic_t shouldRespawn = true;
volatile sig_atomic_t newFilesAdded = false;
volatile sig_atomic_t shutDown = false;

void signalHandler(int signo) {
    switch (signo) {
        case SIGINT:
            shutDown = true;
            return;
        case SIGQUIT:
            shutDown = true;
            return;
        case SIGCHLD:
            childDied = true;
            if (shutDown) shouldRespawn = false;
            return;
        case SIGUSR1:
            newFilesAdded = true;
            return;
        default:
            std::cout.write("Uknown Signal caught", sizeof("Uknown Signal caught"));
            return;
    }
}

#endif