#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000003

typedef struct node_t{
  int value;
  int used;
  int chiso;
}node;

node* table[N] = {NULL};

int hash(int v);
int find(int v, int chiso);
void add(int v, int chiso);

int main(){
  int* a1 = (int*) malloc(N * sizeof(int));
  for(int i = 0;i < N;i++){
    table[i] = (node*) malloc(sizeof(node));
    table[i]->used = 0;
    table[i]->chiso = -1;
  }
  int n;
  scanf("%d",&n);
  for(int i = 1;i <= n;i++){
    scanf("%d",&a1[i]);
    add(a1[i],i);
  }
  for(int i = 1;i <= n;i++){
    printf("%d\n",find(a1[i],i));
  }
  return 0;
}
int hash(int v){
  return v % N;
} 
int find(int v, int chiso){
  int c = hash(v);
  while(table[c]->used){
    if(table[c]->value == v && table[c]->chiso < chiso)
      return 1;
    c = (c + 1) % N;
  }
  return 0;
}
void add(int v, int chiso){
  int c = hash(v);
  while(table[c]->used){
    c = (c + 1) % N;
  }
  table[c]->chiso = chiso;
  table[c]->value = v;
  table[c]->used = 1;
}

