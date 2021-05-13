#ifndef MONITORINFO_HPP
#define MONITORINFO_HPP

#include <iostream>
#include "../../../include/List.hpp"

class MonitorInfo {
private:
    pid_t pid;
    std::string clientFile;
    std::string serverFile;
    int fdRead;
    int fdWrite;
    List<std::string> countries;
    unsigned int accepted;
    unsigned int rejected;

public:
    MonitorInfo(pid_t p = 0, std::string cFile = "", std::string sFile = "", int fdR = 0, int fdW = 0)
    : pid(p), clientFile(cFile), serverFile(sFile), fdRead(fdR), fdWrite(fdW), accepted(0), rejected(0) {}
    ~MonitorInfo() {}
    MonitorInfo(const MonitorInfo &monitor);
    MonitorInfo &operator=(const MonitorInfo &monitor);

    int PID () const { return pid; }
    std::string cFile() const { return clientFile; }
    std::string sFile() const { return serverFile; }
    int fdR() const { return fdRead; }
    int fdW() const { return fdWrite; }
    List<std::string> &getCountries() { return countries; }
    unsigned int countriesNumber() { return countries.getSize(); }
    unsigned int getAccepted() { return accepted; }
    unsigned int getRejected() { return rejected; }

    void setPID(unsigned int p) { pid = p; }
    void setCFile(std::string cFile) { clientFile.clear(); clientFile.assign(cFile); }
    void setSFile(std::string sFile) { serverFile.clear(); serverFile.assign(sFile); }
    void setRead(unsigned int fdR) { fdRead = fdR; }
    void setWrite(unsigned int fdW) { fdWrite = fdW; }
    void insertCountry(std::string country) { countries.insertAscending(country); }
    void accept() { accepted++; }
    void reject() { rejected++; }

    friend bool operator==(const MonitorInfo &m1, const MonitorInfo &m2);
    friend bool operator!=(const MonitorInfo &m1, const MonitorInfo &m2);
    friend bool operator<(const MonitorInfo &m1, const MonitorInfo &m2);
    friend bool operator>(const MonitorInfo &m1, const MonitorInfo &m2);
    friend bool operator<=(const MonitorInfo &m1, const MonitorInfo &m2);
    friend bool operator>=(const MonitorInfo &m1, const MonitorInfo &m2);
    friend std::ostream &operator<<(std::ostream &os, const MonitorInfo &monitor);

    std::string *searchCountry(std::string name) { return countries.search(name); }
    void print() const { std::cout << *this; };
};

#endif