#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000003

typedef struct node_t{
  char v[N];
  int fre;
  struct node_t* leftchild;
  struct node_t* rightchild;
}node;

node* root;
char T[2*N];
int n;

void input();
node* makenode(char* s);
node* insert(node* r, char*s);
int check(char c);
void solve();
void inorder(node* r);

int main(){
  root = NULL;
  input();
  solve();
  inorder(root);
  return 0;
}

void input(){
  n = 0;
  while(!feof(stdin)){
    char c = fgetc(stdin);
    T[n] = c;
    n += 1;
  }
  T[n-1] = '\0';
}
node* makenode(char* s){
  node* q = (node*) malloc(sizeof(node));
  strcpy(q->v,s);
  q->fre = 1;
  q->leftchild = NULL;
  q->rightchild = NULL;
  return q;
}
node* insert(node* r, char*s){
  if(r == NULL) return makenode(s);
  int c = strcmp(r->v,s);
  if(c == 0) r->fre += 1;
  else if(c > 0) r->leftchild = insert(r->leftchild,s);
  else r->rightchild = insert(r->rightchild,s);
  return r;
} 
int check(char c){
  return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9');
}
void solve(){
  char word[30];
  int end = -1;
  for(int i = 0; i < n;i++){
    if(check(T[i])){
      end++;
      word[end] = T[i];
    }
    else {
      if(end != -1){
	word[end + 1] = '\0';
	root = insert(root,word);
      }
      end = -1;
    }
  }
}
void inorder(node* r){
  if(r == NULL) return;
  inorder(r->leftchild);
  printf("%s %d\n",r->v,r->fre);
  inorder(r->rightchild);
}
