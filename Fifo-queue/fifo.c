#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
  struct Node* previous;
  int value;
};

struct Queue{
  struct Node* first;
  int size;
};

void enqueue(struct Queue*, int);
void initizalizeQueue(struct Queue*);
int dequeue(struct Queue*);
int getSize(struct Queue);
bool isEmpty(struct Queue);

int main(){
  int array[4];
  struct Queue queue;
  struct Queue *q = &queue;

  enqueue(q,5);
  enqueue(q,6);
  enqueue(q,8);
  array[0] = dequeue(q);
  array[1] = dequeue(q);
  array[2] = dequeue(q);
  array[3] = dequeue(q);

  for(int i =0; i < 4; i ++){
    printf("%d\n", array[i]);
  }
}

void initizalizeQueue(struct Queue *queue){
  queue->first = NULL;
  queue->size = 0;
}

void enqueue(struct Queue *queue, int new_value){

  struct Node *new;
  new = (struct Node*)malloc(sizeof(struct Node));

  if(queue->first != NULL){
    new->value = new_value;
    new->previous = queue->first;
    queue->first = new;
  }
  else{
    new->value = new_value;
    new->previous = NULL;
    queue->first = new;
  }
}

int dequeue(struct Queue *queue){
  if(queue->first != NULL){
    struct Node* toDelete = queue->first;
    int temp = queue->first->value;
    queue->first = queue->first->previous;

    free(toDelete);
    return temp;
  }
  else{
    printf("Cannot dequeue from an empty FIFO\n");
    return -1;
  }
}

int getSize(struct Queue queue){
  return queue.size;
}

bool isEmpty(struct Queue queue){
  if(queue.first == NULL){
    return true;
  }
  else{
    return false;
  }
}
