#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s FILE\n", argv[0]);
    return 1;
  }

  pid_t pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Error occured during fork()\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {

    int fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd == -1) {
      fprintf(stderr, "Failed to open file %s\n", argv[1]);
      return 1;
    }
    close(fd);

    exit(EXIT_SUCCESS);
  }

  int status = 0, code = 0;
  waitpid(pid, &status, 0);

  if (WIFEXITED(status)) {
    code = WEXITSTATUS(status);
    if (code != 0) {
      fprintf(stderr, "Child process failed\n");
      return 1;
    }
  }

  printf("[parent] Child exited with code %d\n", code);
  printf("Please enter file contents:\n");

  int fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
  if (fd == -1) {
    fprintf(stderr, "Failed to open file %s\n", argv[1]);
    return 1;
  }

  int c = 0;
  while (read(STDIN_FILENO, &c, 1) != 0 && c != '\n') {
    write(fd, &c, 1);
  }

  close(fd);
  return 0;
}
