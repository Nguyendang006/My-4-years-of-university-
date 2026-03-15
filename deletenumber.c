#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 120001

typedef struct node_t{
  char v;
  struct node_t* next;
}node;

node* head = NULL;

node* makenode(char v);
void push(char v);
char pop();
char che();
void print(node* head);
void solve(char* s, int num);

int main(){
  char s1[N];
  scanf("%s",s1);
  int k;
  scanf("%d",&k);
  solve(s1,k);
  return 0;
}

node* makenode(char v){
  node* q = (node*) malloc(sizeof(node));
  if(q == NULL){
    printf("failed\n");
    exit(1);
  }
  q->v = v;
  q->next = NULL;
  return q;
}
void push(char v){
  if(head == NULL){
    head = makenode(v);
    return;
  }
  node* q = makenode(v);
  q->next = head;
  head = q;
}
char pop(){
  if(head == NULL) return 0;
  node* tmp = head;
  char c = tmp->v;
  head = head->next;
  free(tmp);
  return c;
}
void print(node* h){
  if(h == NULL) return;
  print(h->next);
  printf("%c",h->v);
}
char che(){
  if(head == NULL) return 0;
  return head->v;
}
void solve(char* s, int num){
  int cnt = 0;
  for(int i = 0;i < strlen(s);i++){
    char c = s[i];
    while(head != NULL && num > 0 && head->v > c){
      pop();
      num--;
}
    push(c);
  }
  while(num > 0 && head != NULL){
    pop();
    num--;
  }
  print(head);
  printf("\n");
}
