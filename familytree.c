#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 100
#define N 10001

typedef struct node_t{
  char name[LEN];
  struct node_t* leftchild;
  struct node_t* rightsibling;
}node;

node* nodes[N] = {NULL};
int n;

node* find(char* name);
node* addnode(char* name);
void makechildpa(node* child,node* parent);
int height(node* r);
int count(node* r);
void buildTree();
void menu();

int main(){
  buildTree();
  menu();
  return 0;
}

node* find(char* name){
  for(int i = 0;i < n;i++){
    if(strcmp(name,nodes[i]->name) == 0)
      return nodes[i];
  }
  return NULL;
}
node* addnode(char* name){
  node* p = (node*) malloc(sizeof(node));
  strcpy(p->name,name);
  p->leftchild = NULL;
  p->rightsibling = NULL;
  nodes[n] = p;
  n++;
  return p;
}
void makechildpa(node* child,node* parent){
  child->rightsibling = parent->leftchild;
  parent->leftchild = child;
}

void buildTree(){
  while(1){
    char childname[LEN];
    char parentname[LEN]; 

    scanf("%s",childname);
    if(strcmp(childname,"***") == 0) break;
    scanf("%s",parentname);

    node* nodechild = find(childname);
    if(nodechild == NULL)
      nodechild = addnode(childname);
    node* nodeparent = find(parentname);
    if(nodeparent == NULL)
      nodeparent = addnode(parentname);
    
    makechildpa(nodechild,nodeparent);
  }
}     
void menu(){
  while(1){
    char cmd[LEN];
    char name[LEN];

    scanf("%s",cmd);
    if(strcmp(cmd,"***") == 0) break;
    else if(strcmp(cmd,"descendants") == 0){
      scanf("%s",name);
      node* p = find(name);
      int res = count(p) - 1;
      printf("%d\n",res);
    }
    else if(strcmp(cmd,"generation") == 0){
      scanf("%s",name);
      node* p = find(name);
      int res = height(p) - 1;
      printf("%d\n",res);
    }
  }
}
int count(node* r){
  if(r == NULL) return 0;
  int c = 1;
  for(node* p = r->leftchild;p != NULL;p = p->rightsibling)
    c += count(p);
  return c;
}
int height(node* r){
  if(r == NULL) return 0;
  int maxh = 0;
  for(node* p = r->leftchild;p != NULL;p = p->rightsibling){
    int h = height(p);
    if(maxh < h) maxh = h;
  }
  return maxh + 1;
}
  
