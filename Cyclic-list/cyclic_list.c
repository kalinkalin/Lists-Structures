#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

struct Node{
  int value;
  struct Node* next;
  struct Node* previous;
};

struct List{
  struct Node* head;
  int size;
};

struct List* initializeList();
struct List* megre(struct List *, struct List *);
int find(struct List*, int);
void add(struct List*, int);
void delete(struct List*, int);
bool check(struct List,int);
void print_list(struct List);
int get_size(struct List*);

int main(){
  struct List *lista4 = initializeList();
  srand(time(NULL));
  double total_time1;
  double total_time2;
  struct timeval  time1, time2;

  for(int i = 0; i <1000; i++){
    add(lista4,rand()%100);
  }

  gettimeofday(&time1, NULL);
  for(int i = 0; i<1000; i++){
    same_element = find(lista4,200);
  }
  gettimeofday(&time2,NULL);
  total_time1 = (double) (time2.tv_usec - time1.tv_usec) / 1000000;
  total_time2 = (double) (time2.tv_sec - time1.tv_sec);
  printf ("same element - %f\n", total_time2 + total_time1);
  printf("\n");

  gettimeofday(&time1, NULL);
  for(int i = 0; i < 1000; i++){
    same_element = find(lista4, rand()%1000);
  }
  gettimeofday(&time2, NULL);
  total_time1 = (double) (time2.tv_usec - time1.tv_usec) / 1000000;
  total_time2 = (double) (time2.tv_sec - time1.tv_sec);
  printf ("random element - %f\n", total_time2 + total_time1);
}

struct List* megre(struct List *lista1, struct List *lista2){
  struct List *lista3 = malloc(sizeof(struct List));
  struct Node *node = lista1->head;

  while(node->next != lista1->head){
    add(lista3,node->value);
    node = node->next;
  }
  add(lista3,node->value);

  node = lista2->head;
  while(node->next != lista2->head){
    add(lista3,node->value);
    node = node->next;
  }
  add(lista3,node->value);

  return lista3;
}

struct List* initializeList(){
  struct List* lista = malloc(sizeof(struct List));
  lista->head = NULL;
  lista->size = 0;

  return lista;
}

int find(struct List *lista, int i){
  struct Node *node = lista->head;
  int j = 0;

  if(i >= 0 && i <= ((lista->size-1)/2)){
    while(j < i){
      node = node->next;
      j++;
    }
    return node->value;
  }

  else if(i > ((lista->size)/2) && i < lista->size){
    j = lista->size;
    while(j > i){
      node = node->previous;
      j--;
    }
    return node->value;
  }
  return -1;
}

void add(struct List* lista, int new_value){
  struct Node *node = malloc(sizeof(struct Node));
  node->value = new_value;

  if(lista->head == NULL){
    node->previous = node;
    node->next = node;
    lista->head = node;
  }

  else{
    node->previous = lista->head->previous;
    lista->head->previous->next = node;
    lista->head->previous = node;
    node->next = lista->head;
  }

  lista->size ++;
}

void delete(struct List *lista, int i){
  struct Node *node = lista->head;
  int j = 0;

  if(i >= 0 && i <= ((lista->size-1)/2)){
    while(j < i){
      node = node->next;
      j++;
    }
  }

  else if(i > ((lista->size)/2) && i < lista->size){
    j = lista->size;
    while(j > i){
      node = node->previous;
      j--;
    }
  }

  node->next->previous = node->previous;
  node->previous->next = node->next;
  if(node == lista->head){
    lista->head = node->next;
  }
  free(node);
}

bool check(struct List lista,int i){
  struct Node *node = lista.head;

  while(node->next != lista.head){
    if(node->value == i){
      return true;
    }
    node = node->next;
  }
  return false;
}

void print_list(struct List lista){
  struct Node* temp = lista.head;
  printf("%d\n", temp->value);
  temp = lista.head->next;

  while(temp != lista.head){
    printf("%d\n", temp->value);
    temp = temp->next;
  }
}

int get_size(struct List *lista){
  return lista->size;
}

bool isEmpty(struct List *lista){
  if(lista->head == NULL){
    return true;
  }
  else{
    return false;
  }
}
