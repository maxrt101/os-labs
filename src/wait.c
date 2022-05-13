#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t create_child(int n) {
  pid_t pid = fork();

  if (pid < 0) {
    fprintf(stderr, "[parent] Error occured during fork()\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    usleep(100);
    printf("[child#%d] Created with pid %d\n", n, getpid());
    printf("[child#%d] Parent pid is %d\n", n, getppid());
    exit(EXIT_SUCCESS);
  } else {
    printf("[parent] Parent has pid %d\n", getpid());
    printf("[parent] Child#%d created with pid %d\n", n, pid);
  }

  return pid;
}

void wait_for(pid_t pid, int n) {
  int status = 0, code = 0;
  waitpid(pid, &status, 0);

  if (WIFEXITED(status)) {
    code = WEXITSTATUS(status);
  }

  printf("[parent] Child#%d exited with code %d\n", n, code);
}

int main() {
  printf("[parent] Started with pid %d\n", getpid());

  pid_t child1 = create_child(1);
  pid_t child2 = create_child(2);

  wait_for(child1, 1);
  wait_for(child2, 2);

  printf("[parent] All child processes exited\n");
}
