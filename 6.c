#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 10000

int main(){
  double a;
  scanf("%lf",&a);
  int b = (int)floor(a);
  double c = (double)b - a;
  if(c < 0) c = -c;
  printf("%d %.2lf\n",b,c);
  return 0;
}
