#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main() {
  struct timespec start, end;
  clock_gettime(CLOCK_REALTIME, &start);

  int size = 100000000;
  char* stringBuffer = malloc(size);
  if (stringBuffer == NULL) {
      printf("Memory allocation failed.\n");
      return 1;
    }
    
  memset(stringBuffer, 'a', size);


  printf("%s\n", stringBuffer);
  clock_gettime(CLOCK_REALTIME, &end);
  double time_taken = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Printing time: %f seconds\n", time_taken);
  free(stringBuffer);
  return 0;
}