#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20003

typedef struct node_t{
  char v[100];
  int used;
  struct node_t* next;
}node;

node* h[N] = {NULL};

node* makenode(char* s);
int hash(char* s);
int insert(char* s);
int find(node* r, char* s);
int add(char* s);
int find1(char* s);
void profind();
void proinsert();

int main(){
  for(int i = 0;i < N;i++){
    h[i] = (node*) malloc(sizeof(node));
    h[i]->used = 0;
    h[i]->next = NULL;
  }
  while(1){
    char cmd[100];
    scanf("%s",cmd);
    if(strcmp(cmd,"*") == 0) break;
    add(cmd);
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
  q->used = 0;
  q->next = NULL;
  return q;
}
int find(node* r, char* s){
  for(node* q = r;q != NULL;q = q->next){
    if(strcmp(q->v,s) == 0) return 1;
  }
  return 0;
}
int hash(char* s){
  int c = 0;
  for(int i = 0;i < strlen(s);i++){
    c = (c * 256 + s[i]) % N;
  }
  return c;
}
int insert(char* s){
  int c = hash(s);
  if(h[c] == NULL){
    h[c] = makenode(s);
    return 1;
  }
  if(find(h[c],s)) return 0;
  node* q = makenode(s);
  q->next = h[c];
  h[c] = q;
  return 1;
}
void profind(){
  char a[100];
  scanf("%s",a);
  int c = hash(a);
  printf("%d\n",find1(a));
}
void proinsert(){
  char a[100];
  scanf("%s",a);
  printf("%d\n",add(a));
}
int add(char* s){
  int c = hash(s);
  if(find1(s)) return 0;
  while(h[c]->used && strcmp(h[c]->v,s) != 0){
      c = (c + 1) % N;
  }
  if(!h[c]->used){
    h[c] = makenode(s);
    h[c]->used = 1;
    return 1;
  }
  return 0;
} 
int find1(char* s){
  int c = hash(s);
  while(h[c]->used){
    if(strcmp(h[c]->v,s) == 0) return 1;
    c = (c + 1) % N;
  }
  return 0;
}
