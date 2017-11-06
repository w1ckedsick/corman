#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include "inttypes.h"

#define MAX_SIZE 1000
int data[MAX_SIZE];

int main() {
  FILE* f_in = fopen("sort-input", "r");
  int N;
  fscanf(f_in, "%d", &N);
  for (int i = 0; i < N; ++i) {
    fscanf(f_in, "%d", &data[i]);
  }
  fclose(f_in);
  


  for (int i = 0; i < N; ++i) {
    printf("%d ", data[i]);
  }
  printf("\n");
}
