#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001

typedef struct node_t{
  long long val;
  struct node_t* next;
}node;

node* table[N] = {NULL};

node* makenode(long long k);
int hashcode(long long k);
node* findL(node* r, long long k);
node* insertL(node* r, long long k);
int find(long long k);
int insert(long long k);

int main(){
  while(1){
    char cmd[101];
    scanf("%s",cmd);
    if(strcmp(cmd,"*") == 0) break;
    insert(atoll(cmd));
  }
  while(1){
    char cmd[101];
    scanf("%100s",cmd);
    if(strcmp(cmd,"***") == 0) break;
    else if(strcmp(cmd,"find") == 0){
      long long k;
      scanf("%lld",&k);
      int c = find(k);
      printf("%d\n",c);
    }
    else if(strcmp(cmd,"insert") == 0){
      long long k;
      scanf("%lld",&k);
      int c = insert(k);
      printf("%d\n",c);
    }
  }
  return 0;
}

node* makenode(long long k){
  node* q = (node*) malloc(sizeof(node));
  if(q == NULL){
    printf("failed\n");
    exit(1);
  }
  q->val = k;
  q->next = NULL;
  return q;
}
int hashcode(long long k){
  int c;
  c = k % N;
  return c;
}
node* findL(node* r, long long k){
  while(r != NULL){
    if(r->val == k) return r;
    r = r->next;
  }
  return NULL;
}
node* insertL(node* r, long long k){
  if(r == NULL) return makenode(k);
  node* q = makenode(k);
  q->next = r;
  return q;
}
int find(long long k){
  int c = hashcode(k);
  node* q = findL(table[c],k);
  if(q == NULL) return 0;
  return 1;
}
int insert(long long k){
  int c = hashcode(k);
  node* q = findL(table[c],k);
  if(q != NULL) return 0;
  table[c] = insertL(table[c],k);
  return 1;
}
