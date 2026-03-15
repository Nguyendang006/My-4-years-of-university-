#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000001

typedef struct node_t{
  char word[21];
  int occ;
  struct node_t* leftchild;
  struct node_t* rightchild;
}node;

node* root;
char T[N];
int n;

void input();
node* makenode(char* w);
node* insert(node* r, char* w);
int check(char c);
void inOrder(node* r);
void solve();

int main(){
  input();
  solve();
  inOrder(root);
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
node* makenode(char* w){
  node* p = (node*) malloc(sizeof(node));
  if(p == NULL){
    printf("failed\n");
    exit(1);
  }
  strcpy(p->word,w);
  p->occ = 1;
  p->leftchild = NULL;
  p->rightchild = NULL;
  return p;
}
node* insert(node* r, char* w){
  if(r == NULL) return makenode(w);
  int tmp = strcmp(r->word,w);
  if(tmp == 0){
    r->occ += 1;
    return r;
  }
  if(tmp < 0) r->rightchild = insert(r->rightchild,w);
  else r->leftchild = insert(r->leftchild,w);
  return r;
}
int check(char c){
  return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9');
}
void inOrder(node* r){
  if(r == NULL) return;
  inOrder(r->leftchild);
  printf("%s %d\n",r->word,r->occ);
  inOrder(r->rightchild);
}
void solve(){
  root = NULL;
  char word[30];
  int end = -1;
  for(int i = 0;i < n;i++){
  if(check(T[i])){
    end++;
    word[end] = T[i];
  }
  else{
    if(end != -1){
    word[end+1] = '\0';
    root = insert(root,word);
  }
  end = -1;
  }
  }
}
