#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include "inttypes.h"

#define MAX_SIZE 1000
int data[MAX_SIZE];

void Merge(int* array, int left, int mid, int right) {
  int LEFT[MAX_SIZE];
  int RIGHT[MAX_SIZE];
  int left_iter = 0;
  int right_iter = 0;
  int left_size = mid - left;
  int right_size = right - mid + 1;
  for (int i = left; i < mid; ++i) {
    LEFT[left_iter++] = array[i];
  }
  for (int i = mid; i <= right; ++i) {
    RIGHT[right_iter++] = array[i];
  }

  left_iter = 0;
  right_iter = 0;
  for (int i = left; i <= right; ++i) {
    if (left_iter == left_size) {
      array[i] = RIGHT[right_iter++];
    }
    else if (right_iter == right_size) {
      array[i] = LEFT[left_iter++];
    }
    else if (RIGHT[right_iter] < LEFT[left_iter]) {
      array[i] = RIGHT[right_iter++];
    }
    else {
      array[i] = LEFT[left_iter++];
    }
  }
}

void MergeSort(int* array, int left, int right) {
  if (left < right) {
    int mid = (right - left) / 2 + left;
    MergeSort(array, left, mid);
    MergeSort(array, mid + 1, right);
    Merge(array, left, mid + 1, right);
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
  
  MergeSort(data, 0, N - 1);

  for (int i = 0; i < N; ++i) {
    printf("%d ", data[i]);
  }
  printf("\n");
}
