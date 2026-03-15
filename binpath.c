#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1001

typedef struct node_t{
  int val;
  struct node_t* leftchild;
  struct node_t* rightchild;
}node;

node* root;
int cnt = 0;
int sum = 0;

node* makenode(int v);
node* find(node* r, int v);
void makeroot();
void addleft(node* r, int u, int v);
void left();
void addright(node* r, int u, int v);
void right();
void pathsum(node* r, int v);
void path();

int main(){
  root = NULL;
  while(1){
    char cmd[101];
    scanf("%s",cmd);
    if(strcmp(cmd,"MakeRoot") == 0) makeroot();
    else if(strcmp(cmd,"AddLeft") == 0) left();
    else if(strcmp(cmd,"AddRight") == 0) right();
    else if(strcmp(cmd,"PathSum") == 0) path();
    else if(strcmp(cmd,"*") == 0) break;
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
  q->leftchild = NULL;
  q->rightchild = NULL;
  return q;
}
void makeroot(){
  int k;
  scanf("%d",&k);
  root = makenode(k);
}
node* find(node* r, int v){
  if(r == NULL) return NULL;
  if(r->val == v) return r;
  else {
  node* q = find(r->leftchild,v);
  if(q != NULL) return q;
  node* p = find(r->rightchild,v);
  if(p != NULL) return p;
  }
  return NULL;
}
void addleft(node* r, int u, int v){
  if(r == NULL) return; 
  node* q = find(r,v);
  if(q->leftchild != NULL) return;
  node* p = makenode(u);
  q->leftchild = p;
}
void left(){
  int u, v;
  scanf("%d%d",&u,&v);
  node* q = find(root,v);
  node* p = find(root,u);
  if(q == NULL) return;
  if(p != NULL) return;
  addleft(root,u,v);
}
void addright(node* r, int u, int v){
  if(r == NULL) return;
  node* q = find(r,v);
  if(q->rightchild != NULL) return;
  q->rightchild = makenode(u);
}
void right(){
  int u, v;
  scanf("%d%d",&u,&v);
  node* q = find(root,v);
  node* p = find(root,u);
  if(q == NULL) return;
  if(p != NULL) return;
  addright(root,u,v);
}
void pathsum(node* r, int v){
  if(r == NULL) return;
  sum += r->val;
  if((r->leftchild == NULL) && (r->rightchild == NULL) && (sum == v)){
    cnt += 1;
  } 
  else{
    pathsum(r->leftchild,v);
    pathsum(r->rightchild,v);
  }
  sum -= r->val;
}
void path(){
  int v;
  scanf("%d",&v);
  pathsum(root,v);
  if(cnt == 0){
    printf("False\n");
    return;
  }
  printf("True\n");
  cnt = 0;
}
