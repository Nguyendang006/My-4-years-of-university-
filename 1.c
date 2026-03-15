#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10000

typdef struct node_t{
  char name[21];
  int prio;
  struct node_t* next;
}node;

int main(){
  scanf(
