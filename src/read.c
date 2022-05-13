#include <stdio.h>
#include <unistd.h>

#define COUNT 15

int main() {
  char buffer[COUNT + 1] = {0};
  int count = read(STDIN_FILENO, buffer, 15);
  printf("Input length is: %d\n", count);
  write(STDOUT_FILENO, buffer, count);
}
