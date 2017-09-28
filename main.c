#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include "Process.h"
#include "Sort.h"
#include "ProcessQueue.h"
#include "SJF.h"

struct ProcessQueue * generate_process_queue(int size);
const int MAX_SIZE = 10;

int main(){
   struct ProcessQueue *process_queue = generate_process_queue(MAX_SIZE);

   long long_input;
   char str_input[2];
   do{
      puts("\n   Process Scheduler");
      puts("0. Exit");
      puts("1. Print Processes");
      puts("2. First Come First Serve");
      puts("3. Shortest Job First");
      puts("4. Shortest Remaining Time");
      puts("5. Round Robin");
      puts("6. Highest Priority First (non-preemptive)");
      puts("7. Highest Priority First (preemptive)");
      printf("> ");
      fgets(str_input, 2, stdin);
      puts("");
      while(getchar() != '\n'){}
      if(str_input != NULL && isdigit(str_input[0])){
         long_input = strtol(str_input, NULL, 10);
         switch(long_input){
            case 0:
               puts("Exiting.");
               break;
            case 1:
               puts("Printing processes.\n");
               print_processes(process_queue->process_queue, MAX_SIZE);
               sort_by_arrival_time(process_queue);
               print_processes(process_queue->process_queue, MAX_SIZE);
               dequeue(process_queue);
               sort_by_priority(process_queue);
               print_processes(process_queue->process_queue, MAX_SIZE);
               dequeue(process_queue);
               sort_by_priority(process_queue);

               print_processes(process_queue->process_queue, MAX_SIZE);
               break;
            case 2:
               puts("Simulating First Come First Serve.\n");
               break;
            case 3:
               puts("Simulating Shortest Job First.\n");
               break;
            case 4:
               puts("Simulating Shortest Time Remaining.\n");
               break;
            case 5:
               puts("Simulating Round Robin.\n");
               break;
            case 6:
               puts("Simulating Highest Priority First (non-preemptive).\n");
               break;
            case 7:
               puts("Simulating Highest Priority First (preemptive).\n");
               break;
            default:
               puts("Input an integer between 0 and 7 inclusive.");
               break;
         }
      }
      else
         puts("Input an integer between 0 and 7 inclusive.");
   } while(long_input != 0);
}

struct ProcessQueue * generate_process_queue(int size){
   struct ProcessQueue * process_queue = make_queue(size);

   int seed = time(NULL);
   srand(seed);
   int i;
   for(i = 0; i < size; i++) {
      struct Process *process = malloc(sizeof(struct ProcessQueue));
      process->id = i;
      process->arrival_time = rand() % 100;
      process->service_time = rand() % 11;
      if(process->service_time == 0) {
         process->service_time += 1;
      }
      process->priority = rand() % 5;
      if(process->priority == 0) {
         process->priority += 1;
      }
      process->wait_time = -1;
      process->response_time = -1;
      process->turnaround_time = -1;
      enqueue(process_queue, process);
   }
   return process_queue;
}
