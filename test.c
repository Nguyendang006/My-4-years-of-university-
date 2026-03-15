#include <stdio.h>
#include <stdlib.h>

void insertionSort(int a[],int n);

int main(){
  int n;
  scanf("%d",&n);
  int* a = (int*) malloc(n * sizeof(int));
  for(int i = 1;i <= n;i++){
    scanf("%d",&a[i]);
  }
  insertionSort(a,n);
  for(int i = 1;i <= n;i++)
    printf("%d ",a[i]);
  return 0;
}

void insertionSort(int a[],int n){
  int i, j, last;
  for(i = 1;i <= n;i++){
    last = a[i];
    j = i;
    while((j > 0) && (a[j-1] > last)){
      a[j] = a[j-1];
      j = j - 1;
    }
    a[j] = last;
  }
}
