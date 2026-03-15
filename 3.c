#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10003

int findmax(int* a, int n);
int findmin(int* a, int n);
int sum(int* a, int n);
int maxseg(int* a, int l, int r, int n);
void promax(int* a, int n);

int main(){
  int* a = (int*) malloc(N * sizeof(int));
  int n;
  while(1){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
      scanf("%d",&a[i]);
    break;
  }
  char ch;
  scanf(" %c",&ch);
  while(1){
    char cmd[103];
    scanf("%s",cmd);
    if(strcmp(cmd,"***") == 0) break;
    else if(strcmp(cmd,"find-max") == 0) printf("%d\n",findmax(a,n));
    else if(strcmp(cmd,"find-min") == 0) printf("%d\n",findmin(a,n));
    else if(strcmp(cmd,"find-max-segment") == 0) promax(a,n);
    else if(strcmp(cmd,"sum") == 0) printf("%d\n",sum(a,n));
  }
  free(a);
  return 0;
}

int findmax(int* a, int n){
  int max = a[1];
  for(int i = 2;i <= n;i++)
    if(a[i] >= max) max = a[i];
  return max;
}
int findmin(int* a, int n){
  int min = a[1];
  for(int i = 2;i <= n;i++)
    if(a[i] <= min) min = a[i];
  return min;
}
int sum(int* a, int n){
  int sum = 0;
  for(int i = 1;i <= n;i++)
    sum += a[i];
  return sum;
}
int maxseg(int* a,int l, int r, int n){
  int max = a[l];
  for(int i = l+1;i <= r;i++)
    if(a[i] >= max) max = a[i];
  return max;
}
void promax(int* a, int n){
  int l;
  int r;
  scanf("%d%d",&l,&r);
  printf("%d\n",maxseg(a,l,r,n));
}
  
