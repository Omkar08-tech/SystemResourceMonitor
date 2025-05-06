#include "memory.h"
#include <fstream>
#include <ncurses.h>
#include <string>

void printMemoryUsage(int row, int col) {
    std::ifstream file("/proc/meminfo");
    std::string label;
    long memTotal = 0, memAvailable = 0, value;
    std::string unit;

    while (file >> label >> value >> unit) {
        if (label == "MemTotal:") memTotal = value;
        if (label == "MemAvailable:") memAvailable = value;
        if (memTotal && memAvailable) break;
    }

    float used = (memTotal - memAvailable) / 1024.0;
    float total = memTotal / 1024.0;
    float percent = 100.0 * used / total;

    mvprintw(row, col, "Memory Usage: %.2f MB / %.2f MB (%.2f%%)", used, total, percent);
}