#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  char s1[100];
  char s2[100];
  
  fgets(s1,sizeof(s1),stdin);
  s1[strcspn(s1,"\n")] = '\0';
  fgets(s2,sizeof(s2),stdin);
  s1[strcspn(s2,"\n")] = '\0';
  char s3[100] = "hello\t";
  char s4[] = "world";

  strcat(s1,s2);
  printf("%s\n",s1);
  return 0;
}
  
