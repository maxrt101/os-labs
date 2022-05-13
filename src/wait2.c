#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void print_child_info(int n) {
  printf("[child] Created with pid %d\n", getpid());
  printf("[child] Parent pid is %d\n", getppid());
}

pid_t create_child() {
  pid_t pid = fork();

  if (pid < 0) {
    fprintf(stderr, "[parent] Error occured during fork()\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    signal(SIGUSR1, print_child_info);
    pause();
    exit(EXIT_SUCCESS);
  } else {
    printf("[parent] Parent has pid %d\n", getpid());
    printf("[parent] Child created with pid %d\n", pid);
    usleep(500);
    kill(pid, SIGUSR1);
  }

  return pid;
}

void wait_for(pid_t pid) {
  int status = 0, code = 0;
  waitpid(pid, &status, 0);

  if (WIFEXITED(status)) {
    code = WEXITSTATUS(status);
  }

  printf("[parent] Child exited with code %d\n", code);
}

int main() {
  printf("[parent] Started with pid %d\n", getpid());

  pid_t child1 = create_child();

  wait_for(child1);
}
