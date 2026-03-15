#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000001

typedef struct node_t{
  char c;
  struct node_t* next;
}node;

node* head;
char str[N];

node* makenode(char v);
void push(char v);
char pop();
int check(char* s);
int match(char c1, char c2);

int main(){
  scanf("%s",str);
  int ans = check(str);
  printf("%d\n",ans);
  return 0;
}

node* makenode(char v){
  node* q = (node*) malloc(sizeof(node));
  if(q == NULL){
    printf("failed\n");
    exit(1);
  }
  q->c = v;
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
  if(head == NULL) return '0';
  node* tmp = head;
  head = head->next;
  char c = tmp->c;
  free(tmp);
  return c;
}
int check(char* s){
  for(int i = 0;i < strlen(s);i++){
    if(s[i] == '(' || s[i] == '{' || s[i] == '['){
      push(s[i]);
    }
    else{
      if(head == NULL) return 0;
      char c = pop();
      if(!match(c,s[i])) return 0;
    }
  }
  return head == NULL;
}
int match(char c1, char c2){
  if( c1 == '(' && c2 == ')') return 1;
  if( c1 == '{' && c2 == '}') return 1;
  if( c1 == '[' && c2 == ']') return 1;
  return 0;
}
	      

