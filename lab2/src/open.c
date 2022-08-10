#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char ** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s FILE CONTENT\n", argv[0]);
    return 1;
  }

  int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRGRP);
  write(fd, argv[2], strlen(argv[2]));
  close(fd);
}
