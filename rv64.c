#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100003

typedef struct node_t{
  int val;
  struct node_t* leftchild;
  struct node_t* rightchild;
}node;

node* root;
int n;
node* makenode(int v);

int main(){
  scanf("%d",&n);
  int* a1 = (int*) malloc(N * sizeof(int));
  for(int i = 1;i <= n;i++){
    scanf("%d",&a1[i]);
    
