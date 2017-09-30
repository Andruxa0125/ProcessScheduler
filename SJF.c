#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Process.h"
#include "ProcessQueue.h"
#include "SJF.h"
#include "Constants.h"

void shortest_job_first(struct ProcessQueue *scheduler){
   if(!is_empty(scheduler)){
      sort_by_arrival_time(scheduler);
      struct ProcessQueue *queue = make_queue(MAX_SIZE);
      struct ProcessQueue *result= make_queue(MAX_SIZE);
      enqueue(queue, dequeue(scheduler));
   
      struct Process *process;
      int quanta = 0;
      while(is_empty(scheduler) != true || is_empty(queue) != true){
         if(is_empty(queue) == true){
            quanta++;
            bool can_queue = !is_empty(scheduler);
            while(can_queue){
               if(quanta >= peek(scheduler)->arrival_time){
                  enqueue(queue, dequeue(scheduler));
                  can_queue = !is_empty(scheduler);
               }
               else
                  can_queue = false;
            }
         }
         else{
            process = dequeue(queue);
            process->response_time = quanta;
            quanta += process->service_time;
            process->service_time = 0;
            bool can_queue = !is_empty(scheduler);
            while(is_empty(scheduler) == false && can_queue){
               if(quanta >= peek(scheduler)->arrival_time){
                  enqueue(queue, dequeue(scheduler));
                  can_queue = is_empty(scheduler);
               }
               else
                  can_queue = false;
            }
            enqueue(result, process);
         }
      }
      puts("Printing Result.");
      print_queue(result);
   }
   else
      puts("Process Queue was empty.");
}
