#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 100001

typedef struct node_t{
  int smu;
  int hso;
  struct node_t* next;
}node;

node* P[N];

node* makenode(int hso, int smu);
node* addTerm(int hso, int smu, node* p);
void proterm(int id, int hso, int smu);
node* addPoly(node* p1, node* p2);
void proPoly(int id1, int id2, int idrs);
void proEvaluate(int id, int x);
void print(node* p);

int main(){
  while(1){
    char cmd[101];
    scanf("%s",cmd);
    if(strcmp(cmd,"AddTerm") == 0){
      int id, hso, smu;
      scanf("%d%d%d",&id,&hso,&smu);
      proterm(id,hso,smu);
    }
    else if(strcmp(cmd,"PrintPoly") == 0){
      int id;
      scanf("%d",&id);
      print(P[id]);
    }
    else if(strcmp(cmd,"AddPoly") == 0){
      int id1, id2, idrs;
      scanf("%d%d%d",&id1,&id2,&idrs);
      proPoly(id1,id2,idrs);
    }
    else if(strcmp(cmd,"EvaluatePoly") == 0){
      int id, x;
      scanf("%d%d",&id,&x);
      proEvaluate(id,x);
    }
    else if(strcmp(cmd,"*") == 0) break;
  }
  return 0;
}

node* makenode(int hso, int smu){
  node* q = (node*) malloc(sizeof(node));
  if(q == NULL){
    printf("failed\n");
    exit(1);
  }
  q->hso = hso;
  q->smu = smu;
  q->next = NULL;
  return q;
}
node* addTerm(int hso, int smu, node* p){
  if(p == NULL) return makenode(hso,smu);
  if(smu > p->smu){
    node* q = makenode(hso,smu);
    q->next = p;
    return q;
  }
  if(smu == p->smu){
    p->hso += hso;
    return p;
  }
  p->next = addTerm(hso,smu,p->next);
  return p;
}
void proterm(int id, int hso, int smu){
  P[id] = addTerm(hso,smu,P[id]);
}
node* addPoly(node* p1, node* p2){
  node* pp = NULL;
  node* last = pp;
  for(node* q = p1;q != NULL;q = q->next){
    node* p = makenode(q->hso,q->smu);
    if(pp == NULL) pp = p;
    else last->next = p;
    last = p;
  }
  for(node* q = p2;q != NULL;q = q->next){
    pp = addTerm(q->hso,q->smu,pp);
  }
  return pp;
}
void proPoly(int id1, int id2, int idrs){
  P[idrs] = addPoly(P[id1],P[id2]);
}
void proEvaluate(int id, int x){
  long long rs = 0;
  for(node* q = P[id];q != NULL;q = q->next){
    rs += q->hso * pow(x,q->smu);
  }
  printf("%lld\n",rs);
}
void print(node* p){
  for(node* q = p;q != NULL; q = q->next){
    printf("%d %d ",q->hso,q->smu);
  }
  printf("\n");
}
