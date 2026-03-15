#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1001

typedef struct node_t{
  int val;
  struct node_t* next;
}node;

node* head;

node* makenode(int v);
node* push(node* h, int v);
void propush();
void pop();

int main(){
  head = NULL;
  while(1){
    char cmd[101];
    scanf("%100s",cmd);
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
  q->next = h;
  return q;
}
void propush(){
  int k;
  scanf("%d",&k);
  head = push(head,k);
}
void pop(){
  node* tmp;
  if(head == NULL){
    printf("NULL\n");
    return;
  }
  tmp = head;
  printf("%d\n",tmp->val);
  head = head->next;
  free(tmp);
}

