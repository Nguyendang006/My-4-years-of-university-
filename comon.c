#include <stdio.h>
#include <stdlib.h>
#define N 10003

int max1(int a, int b){
  return a > b ? a : b;
}

int main(){
  int n, m;
  scanf("%d%d",&n,&m);
  int* x = (int*) malloc((n+1) * sizeof(int));
  int* y = (int*) malloc((m+1) * sizeof(int));

  for(int i = 1;i <=n;i++){
    scanf("%d",&x[i]);
  }
  for(int i = 1;i <= m;i++){
    scanf("%d",&y[i]);
  }

  int **length = (int**) malloc((n+1) * sizeof(int*));
  for(int i = 0;i <= n;i++)
    length[i] = (int*) malloc((m+1) * sizeof(int));
  for(int i = 0;i <= n;i++)
    length[i][0] = 0;
  for(int j = 0;j <= m;j++)
    length[0][j] = 0;

  for(int i = 1;i <= n;i++)
    for(int j = 1;j <= m;j++){
      if(x[i] == y[j]) length[i][j] = length[i-1][j-1] + 1;
      else length[i][j] = max1(length[i][j-1],length[i-1][j]);
    }
  printf("%d\n",length[n][m]);
  return 0;
}

  
