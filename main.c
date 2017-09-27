#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "Process.h"
#include "Sort.h"
#include "ProcessQueue.h"

void generate_processes(struct Process processes[], int size);
void print_process(struct Process process);
void print_processes(struct Process processes[], int size);

const int MAX_SIZE = 10;

int main() {
   struct Process processes[MAX_SIZE];
   struct ProcessQueue *queue = make_queue(MAX_SIZE);
   int processes_length = sizeof(processes)/sizeof(processes[0]);

   generate_processes(processes, processes_length);
   sort_processes(processes, processes_length);

   int i;
   for(i = 0; i < MAX_SIZE; i++){
      enqueue(queue, &processes[i]);
   }

   for(i = 0; i < MAX_SIZE; i++){
      dequeue(queue);
      if(peek(queue) != NULL){
         print_process(*peek(queue));
      }
   }

}

void generate_processes(struct Process processes[], int size) {
   int seed = time(NULL);
   srand(seed);

   int i;
   for(i = 0; i < size; i++) {
      processes[i].id = i;
      processes[i].arrival_time = rand() % 100;
      processes[i].service_time = rand() % 11;
      if(processes[i].service_time == 0) {
         processes[i].service_time += 1;
      }
      processes[i].priority = rand() % 5;
      if(processes[i].priority == 0) {
         processes[i].priority += 1;
      }
   }
}

void print_process(struct Process process) {
   printf("Process ID: %d\nArrival Time: %d\nService Time: %d\nPriority: %d\n", process.id, process.arrival_time, process.service_time, process.priority);
}

void print_processes(struct Process processes[], int size) {
   int i;
   for(i = 0; i < size; i++) {
      print_process(processes[i]);
      printf("\n");
   }
}
