#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100003

typedef struct point_t{
  int a;
  int b;
  struct point_t* next;
}doan;

void merge(doan* a, int first, int mid, int last);
void mergesort(doan* a, int first, int last);

int main(){
  int n;
  scanf("%d",&n);
  doan* f = (doan*) malloc((n+3) * sizeof(doan));
  for(int i = 1;i <= n;i++){
    scanf("%d%d",&f[i].a,&f[i].b);
  }
  mergesort(f,1,n);
  for(int i = 1;i <= n;i++){
    printf("%d ",f[i].b);
  }
  printf("\n");
  /*int cnt = 1;
  int end = f[1].b;
  for(int i = 2;i <= n;i++){
    if(f[i].a > end){
      cnt++;
      end = f[i].b;
    }
  }
  printf("%d\n",cnt);
  */
  free(f);
  return 0;
}

void merge(doan* a, int first, int mid, int last){
  doan* tmp = (doan*) malloc((N) * sizeof(doan));
  int first1 = first;
  int last1 = mid;
  int first2 = mid+1;
  int last2 = last;
  int index = first;
  for(;first1 <= last1 && first2 <= last2;index++){
    if(a[first1].b < a[first2].b){
      tmp[index] = a[first2];
      first2++;
    }
    else {
      tmp[index] = a[first1];
      first1++;
    }
  }
  for(;first1 <= last1;first1++,index++)
    tmp[index] = a[first1];
  for(;first2 <= last2;first2++,index++)
    tmp[index] = a[first2];
  for(index = first;index <= last;index++)
    a[index] = tmp[index];
  free(tmp);
}
void mergesort(doan* a, int first, int last){
  if(first < last){
    int mid = (first + last) / 2;
    mergesort(a,first,mid);
    mergesort(a,mid+1,last);
    merge(a,first,mid,last);
  }
}
