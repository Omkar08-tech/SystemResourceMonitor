#include "cpu.h"
#include <fstream>
#include <sstream>
#include <string>

long CpuStats::totalTime() const {
    return user + nice + system + idle + iowait + irq + softirq + steal;
}

long CpuStats::idleTime() const {
    return idle + iowait;
}

CpuStats getCpuStats() {
    std::ifstream file("/proc/stat");
    std::string line;
    CpuStats stats{};

    if (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string cpu;
        ss >> cpu >> stats.user >> stats.nice >> stats.system >> stats.idle
           >> stats.iowait >> stats.irq >> stats.softirq >> stats.steal;
    }

    return stats;
}

float calculateCpuUsage(const CpuStats& prev, const CpuStats& curr) {
    long prevIdle = prev.idleTime();
    long currIdle = curr.idleTime();
    long prevTotal = prev.totalTime();
    long currTotal = curr.totalTime();

    long totalDiff = currTotal - prevTotal;
    long idleDiff = currIdle - prevIdle;

    return 100.0f * (totalDiff - idleDiff) / totalDiff;
}