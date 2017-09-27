#include <stdlib.h>
#include <stdio.h>
#include "Process.h"
#include "Sort.h"

void sort_processes(struct Process processes[], int size) {
        int i, j;
        int index_of_earliest;
        struct Process swap;
        for(i = 0; i < size; i++) {
                index_of_earliest = i;
                for(j = i; j < size; j++) {
                        if(processes[j].arrival_time < processes[index_of_earliest].arrival_time) {
                                index_of_earliest = j;
                        }
                }
                swap = processes[i];
                processes[i] = processes[index_of_earliest];
                processes[index_of_earliest] = swap;
        }
}
