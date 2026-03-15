#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000003

int max1(int a, int b){
  return a > b ? a : b;
}

int main(){
  int n;
  scanf("%d",&n);
  int* a = (int*) malloc(N * sizeof(int));
  for(int i = 1;i <= n;i++){
    scanf("%d",&a[i]);
  }
  int cursum = a[1];
  int lastsum = a[1];
  for(int i = 2;i <= n;i++){
    cursum = max1(cursum + a[i],a[i]);
    lastsum = max1(lastsum,cursum);
  }
  printf("%d\n",cursum);
  return 0;
}
