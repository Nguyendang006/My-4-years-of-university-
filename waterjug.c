#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 901

typedef struct node_t{
  int x;
  int y;
  struct node_t* next;
}state;

typedef struct n{
  int x;
  int y;
}state1;

state* head1;
state* tail1;

int visited[N][N];
int level[N][N];
int ans = -1;

state* makenode(int x, int y);
void push(int x, int y);
state1 pop();
void init(int a, int b);
int goal(int x, int y, int c);
int filljug1(int x, int y, int a, int b, int c);
int filljug2(int x, int y, int a, int b, int c);
int emptyjug1(int x, int y, int a, int b, int c);
int emptyjug2(int x, int y, int a, int b, int c);
int pourjug1tojug2(int x, int y, int a, int b, int c);
int pourjug2tojug1(int x, int y, int a, int b, int c);
void solve(int a, int b, int c);

int main(){
  int a, b, c;
  tail1 = NULL;
  head1 = NULL;
  scanf("%d%d%d",&a,&b,&c);
  solve(a,b,c);
  return 0;
}

state* makenode(int x, int y){
  state* q = (state*) malloc(sizeof(state));
  if(q == NULL){
    printf("failed\n");
    exit(1);
  }
  q->x = x;
  q->y = y;
  q->next = NULL;
  return q;
}
void push(int x, int y){
  if(head1 == NULL){
    head1 = makenode(x,y);
    tail1 = head1;
    return;
  }
  state* q = makenode(x,y);
  tail1->next = q;
  tail1 = q;
}
state1 pop(){
  state* tmp = head1;
  head1 = head1->next;
  state1 a1;
  a1.x = tmp->x;
  a1.y = tmp->y;
  free(tmp);
  return a1;
}
void init(int a ,int b){
  for(int i = 0;i <= a ;i++)
    for(int j = 0;j <= b;j++){
      visited[i][j] = 0;
      level[i][j] = 0;
    }
}
int goal(int x, int y, int c){
  return x == c || y == c;
}
int filljug1(int x, int y, int a, int b, int c){
  if(goal(a,y,c)){
    ans = level[x][y] + 1;
    return 1;
  }
  if(visited[a][y]) return 0;
  push(a,y);
  visited[a][y] = 1;
  level[a][y] = level[x][y] + 1;
  return 0;
}
int filljug2(int x, int y, int a, int b, int c){
  if(goal(x,b,c)){
    ans = level[x][y] + 1;
    return 1;
  }
  if(visited[x][b]) return 0;
  push(x,b);
  visited[x][b] = 1;
  level[x][b] = level[x][y] + 1;
  return 0;
}
int emptyjug1(int x, int y, int a, int b, int c){
  if(goal(0,y,c)){
    ans = level[x][y] + 1;
    return 1;
  }
  if(visited[0][y]) return 0;
  push(0,y);
  visited[0][y] = 1;
  level[0][y] = level[x][y] + 1;
  return 0;
}
int emptyjug2(int x, int y, int a, int b, int c){
  if(goal(x,0,c)){
    ans = level[x][y] + 1;
    return 1;
  }
  if(visited[x][0]) return 0;
  push(x,0);
  visited[x][0] = 1;
  level[x][0] = level[x][y] + 1;
  return 0;
}
int pourjug1tojug2(int x, int y, int a, int b, int c){
  int nx, ny;
  if(x+y > b){
    nx = x+y-b;
    ny = b;
  }
  else{
    nx = 0;
    ny = x+y;
  }
  if(goal(nx,ny,c)){
    ans = level[x][y] + 1;
    return 1;
  }
  if(visited[nx][ny]) return 0;
  push(nx,ny);
  visited[nx][ny] = 1;
  level[nx][ny] = level[x][y] + 1;
  return 0;
}
int pourjug2tojug1(int x, int y, int a, int b, int c){
  int nx, ny;
  if(x + y > a){
    nx = a;
    ny = x+y-a;
  } else {
    nx = x+y;
    ny = 0;
  }
  if(goal(nx,ny,c)){
    ans = level[x][y] + 1;
    return 1;
  }
  if(visited[nx][ny]) return 0;
  push(nx,ny);
  visited[nx][ny] = 1;
  level[nx][ny] = level[x][y] + 1;
  return 0;
}
void solve(int a, int b, int c){
  init(a,b);
  push(0,0);
  level[0][0] = 0;
  visited[0][0] = 1;
  while(head1 != NULL){
    state1 a1 = pop();
    int x = a1.x;
    int y = a1.y;
    if(filljug1(x,y,a,b,c)) break;
    if(filljug2(x,y,a,b,c)) break;
    if(emptyjug1(x,y,a,b,c)) break;
    if(emptyjug2(x,y,a,b,c)) break;
    if(pourjug1tojug2(x,y,a,b,c)) break;
    if(pourjug2tojug1(x,y,a,b,c)) break;
  }
  printf("%d\n",ans);
}
  
