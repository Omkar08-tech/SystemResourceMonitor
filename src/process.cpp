#include "process.h"
#include <dirent.h>
#include <fstream>
#include <ncurses.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

struct ProcessInfo {
    int pid;
    std::string name;
};

void listProcesses(int row, int col, const std::string& filter) {
    DIR* proc = opendir("/proc");
    struct dirent* entry;
    std::vector<ProcessInfo> processes;

    while ((entry = readdir(proc)) != nullptr) {
        if (entry->d_type == DT_DIR) {
            std::string dirName = entry->d_name;
            if (std::all_of(dirName.begin(), dirName.end(), ::isdigit)) {
                std::string cmdlinePath = "/proc/" + dirName + "/comm";
                std::ifstream cmdFile(cmdlinePath);
                std::string cmd;
                std::getline(cmdFile, cmd);
                if (!cmd.empty() && (filter.empty() || cmd.find(filter) != std::string::npos)) {
                    processes.push_back({std::stoi(dirName), cmd});
                }
            }
        }
    }
    closedir(proc);

    std::sort(processes.begin(), processes.end(), [](const ProcessInfo& a, const ProcessInfo& b) {
        return a.name < b.name;
    });

    mvprintw(row, col, "PID      CMD");
    int r = row + 1;
    for (const auto& p : processes) {
        mvprintw(r++, col, "%-8d %-20s", p.pid, p.name.c_str());
        if (r > LINES - 2) break;
    }
}