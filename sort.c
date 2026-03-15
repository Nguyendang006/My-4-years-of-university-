#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100002

int m, n;
int cnt = 0;

void merge(int* a, int first, int mid, int last);
void mergesort(int* a, int first, int last);

int main(){
  scanf("%d%d",&m,&n);
  int* a1 = (int*) malloc(N * sizeof(int));
  int* a2 = (int*) malloc(N * sizeof(int));
  for(int i = 1;i <= n;i++)
    scanf("%d",&a1[i]);
  for(int i = 1;i <= m;i++)
    scanf("%d",&a2[i]);
  mergesort(a1,1,n);
  mergesort(a2,1,m);
  
  int* troa1 = (a1+1);
  int* troa2 = (a2+1);
  while(troa1 <= (a1+n) && troa2 <= (a2+m)){
    if((*troa1) < (*troa2))
      troa1++;
    else if((*troa1) > (*troa2))
      troa2++;
    else{
      troa1++;
      troa2++;
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}

void merge(int* a, int first, int mid, int last){
  int *tmp = (int*) malloc((last+first+2) * sizeof(int));
  int first1 = first;
  int last1 = mid;
  int first2 = mid+1;
  int last2 = last;
  int index = first;
  for(;first1 <= last1 && first2 <= last2;index++){
    if(a[first1] < a[first2]){
      tmp[index] = a[first1];
      first1++;
    } else {
      tmp[index] = a[first2];
      first2++;
    }
  }
  for(;first1 <= last1;first1++,index++){
    tmp[index] = a[first1];
  }
  for(;first2 <= last2;first2++,index++){
    tmp[index] = a[first2];
  }
  for(index = first;index <= last;index++)
    a[index] = tmp[index];
  free(tmp);
}
void mergesort(int* a, int first, int last){
  if(first < last){
    int mid = (first + last)/2;
    mergesort(a,first,mid);
    mergesort(a,mid+1,last);
    merge(a,first,mid,last);
  }
}
