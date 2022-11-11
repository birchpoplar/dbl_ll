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

struct node *next;
struct node *prev;
struct node *current = NULL;

int insert_first(int key, int data);

int main()
{
  struct node root;
  struct node *proot = &root;
  root.prev = NULL;
  root.next = NULL; 
  
  add_node(proot, 10);
  add_node(proot, 20);

  printf("data: %d\n", proot->data);
  
  return 0;
}

int add_node(struct node *n, int data)
{
  struct node *tmp = (struct node*) malloc(sizeof(struct node));
  int i = 0;

  for (i = 0; n->next == NULL; ++i) {
    printf("i %d\n", i);
    tmp = n;
    printf("set tmp\n");
    n = tmp->next;
    printf("set next");
    n->prev = tmp;
  }

  printf("now assign data\n");
  n->data = data;
  
  printf("%4d loc added\n", i);
  return i;
}
