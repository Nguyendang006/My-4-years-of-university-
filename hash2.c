#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 51
#define N1 10001

typedef struct node_t{
  char key[N];
  struct node_t* leftchild;
  struct node_t* rightchild;
}node;

node* T[N1];

node* makenode(char* k);
int hashcode(char* k);
node* findBST(node* r, char* k);
node* insertBST(node* r, char* k);
int find(char* k);
int insert(char* k);

int main(){
  char cmd[20];
  for(int i = 0;i < N1;i++)
    T[i] = NULL;
  while(1){
    char k[N];
    scanf("%50s",k);
    if(strcmp(k,"*") == 0) break;
    insert(k);
  }
  while(1){
    scanf("%19s",cmd);
    if(strcmp(cmd,"***") == 0) break;
    else if(strcmp(cmd,"find") == 0){
      char k[N];
      scanf("%s",k);
      int ans = find(k);
      printf("%d\n",ans);
    }
    else if(strcmp(cmd,"insert") == 0){
      char k[N];
      scanf("%s",k);
      int ans = insert(k);
      printf("%d\n",ans);
    }
  }
  return 0;
}

node* makenode(char* k){
  node* p = (node*) malloc(sizeof(node));
  if(p == NULL){
    printf("failed\n");
    exit(1);
  }
  strcpy(p->key, k);
  p->leftchild = NULL;
  p->rightchild = NULL;
  return p;
}
int hashcode(char* k){
  int c = 0;
  for(int i = 0;i < strlen(k);i++)
    c = (c*256 + k[i]) % N1;
  return c;
}
node* findBST(node* r, char* k){
  if(r == NULL) return NULL;
  int c = strcmp(r->key,k);
  if(c == 0) return r;
  if(c < 0) return findBST(r->rightchild,k);
  else return findBST(r->leftchild,k);
}
node* insertBST(node* r, char* k){
  if(r == NULL) return makenode(k);
  if(strcmp(r->key,k) < 0)
    r->rightchild = insertBST(r->rightchild,k);
  else
    r->leftchild = insertBST(r->leftchild,k);
  return r;
}
int find(char* k){
  int i = hashcode(k);
  node* p = findBST(T[i],k);
  if(p == NULL) return 0;
  return 1;
}
int insert(char* k){
  int i = hashcode(k);
  node* p = findBST(T[i],k);
  if(p != NULL) return 0;
  T[i] = insertBST(T[i],k);
  return 1;
}
