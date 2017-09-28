#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Process.h"
#include "ProcessQueue.h"

const struct Process NULL_PROCESS = {.id = -1, .arrival_time = -1, .service_time = -1, .priority = -1};

/*
 * Constructor for ProcessQueues. Must allocate memory because
 * the ProcessQueue defined within is local and ProcessQueue
 * contains a flexible array of structs.
 */
struct ProcessQueue * make_queue(int size){
   struct ProcessQueue *queue = malloc(sizeof(struct ProcessQueue));
   queue->process_queue = (struct Process *) malloc (size*sizeof(struct Process));
   queue->max_size = size;
   queue->size = 0;
   queue->last = -1;
   return queue;
}

/*
 * Destructor for ProcessQueues. Must manually free memory
 * because the ProcessQueue struct uses a flexible array of structs.
 */
void destroy_queue(struct ProcessQueue *queue){
   free(queue->process_queue);
   free(queue);
}

/*
 * Return the size of a ProcessQueue struct.
 */   
int size(struct ProcessQueue *queue){
   return queue->size;
}

/*
 * Returns the next element in the ProcessQueue. Note, the caller must check
 * the return value for NULL (use '#include <stddef.h>' to define NULL.
 */
struct Process * peek(struct ProcessQueue *queue){
   if(queue->size != 0){
      return &queue->process_queue[0];
   }
   else
      return NULL;
}

/*
 * Returns true if the ProcessQueue is full, false otherwise.
 */
bool is_full(struct ProcessQueue *queue){
   return queue->max_size == queue->size;
}

/*
 * Returns true if the ProcessQueue is empty, false otherwise.
 */
bool is_empty(struct ProcessQueue *queue){
   return queue->size == 0;
}

/*
 * Dequeues an element from the ProcessQueue and returns that element. Note, caller must
 * check return value for NULL_PROCESS (check if return.id == -1).
 */
struct Process dequeue(struct ProcessQueue *queue){
   if(!is_empty(queue)){
      queue->size -= 1;
      queue->last -= 1;
      return _normalize(queue);
;
   }
   else
      return NULL_PROCESS;
}

bool enqueue(struct ProcessQueue *queue, struct Process *process){
   if(queue->max_size != queue->size){
      queue->size += 1;
      queue->last += 1;
      queue->process_queue[queue->last] = *process;
      return true;
   }
   else
      return false;
}

/*
 * Helper function used after dequeueing
 */
struct Process _normalize(struct ProcessQueue *queue){
   int i;
   struct Process first = queue->process_queue[0];
   for(i = 0; i < queue->last + 1; i++){
      queue->process_queue[i] = queue->process_queue[i+1];
   }
   struct Process *processes = queue->process_queue;
   for(i = queue->last + 1; i < queue->max_size; i++){
      processes[i] = NULL_PROCESS;
   }
   return first;
}

void sort_by_arrival_time(struct ProcessQueue *queue){
   struct Process *processes = queue->process_queue;
   int index_of_earliest;
   struct Process swap;
   int i, j;
   for(i = 0; i < queue->size; i++) {
      index_of_earliest = i;
      for(j = i; j < queue->size; j++) {
         if(processes[j].arrival_time < processes[index_of_earliest].arrival_time) {
            index_of_earliest = j;
         }
      }
      swap = processes[i];
      processes[i] = processes[index_of_earliest];
      processes[index_of_earliest] = swap;
   }
}

void sort_by_service_time(struct ProcessQueue *queue){
   struct Process *processes = queue->process_queue;
   int index_of_earliest;
   struct Process swap;
   int i, j;
   for(i = 0; i < queue->size; i++) {
      index_of_earliest = i;
      for(j = i; j < queue->size; j++) {
         if(processes[j].service_time < processes[index_of_earliest].service_time) {
            index_of_earliest = j;
         }
      }
      swap = processes[i];
      processes[i] = processes[index_of_earliest];
      processes[index_of_earliest] = swap;
   }
}

void sort_by_priority(struct ProcessQueue *queue){
   struct Process *processes = queue->process_queue;
   int index_of_earliest;
   struct Process swap;
   int i, j;
   for(i = 0; i < queue->size; i++) {
      index_of_earliest = i;
      for(j = i; j < queue->size; j++) {
         if(processes[j].priority < processes[index_of_earliest].priority) {
            index_of_earliest = j;
         }
      }
      swap = processes[i];
      processes[i] = processes[index_of_earliest];
      processes[index_of_earliest] = swap;
   }
}
