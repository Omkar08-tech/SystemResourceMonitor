#ifndef CPU_H
#define CPU_H

struct CpuStats {
    long user, nice, system, idle, iowait, irq, softirq, steal;
    long totalTime() const;
    long idleTime() const;
};

CpuStats getCpuStats();
float calculateCpuUsage(const CpuStats& prev, const CpuStats& curr);

#endif