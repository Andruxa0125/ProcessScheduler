#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include "Process.h"
#include "Sort.h"
#include "ProcessQueue.h"
#include "SJF.h"

void generate_processes(struct Process processes[], int size);
const int MAX_SIZE = 10;

int main(){
   struct Process processes[MAX_SIZE];
   struct ProcessQueue *queue = make_queue(MAX_SIZE);
   int processes_length = sizeof(processes)/sizeof(processes[0]);

   generate_processes(processes, processes_length);

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
               print_processes(processes, MAX_SIZE);
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
//   int i;
//   for(i = 0; i < MAX_SIZE; i++){
//      enqueue(queue, &processes[i]);
//   }
//
//   for(i = 0; i < MAX_SIZE; i++){
//      if(peek(queue) != NULL){
//         print_process(*peek(queue));
//      }
//      dequeue(queue);
//   }
//   destroy_queue(queue);
//   print_processes(processes, MAX_SIZE);

}

void generate_processes(struct Process processes[], int size){
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
