#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 1000

int main(){
  char text[N];
  while(fgets(text,sizeof(text),stdin) != NULL){
    for(int i = 0;i < strlen(text);i++)
      text[i] = toupper(text[i]);
    printf("%s",text);
  }
  return 0;
}
    
