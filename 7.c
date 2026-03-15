#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10000

int main(){
  char s1[N];
  char s2[N];
  char T[N];

  fgets(s1,sizeof(s1),stdin);
  s1[strcspn(s1,"\n")] = '\0';
  fgets(s2,sizeof(s1),stdin);
  s2[strcspn(s2,"\n")] = '\0';
  fgets(T,sizeof(T),stdin);
  T[strcspn(T,"\n")] = '\0';

  char res[2 * N] = "";
  char* a = T;
  char* q;
  while((q = strstr(a,s1)) != NULL){
      strncat(res,a,q-a);
      strcat(res,s2);
      a = q + strlen(s1);
    }
    strcat(res,a);
    printf("%s\n",res);
    return 0;
}
