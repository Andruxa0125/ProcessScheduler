#include <stdbool.h>
#include "Process.h"

struct ProcessQueue{
   int max_size;
   int size;
   int last;
   struct Process *process_queue;
};

struct ProcessQueue * make_queue(int size);
void destroy_queue(struct ProcessQueue *queue);
int size(struct ProcessQueue *queue);
struct Process * peek(struct ProcessQueue *queue);
bool is_full(struct ProcessQueue *queue);
bool is_empty(struct ProcessQueue *queue);
struct Process dequeue(struct ProcessQueue *queue);
bool enqueue(struct ProcessQueue *queue, struct Process *process);
struct Process _normalize(struct ProcessQueue *queue);
