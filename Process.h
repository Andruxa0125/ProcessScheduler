#ifndef PROCESS_H
#define PROCESS_H
struct Process{
   int id;
   int arrival_time;
   int service_time;
   int priority;
};

void print_process(struct Process process);
void print_processes(struct Process processes[], int size);
#endif
