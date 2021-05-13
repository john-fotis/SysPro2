#include "include/MonitorInfo.hpp"

MonitorInfo::MonitorInfo(const MonitorInfo &monitor) {
    if (this == &monitor) return;
    pid = monitor.PID();
    clientFile.assign(monitor.cFile());
    serverFile.assign(monitor.sFile());
    fdRead = monitor.fdR();
    fdWrite = monitor.fdW();
    countries = monitor.countries;
    accepted = monitor.accepted;
    rejected = monitor.rejected;
}

MonitorInfo &MonitorInfo::operator=(const MonitorInfo &monitor) {
    if (this == &monitor) return *this;
    pid = monitor.PID();
    clientFile.assign(monitor.cFile());
    serverFile.assign(monitor.sFile());
    fdRead = monitor.fdR();
    fdWrite = monitor.fdW();
    countries = monitor.countries;
    accepted = monitor.accepted;
    rejected = monitor.rejected;
    return *this;
}

bool operator==(const MonitorInfo &r1, const MonitorInfo &r2) {
    return (r1.PID() == r2.PID());
}

bool operator!=(const MonitorInfo &r1, const MonitorInfo &r2) {
    return !(r1 == r2);
}

bool operator<(const MonitorInfo &r1, const MonitorInfo &r2) {
    return r1.PID() < r2.PID();
}

bool operator>(const MonitorInfo &r1, const MonitorInfo &r2) {
    return r1.PID() > r2.PID();
}

bool operator<=(const MonitorInfo &r1, const MonitorInfo &r2) {
    return r1.PID() <= r2.PID();
}

bool operator>=(const MonitorInfo &r1, const MonitorInfo &r2) {
    return r1.PID() >= r2.PID();
}

std::ostream &operator<<(std::ostream &os, const MonitorInfo &monitor) {
    os  << monitor.PID() << " " << monitor.cFile() << " " << monitor.sFile()
        << " " << monitor.fdR() << " " << monitor.fdW() << " "
        << monitor.accepted << " " << monitor.rejected << std::endl;
    monitor.countries.print();
    return os;
}