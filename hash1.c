#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 201

int hashcode(char* v, int m);

int main(){
  int m,n;
  scanf("%d%d",&n,&m);
  char s[N];
  for(int i = 0;i < n;i++){
    scanf("%s",&s);
    int h = hashcode(s,m);
    printf("%d\n",h);
  }
  return 0;
}

int hashcode(char* v, int m){
  int c = 0;
  for(int i = 0;i < strlen(v);i++){
    c = (c*256 + v[i]) % m;
  }
  return c;
}
