#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10001

typedef struct node_t{
  char v[100];
  int used;
  struct node_t* next;
}node;

node* h[N] = {NULL};

node* makenode(char* s);
int hash(char* s);
void insert(char* s);
void add(char* s);
char* get(char* s);
void profind();
void proinsert();

int main(){
  while(1){
    char cmd[100];
    scanf("%s",cmd);
    if(strcmp(cmd,"*") == 0) break;
  }
  while(1){
    char cmd[100];
    scanf("%s",cmd);
    if(strcmp(cmd,"***") == 0) break;
    else if(strcmp(cmd,"find") == 0) profind();
    else if(strcmp(cmd,"insert") == 0) proinsert();
  }
  return 0;
}

node* makenode(char* s){
  node* q = (node*) malloc(sizeof(node));
  strcpy(q->v,s);
  q->next = NULL;
  return q;
}
int hash(char* s);
void insert(char* s);
void add(char* s);
char* get(char* s);
void profind();
void proinsert();
