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
void display_forward();
void display_backward();

int main()
{
  insert_last(3, 5);
  insert_last(4, 7);
  insert_first(1, 1);
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

void display_forward() {
  struct node *ptr = head;

  printf("[ ");
	 
  while (ptr != NULL) {
    printf(" k: %d, d: %d ", ptr->key, ptr->data);
    ptr = ptr->next;
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
  
