#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000

int main(){
  char str[N];
  int cnt = 0;
  while(scanf("%s",str) != EOF)
    cnt += 1;
  printf("%d\n",cnt);
  return 0;
}
