#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000

typedef struct node_t{
  int val;
  struct node_t* leftchild;
  struct node_t* rightsibling;
}node;

node* root;

node* makenode(int v);
node* find(node* r, int v);
void insert(node* r, int u, int v);
void proinsert();
void preorder(node* r);
void propreorder();
void inorder(node* r);
void proinorder();
void postorder(node* r);
void propostorder();
void makeroot();

int main(){
  root = NULL;
  while(1){
    char cmd[100];
    scanf("%s",cmd);
    if(strcmp(cmd,"*") == 0) break;
    else if(strcmp(cmd,"Insert") == 0) proinsert();
    else if(strcmp(cmd,"PreOrder") == 0) propreorder();
    else if(strcmp(cmd,"InOrder") == 0) proinorder();
    else if(strcmp(cmd,"PostOrder") == 0) propostorder();
    else if(strcmp(cmd,"MakeRoot") == 0) makeroot();
    else if(strcmp(cmd,"find1") == 0){
      int v; scanf("%d",&v);
      node* q = find(root,v);
      if(q == NULL) printf("0\n");
      else printf("1\n");
    }
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
  q->rightsibling = NULL;
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
  node* q = r->leftchild;
  while(q != NULL){
    node* p = find(q,v);
    if(p != NULL) return p;
    q = q->rightsibling;
  }
  return NULL;
}
void insert(node* r, int u, int v){
  node* q = makenode(u);
  node* p = find(r,v);
  node* tmp = p->leftchild;
  if(tmp == NULL){
    p->leftchild = q;
    return;
  }
  while(tmp->rightsibling != NULL)
    tmp = tmp->rightsibling;
  tmp->rightsibling = q;
}
void proinsert(){
  int u, v;
  scanf("%d%d",&u,&v);
  node* q = find(root,u);
  node* p = find(root,v);
  if(q != NULL) return;
  if(p == NULL) return;
  insert(root,u,v);
}
void preorder(node* r){
  if(r == NULL) return;
  printf("%d ",r->val);
  node* q = r->leftchild;
  while(q != NULL){
    preorder(q);
    q = q->rightsibling;
  }
}
void propreorder(){
  preorder(root);
  printf("\n");
}
void inorder(node* r){
  if(r == NULL) return;
  node* q = r->leftchild;
  inorder(q);
  printf("%d ",r->val);
  while(q != NULL){
    q = q->rightsibling;
    inorder(q);
  }
}
void proinorder(){
  inorder(root);
  printf("\n");
}
void postorder(node* r){
  if(r == NULL) return;
  node* q = r->leftchild;
  while(q != NULL){
    postorder(q);
    q = q->rightsibling;
  }
  printf("%d ",r->val);
}
void propostorder(){
  postorder(root);
  printf("\n");
}

