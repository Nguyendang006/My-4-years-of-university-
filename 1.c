#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10000

int main(){
  char a[26];
  char b[26];
  scanf("%s %s",a,b);
  
  char sum[26];
  int i = strlen(a) - 1;
  int j = strlen(b) - 1;
  int cary = 0;
  int k = 0;

  while(i >= 0 || j >= 0 || cary){
    int a1 = i >= 0 ? a[i] - '0' : 0;
    int b1 = j >= 0 ? b[j] - '0' : 0;
    int adder = cary + a1 + b1;
    int tong = adder % 10;
    cary = adder / 10;
    sum[k] = tong;
    i--;
    j--;
    k++;
  }
  for(int i = k-1;i >= 0;i--)
    printf("%d",sum[i]);
  return 0;
}
