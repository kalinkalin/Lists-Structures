#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

struct Node{
  int value;
  struct Node* next;
};

struct List{
  struct Node* head;
  struct Node* tail;
  int size;
};

struct List* merge(struct List*, struct List*);
struct List *initializeList();
bool check(struct List*, int );
void add(struct List*, int);
void delete(struct List*, int);
int find(struct List*, int);
void print_list(struct List);
int get_size(struct List);

int main(){

  struct List *lista4 = initializeList();
  int element;
  double total_time1;
  double total_time2;
  struct timeval time1;
  struct timeval time2;
  srand(time(NULL));

  for(int i = 0; i < 1000; i++){
    add(lista4, rand()%100);
  }

  gettimeofday(&time1, NULL);
  for(int i = 0; i < 1000; i++){
    element = find(lista4, 512);
  }
  gettimeofday(&time2, NULL);
  total_time1 = (double) (time2.tv_usec - time1.tv_usec) / 1000000;
  total_time2 = (double) (time2.tv_sec - time1.tv_sec);
  printf ("same element - %f\n", total_time1 + total_time2);
  printf("\n");

  gettimeofday(&time1, NULL);
  for(int i = 0; i < 1000; i++){
    element = find(lista4, rand()%1000);
  }
  gettimeofday(&time2, NULL);
  total_time1 = (double) (time2.tv_usec - time1.tv_usec) / 1000000;
  total_time2 = (double) (time2.tv_sec - time1.tv_sec);
  printf ("random element - %f\n", total_time2 + total_time1);

  free(lista4);

}

struct List* merge(struct List *lista1, struct List *lista2){
  struct List* lista3 = initializeList();
  struct Node* temp = lista1->head;

  while(temp != NULL){
    add(lista3, temp->value);
    temp = temp->next;
  }
  temp = lista2->head;
  while(temp != NULL){
    add(lista3,temp->value);
    temp = temp->next;

  }
  free(temp);

  return lista3;
}

struct List* initializeList(){
  struct List* lista = malloc(sizeof(struct List));
  lista -> size = 0;
  lista -> head = NULL;
  lista -> tail = NULL;
  return lista;
}

void add(struct List *lista, int new_value){

  struct Node* new = (struct Node*) malloc(sizeof(struct Node));
  new->value = new_value;

  if(lista->head == NULL){
    new->next = NULL;
    lista->head = new;
    lista->tail = lista->head;
  }
  else{
    lista->tail->next = new;
    lista->tail = new;
  }
  lista->size ++;
}

int find(struct List* lista, int i){
  struct Node* temp = lista->head;
  int j = 0;

  while(temp != NULL && j < i){
    j++;
    temp = temp->next;
  }
  return temp->value;
}

bool check(struct List* lista, int i){
  struct Node* temp = lista->head;

  while(temp != NULL){
    if(temp->value == i){
      return true;
    }
    temp = temp->next;
  }

  return false;
}

void delete(struct List* lista, int i){
  struct Node* temp = lista->head;
  struct Node* pointer;
  int j;

  while(temp != NULL && j < i-1){
    temp = temp->next;
    j++;
  }
  pointer = temp->next;
  temp->next= temp->next->next;

  free(pointer);
}

void print_list(struct List lista){
  struct Node* temp = lista.head;
  while(temp != NULL){
    printf("%d\n", (*temp).value);
    temp = (*temp).next;
  }
}

int get_size(struct List lista){
  return lista.size;
}
