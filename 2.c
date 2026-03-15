#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10002

int main(){
  int T;
  scanf("%d",&T);
  for(int i = 1;i <= T;i++){
    int n, m;
    int a[N];
    int b[N];
    scanf("%d%d",&n,&m);
    for(int j = 1;j <= n;j++)
      scanf("%d",&a[j]);
    for(int k = 1;k <= m;k++)
      scanf("%d",&b[k]);
    if(n > m || n < m){
      printf("0\n");
      continue;
    } else {
      int cnt;
      for(int i = 1;i <= n;i++){
	if(a[i] != b[i]){
	  cnt = 0;
	  break;
	} else { cnt = 1;}
      }
      if(cnt != 0) printf("1\n");
      else printf("0\n");
    }
  }
  return 0;
}
