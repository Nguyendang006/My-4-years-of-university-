#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000001

typedef struct node_t{
  int val;
  struct node_t* next;
}node;

node* head;

node* makenode(int k);
node* find(node* h, int k);
node* addlast(node* h, int k);
void prolast();
node* addfirst(node* h, int k);
void profirst();
node* addbefore(node* h, int u, int v);
void profore();
node* addafter(node* h, int u, int v);
void proafter();
node* remove1(node* h, int k);
void promove();
node* reverse(node* h);
void proverse();

int main(){
  head = NULL;
  int n;
  scanf("%d",&n);
  for(int i = 0;i < n;i++){
    int k;
    scanf("%d",&k);
    head = addlast(head,k);
  }
  while(1){
    char cmd[101];
    scanf("%100s",cmd);
    if(strcmp(cmd,"#") == 0) break;
    else if(strcmp(cmd,"addlast") == 0) prolast();
    else if(strcmp(cmd,"addfirst") == 0) profirst();
    else if(strcmp(cmd,"addafter") == 0) proafter();
    else if(strcmp(cmd,"remove") == 0) promove();
    else if(strcmp(cmd,"addbefore") == 0) profore();
    else if(strcmp(cmd,"reverse") == 0) proverse();
  }
  for(node* p = head;p != NULL;p = p->next){
    printf("%d ",p->val);
  }
  printf("\n");
  return 0;
}


node* makenode(int k){
  node* q = (node*) malloc(sizeof(node));
  if(q == NULL){
    printf("failed\n");
    exit(1);
  }
  q->val = k;
  q->next = NULL;
  return q;
}
node* find(node* h, int k){
  while(h != NULL){
    if(h->val == k) return h;
    h = h->next;
  }
  return NULL;
}
node* addlast(node* h, int k){
  if(h == NULL) return makenode(k);
  h->next = addlast(h->next,k);
  return h;
}
void prolast(){
  int k;
  scanf("%d",&k);
  node* q = find(head,k);
  if(q != NULL) return;
  head = addlast(head,k);
}
node* addfirst(node* h, int k){
  if(h == NULL) return makenode(k);
  node* q = makenode(k);
  q->next = h;
  return q;
}
void profirst(){
  int k;
  scanf("%d",&k);
  node* q = find(head,k);
  if(q != NULL) return;
  head = addfirst(head,k);
}
node* addbefore(node* h, int u, int v){
  if(h == NULL) return NULL;
  if(h->val == v){
    node* q = makenode(u);
    q->next = h;
    return q;
  }
  h->next = addbefore(h->next,u,v);
  return h;
}   
void profore(){
  int u, v;
  scanf("%d%d",&u,&v);
  node* q = find(head,v);
  if(q == NULL) return;
  node* p = find(head,u);
  if(p != NULL) return;
  head = addbefore(head,u,v);
}
node* addafter(node* h, int u, int v){
  if(h == NULL) return NULL;
  if(h->val == v){
    node* q = makenode(u);
    q->next = h->next;
    h->next = q;
    return h;
  }
  h->next = addafter(h->next,u,v);
  return h;
}
void proafter(){
  int u, v;
  scanf("%d%d",&u,&v);
  node* q = find(head,v);
  if(q == NULL) return;
  node* p = find(head,u);
  if(p != NULL) return;
  head = addafter(head,u,v);
}
node* remove1(node* h, int k){
  if(h == NULL) return NULL;
  if(h->val == k){
    node* tmp = h;
    h = h->next;
    free(tmp);
    return h;
  }
  h->next = remove1(h->next,k);
  return h;
}
void promove(){
  int k;
  scanf("%d",&k);
  head = remove1(head,k);
}
node* reverse(node* h){
  node* pp = NULL;
  node* p = h;
  node* fp = NULL;
  while(p != NULL){
    fp = p->next;
    p->next = pp;
    pp = p;
    p = fp;
  }
  return pp;
}
void proverse(){
  head = reverse(head);
}
