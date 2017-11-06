#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include "inttypes.h"

#define MAX_SIZE 1000
int data[MAX_SIZE];

static inline void Swap(int* array, int a, int b) {
  register int tmp;
  tmp = array[b];
  array[b] = array[a];
  array[a] = tmp;
}

int Partition(int* array, int left, int right) {
  int pivot = array[right];
  int sorted_tail = left;
  for (int i = left; i < right; ++i) {
    if (array[i] < pivot) {
      // Add it into a sorted part
      Swap(array, sorted_tail, i);
      sorted_tail++;
    }
  }
  Swap(array, sorted_tail, right);
  return sorted_tail;
}

void QuickSort(int* array, int left, int right) {
  if (left < right) {
    int pivot_idx = Partition(array, left, right);
    printf("%d\n", pivot_idx);
    QuickSort(array, left, pivot_idx - 1);
    QuickSort(array, pivot_idx + 1, right);
  }
}

int main() {
  FILE* f_in = fopen("sort-input", "r");
  int N;
  fscanf(f_in, "%d", &N);
  for (int i = 0; i < N; ++i) {
    fscanf(f_in, "%d", &data[i]);
  }
  fclose(f_in);
  
  QuickSort(data, 0, N-1);

  for (int i = 0; i < N; ++i) {
    printf("%d ", data[i]);
  }
  printf("\n");
}
