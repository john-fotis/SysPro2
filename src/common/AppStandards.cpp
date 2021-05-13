#include <iostream>
#include <sys/stat.h>

#include "../../include/AppStandards.hpp"
#include "../../include/DataManipulationLib.hpp"

bool checkServerArgs(List<std::string> &args) {
    unsigned int errorNumber = 0;
    struct stat inputDirName;

    if (args.getSize() != 9) errorNumber = serverArgsNum;
    else {
        if (args.getNode(1)->compare("-m")) errorNumber = monitorIdentifier;
        if (isInt(*args.getNode(2)))
            if (myStoi(*args.getNode(2)) < 1) errorNumber = monitorNumber;
        if (args.getNode(3)->compare("-b")) errorNumber = bufferIdentifier;
        if (isInt(*args.getNode(4)))
            if (myStoi(*args.getNode(4)) < 1) errorNumber = bufferSize;
        if (args.getNode(5)->compare("-s")) errorNumber = bloomIdentifier;
        if (isInt(*args.getNode(6)))
            if (myStoi(*args.getNode(6)) < 1) errorNumber = bloomSize;
        if (args.getNode(7)->compare("-i")) errorNumber = directoryIdentifier;
        if ((stat(args.getNode(8)->c_str(), &inputDirName))) errorNumber = directoryNotFound;
    }

    if (errorNumber) {
        if (errorNumber == 1) std::cerr << ARGS_NUMBER;
        else if (errorNumber == 2) std::cerr << "Invalid Monitor number identifier.\n";
        else if (errorNumber == 3) std::cerr << "Invalid number of Monitors.\n";
        else if (errorNumber == 4) std::cerr << "Invalid buffer size identifier.\n";
        else if (errorNumber == 5) std::cerr << "Invalid buffer size.\n";
        else if (errorNumber == 6) std::cerr << "Invalid bloom filter identifier.\n";
        else if (errorNumber == 7) std::cerr << "Invalid bloom filter size.\n";
        else if (errorNumber == 8) std::cerr << "Invalid input directory identifier.\n";
        else if (errorNumber == 9) std::cerr << "Input directory not found.\n";
        std::cout << "Input should be like: " << INPUT_SERVER;
        return false;
    }

    return true;
}

bool checkClientArgs(List<std::string> &args) {
    unsigned int errorNumber = 0;
    struct stat inputFileName;

    if (args.getSize() != 3) errorNumber = clientArgsNum;
    else {
        if ((stat(args.getNode(1)->c_str(), &inputFileName))) errorNumber = fifo1NotFound;
        if ((stat(args.getNode(2)->c_str(), &inputFileName))) errorNumber = fifo2NotFound;
    }

    if (errorNumber) {
        if (errorNumber == 1) std::cerr << ARGS_NUMBER;
        else if (errorNumber == 2) std::cerr << "FIFO file 1 not found\n";
        else if (errorNumber == 3) std::cerr << "FIFO file 2 not found\n";
        std::cout << "Input should be like: " << INPUT_CLIENT;
        return false;
    }

    return true;
}

int getOptions (std::string input) {
    if (!input.compare("/exit")) return exitProgram;
    if (!input.compare("/travelRequest")) return travelRequest;
    if (!input.compare("/travelStats")) return travelStats;
    if (!input.compare("/addVaccinationRecords")) return addRecords;
    if (!input.compare("/searchVaccinationStatus")) return searchStatus;
    if (!input.compare("/help")) return help;
    return -1;
}

void printOptions() {
    std::cout << "\nOptions:\n" \
    "=============================================================\n" \
    "/travelRequest citizenID date countryFrom countryTo virusName\n" \
    "/travelStats virusName date1 date2 [country]\n" \
    "/addVaccinationRecords country\n" \
    "/searchVaccinationStatus citizenID\n" \
    "/exit\n" \
    "=============================================================\n";
}