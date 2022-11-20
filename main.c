#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  int key;
  struct node *prev;
  struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;
bool isEmpty() {
  return head == NULL;
}


void insert_first(int key, int data);
void insert_last(int key, int data);
void delete(int key);
int find(int key);
void substitute(int key, int nkey, int data);
void display_forward();
void display_backward();

int main()
{
  insert_last(3, 5);
  insert_last(4, 7);
  insert_first(1, 1);
  insert_first(7, 9);
  delete(7);
  insert_first(2, 7);
  delete(3);
  delete(4);
  printf("Key %d is at loc %d\n", 2, find(2));
  printf("Key %d is at loc %d\n", 10, find(10));
  insert_first(4,3);
  delete(1);
  insert_last(9,1);
  display_forward();
  display_backward();
  return 0;
}

void insert_first(int key, int data)
{
  struct node *link = (struct node*) malloc(sizeof(struct node));
  link->key = key;
  link->data = data;
  
  if(isEmpty()) {
    last = link;
  } else {
    head->prev = link;
  }
  link->next = head;
  head = link;
}

void insert_last(int key, int data)
{
  struct node *link = (struct node*) malloc(sizeof(struct node));
  link->key = key;
  link->data = data;

  if(isEmpty()) {
    head = link; 
  } else {
    last->next = link;
  }
  link->prev = last;
  last = link;
}

void delete(int key)
{
  struct node *link, *tmp_prev, *tmp_next;
  link = head;
  while(link->key != key)
    link = link->next;
  tmp_prev = link->prev;
  tmp_next = link->next;
  if (tmp_next == NULL) {
    tmp_prev->next = NULL;
    last = tmp_prev;
  } else if (tmp_prev == NULL) {
    tmp_next->prev = NULL;
    head = tmp_next;
  } else {
    tmp_prev->next = link->next;
    tmp_next->prev = link->prev;
  }
  free(link);
}

int find(int key)
{
  struct node *link;
  int i = 0;
  
  link = head;

  for(i=0; link != last && link->key != key; i++)
    link = link->next;

  if (link == last) {
    return 0;
  } else {
    return ++i;
  }
}

void display_forward() {
  struct node *ptr = head;
  int i = 0;
  
  printf("[ ");
	 
  while (ptr != NULL) {
    printf(" k: %d, d: %d ", ptr->key, ptr->data);
    ptr = ptr->next;
    i++;
  }

  printf(" ]\n");
}

void display_backward() {
  struct node *ptr = last;

  printf("[ ");
	 
  while (ptr != NULL) {
    printf(" k: %d, d: %d ", ptr->key, ptr->data);
    ptr = ptr->prev;
  }

  printf(" ]\n");
}
  
