#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100003

void swap(int* a, int i, int j);
void heapify(int* a, int i, int n);
void buildheap(int* a, int n);
void heapsort(int* a, int n);

int main(){
  int n;
  scanf("%d",&n);
  int* a = (int*) malloc(N * sizeof(int));
  for(int i = 1;i <= n;i++){
    scanf("%d",&a[i]);
  }
  heapsort(a,n);
  for(int i = 1;i <= n;i++)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}

void swap(int* a, int i, int j){
  int x = a[i];
  a[i] = a[j];
  a[j] = x;
}
void heapify(int* a, int i, int n){
  int L = 2 * i;
  int R = 2 * i + 1;
  int maxindex = i;
  if(L < n && a[maxindex] < a[L])
    maxindex = L;
  if(R < n && a[maxindex] < a[R])
    maxindex = R;
  if(maxindex != i){
    swap(a,i,maxindex);
    heapify(a,maxindex,n);
  }
}
void buildheap(int* a, int n){
  for(int i = n/2 ;i >= 1;i--){
    heapify(a,i,n);
  }
}
void heapsort(int* a, int n){
  buildheap(a,n);
  for(int i = n;i >= 2;i--){
    swap(a,1,i);  
    heapify(a,1,i-1);
  }
}
