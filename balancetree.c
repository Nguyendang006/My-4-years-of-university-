#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 50001

typedef struct node_t{
  int val;
  struct node_t* leftchild;
  struct node_t* rightchild;
}node;

node* root;
node* hashmap[N];

node* makenode(int v);
node* find(node* r, int v);
node* find1(int v);
void makeroot();
void addleft(node* r, int u, int v);
void left();
void addright(node* r, int u, int v);
void right();
int height(node* r);
int balance1(node* r, int *h1);

int main(){
  root = NULL;
  while(1){
    char cmd[100];
    scanf("%s",cmd);
    if(strcmp(cmd,"MakeRoot") == 0) makeroot();
    else if(strcmp(cmd,"AddRight") == 0) right();
    else if(strcmp(cmd,"AddLeft") == 0) left();
    else if(strcmp(cmd,"*") == 0) break;
  }
  int h1 = 0;
  int h = height(root);
  int z = balance1(root,&h);
  printf("%d %d\n",z,h);
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
  hashmap[v] = q;
  return q;
}
void makeroot(){
  int v;
  scanf("%d",&v);
  root = makenode(v);
}
node* find(node* r, int v){
  if(r == NULL) return NULL;
  if(r->val == v) return r;
  node* q = find(r->leftchild,v);
  if(q != NULL) return q;
  node* p = find(r->rightchild,v);
  if(p != NULL) return p;
  return NULL;
}
node* find1(int v){
  return hashmap[v];
}
void addleft(node* r,int u, int v){
  node* q = find1(v);
  if(q->leftchild != NULL) return;
  node* p = makenode(u);
  q->leftchild = p;
}
void left(){
  int u, v;
  scanf("%d%d",&u,&v);
  node* q = find1(v);
  node* p = find1(u);
  if(q == NULL) return;
  if(p != NULL) return;
  addleft(root,u,v);
}
void addright(node* r, int u, int v){
  node* q = find1(v);
  if(q->rightchild != NULL) return;
  node* p = makenode(u);
  q->rightchild = p;
}
void right(){
  int u, v;
  scanf("%d%d",&u,&v);
  node* q = find1(v);
  node* p = find1(u);
  if(q == NULL) return;
  if(p != NULL) return;
  addright(root,u,v);
}
int height(node* r){
  if(r == NULL) return 0;
  int maxh = 0;
  maxh = height(r->leftchild) + 1;
  int h = height(r->rightchild) + 1;
  return (maxh > h ? maxh : h);
}
int balance1(node* r, int* h){
  if(r == NULL){
    *h = 0;
    return 1;
  }
  int hl, hr;
  if(!balance1(r->leftchild,&hl)) return 0;
  if(!balance1(r->rightchild,&hr)) return 0;
  *h = (hl > hr ? hl : hr) + 1;
  return (abs(hl - hr) <= 1);
}
