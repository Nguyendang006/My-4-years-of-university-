#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10001

typedef struct info{
  char cu[11];
  char proid[11];
  int price;
  char shoid[11];
  char time[9];
}ttin;

typedef struct cuXsho{
  char c[100];
  int revenue;
  struct cuXsho* next;
}cushop;

cushop* a2[N] = {NULL};

typedef struct shop_t{
  char c[100];
  int revenue;
  struct shop_t* next;
}shop;

shop* a3[N] = {NULL};

ttin* ttin1;
int cnt = 0;
int total = 0;

cushop* makecushop(char* a, int v);
shop* makeshop(char* a, int v);
char* kethop(char* s1, char* s2);
int hashshop(char* s);
int hashcushop(char* s);
void insert1(char* s, int gia);
void insert2(char* s1, char* s2, int gia);
void pronumor();
void prore();
void proshopre();
void procu();
void proper();
void merge(ttin* a,int first, int mid, int last);
void mergesort(ttin* a, int first, int last);

int main(){
  ttin1 = (ttin*) malloc(N * sizeof(ttin));
  while(1){
    char cmd[100];
    fgets(cmd,sizeof(cmd),stdin);
    cmd[strcspn(cmd,"\n")] = '\0';
    if(strcmp(cmd,"#") == 0) break;
    sscanf(cmd,"%s %s %d %s %s",ttin1[cnt].cu,ttin1[cnt].proid,&ttin1[cnt].price,ttin1[cnt].shoid,ttin1[cnt].time);
    insert1(ttin1[cnt].shoid,ttin1[cnt].price);
    insert2(ttin1[cnt].cu,ttin1[cnt].shoid,ttin1[cnt].price);
    total += ttin1[cnt].price;
    cnt++;
  }
  while(1){
    char cmd[100];
    scanf("%s",cmd);
    if(strcmp(cmd,"#") == 0) break;
    else if(strcmp(cmd,"?total_number_orders") == 0) pronumor();
    else if(strcmp(cmd,"?total_revenue") == 0) prore();
    else if(strcmp(cmd,"?revenue_of_shop") == 0) proshopre();
    else if(strcmp(cmd,"?total_consume_of_customer_shop") == 0) procu();
    else if(strcmp(cmd,"?total_revenue_in_period") == 0) proper();
  }
  return 0;
}

cushop* makecushop(char* a, int v){
  cushop* q = (cushop*) malloc(sizeof(cushop));
  strcpy(q->c,a);
  q->revenue = v;
  q->next = NULL;
  return q;
}
shop* makeshop(char* a, int v){
  shop* q = (shop*) malloc(sizeof(shop));
  strcpy(q->c,a);
  q->revenue = v;
  q->next = NULL;
  return q;
}
void pronumor(){
  printf("%d\n",cnt);
}
void prore(){
  printf("%d\n",total);
}

char* kethop(char* s1, char* s2){
  char* e = (char*) malloc((strlen(s1) + strlen(s2) + 2) * sizeof(char));
  strcpy(e,s1);
  strcat(e,"+");
  strcat(e,s2);
  return e;
}
int hashshop(char* s){
  int c = 0;
  for(int i = 0;i < strlen(s);i++){
    c = (c * 256 + s[i]) % N;
  }
  return c;
}
int hashcushop(char* s){
  int c = 0;
  for(int i = 0;i < strlen(s);i++){
    c = (c * 256 + s[i]) % N;
  }
  return c;
}
void insert1(char* s, int gia){
  int c = hashshop(s);
  if(a3[c] == NULL){
    a3[c] = makeshop(s,gia);
    return;
  }
  a3[c]->revenue += gia;
} 
void insert2(char* s1, char* s2, int gia){
  char* s = kethop(s1,s2);
  int c = hashcushop(s);
  if(a2[c] == NULL){
    a2[c] = makecushop(s,gia);
    return;
  }
  a2[c]->revenue += gia;
}
void proshopre(){
  char c1[100];
  scanf("%s",c1);
  int c = hashshop(c1);
  if(a3[c] == NULL){
    printf("0\n");
    return;
  }
  printf("%d\n",a3[c]->revenue);
}
void procu(){
  char c1[100], c2[100];
  scanf("%s %s",c1,c2);
  char* l = kethop(c1,c2);
  int c = hashcushop(l);
  if(a2[c] == NULL){
    printf("0\n");
    return;
  }
  printf("%d\n",a2[c]->revenue);
}
void proper(){
  char time1[100], time2[100];
  int sum = 0;
  scanf("%s %s",time1,time2);
  for(int i = 0;i < cnt;i++)
    if(strcmp(ttin1[i].time,time1) >= 0 && strcmp(ttin1[i].time,time2) <= 0)
      sum += ttin1[i].price;
  printf("%d\n",sum);
}
void merge(ttin* a,int first, int mid, int last);
void mergesort(ttin* a, int first, int last);

