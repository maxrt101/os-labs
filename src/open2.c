#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define READ_COUNT 8

int main(int argc, char ** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s INFILE OUTFILE\n", argv[0]);
    return 1;
  }

  int ret = 0;

  int infd = open(argv[1], O_RDONLY);
  if (infd == -1) {
    fprintf(stderr, "Failed to open %s (should exist)\n", argv[1]);
    return 1;
  }

  int outfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRGRP);
  if (infd == -1) {
    fprintf(stderr, "Failed to open %s\n", argv[2]);
    return 1;
  }

  char buffer[READ_COUNT + 1] = {0};

  if (read(infd, buffer, READ_COUNT) != READ_COUNT) {
    fprintf(stderr, "Failed to read %d chars from %s\n", READ_COUNT, argv[1]);
    ret = 1;
    goto end;
  }

  if (write(outfd, buffer, READ_COUNT) == -1) {
    fprintf(stderr, "Failed to write %d chars to %s\n", READ_COUNT, argv[2]);
    ret = 1;
  }

end:
  close(infd);
  close(outfd);
  return ret;
}
