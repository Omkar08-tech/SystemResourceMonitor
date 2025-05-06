#include <ncurses.h>
#include <chrono>
#include <thread>
#include "cpu.h"
#include "memory.h"
#include "process.h"

int main(int argc, char* argv[]) {
    std::string filter = "";
    if (argc > 1) {
        filter = argv[1];
    }

    initscr();
    noecho();
    cbreak();
    curs_set(0);

    while (true) {
        clear();

        CpuStats prev = getCpuStats();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        CpuStats curr = getCpuStats();

        float cpuUsage = calculateCpuUsage(prev, curr);

        mvprintw(0, 0, "CPU Usage: %.2f%%", cpuUsage);
        printMemoryUsage(1, 0);
        listProcesses(4, 0, filter);

        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    endwin();
    return 0;
}