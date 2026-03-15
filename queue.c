#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10001

typedef struct node_t{
  int val;
  struct node_t* next;
}node;

node* head, *tail;

node* makenode(int v);
node* push(node* h, int v);
void propush();
void pop();

int main(){
  head = NULL;
  tail = NULL;
  while(1){
    char cmd[101];
    scanf("%s",cmd);
    if(strcmp(cmd,"PUSH") == 0) propush();
    else if(strcmp(cmd,"POP") == 0) pop();
    else if(strcmp(cmd,"#") == 0) break;
  }
  return 0;
}

node* makenode(int v){
  node* q = (node*) malloc(sizeof(node));
  if(q == NULL){
    printf("failed\n");
    exit(1);
  }
  q->val = v;
  q->next = NULL;
  return q;
}
node* push(node* h, int v){
  if(h == NULL) return makenode(v);
  node* q = makenode(v);
  h->next = push(h->next,v);
  return h;
}
void propush(){
  int k;
  scanf("%d",&k);
  head = push(head,k);
}
void pop(){
  if(head == NULL){
    printf("NULL\n");
    return;
  }
  node* tmp = head;
  head = head->next;
  printf("%d\n",tmp->val);
  free(tmp);
}
