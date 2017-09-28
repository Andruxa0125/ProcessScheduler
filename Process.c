#include <stdlib.h>
#include <stdio.h>
#include "Process.h"

void print_process(struct Process process) {
   printf("%-2d%14d%14d%10d%11d%15d%17d\n", process.id, process.arrival_time, process.service_time, process.priority, process.wait_time, process.response_time, process.turnaround_time);
}

void print_processes(struct Process processes[], int size) {
   printf("%-2s%14s%14s%10s%11s%15s%17s\n\n", "ID", "Arrival Time", "Service Time", "Priority", "Wait Time", "Response Time", "Turnaround Time");
   int i;
   for(i = 0; i < size; i++) {
      print_process(processes[i]);
   }
}
