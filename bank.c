#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200003

typedef struct node_t{
  char account[21];
  int money;
  int used;
}taikhoan;

typedef struct chuyen{
  char account1[21];
  char account2[21];
  int money;
  char time[9];
  char atm[11];
}chuyentien;

int hash(char* a);
void add(taikhoan* a, char* account, int money);
int get(taikhoan* a, char* account);
void tien(taikhoan* a);

int main(){
  int i = 0;
  taikhoan* a = (taikhoan*) malloc(N * sizeof(taikhoan));
  chuyentien* b = (chuyentien*) malloc(N * sizeof(chuyentien));
  while(1){
    char cmd[103];
    fgets(cmd,sizeof(cmd),stdin);
    cmd[strcspn(cmd,"\n")] = '\0';
    if(strcmp(cmd,"#") == 0) break;
    sscanf(cmd,"%20s %20s %d %8s %10s",b[i].account1,b[i].account2,&b[i].money,b[i].time,b[i].atm);
    add(a,b[i].account1,b[i].money);
    i++;
  }
  while(1){
    char cmd[103];
    scanf("%s",cmd);
    if(strcmp(cmd,"?total_money_transaction_from") == 0) tien(a);
    else if(strcmp(cmd,"#") == 0) break;
  }
  return 0;
}

int hash(char* a){
  int c = 0;
  for(int i = 0;i < strlen(a);i++)
    c = (c * 256 + a[i]) % N;
  return c;
}
void add(taikhoan* a, char* account,int money){
  int c = hash(account);
  while(a[c].used && (strcmp(a[c].account,account)) != 0)
      c = (c + 1) % N;
  if(!a[c].used){
    a[c].used = 1;
    strcpy(a[c].account,account);
    a[c].money = money;
  } else a[c].money += money;
}   
int get(taikhoan* a, char* account){
  int c = hash(account);
  while(a[c].used){
    if(strcmp(a[c].account,account) == 0)
      return a[c].money;
    c = (c + 1) % N;
  }
  return 0;
}
void tien(taikhoan* a){
  char account[21];
  scanf("%s",account);
  int c = get(a,account);
  printf("%d\n",c);
}
