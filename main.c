#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include "Constants.h"
#include "Process.h"
#include "Sort.h"
#include "ProcessQueue.h"
#include "SJF.h"

int main(){
   struct Process processes[MAX_SIZE];
   struct ProcessQueue *queue = generate_process_queue(MAX_SIZE);

   long long_input;
   char str_input[2];
   struct ProcessQueue * one = generate_process_queue(1);
   do{
      puts("\n   Process Scheduler");
      puts("0. Exit");
      puts("1. Generate New Processes");
      puts("2. Print Processes");
      puts("3. First Come First Serve");
      puts("4. Shortest Job First");
      puts("5. Shortest Remaining Time");
      puts("6. Round Robin");
      puts("7. Highest Priority First (non-preemptive)");
      puts("8. Highest Priority First (preemptive)");
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
               puts("Generating Processes.");
               destroy_queue(queue);
               queue = generate_process_queue(MAX_SIZE);
               break;
            case 2:
               puts("Printing processes.\n");
               print_queue(queue);
               break;
            case 3:
               puts("Simulating First Come First Serve.\n");
               break;
            case 4:
               puts("Simulating Shortest Job First.\n");
               shortest_job_first(queue);
               break;
            case 5:
               puts("Simulating Shortest Time Remaining.\n");
               break;
            case 6:
               puts("Simulating Round Robin.\n");
               break;
            case 7:
               puts("Simulating Highest Priority First (non-preemptive).\n");
               break;
            case 8:
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
   destroy_queue(queue);
}
