#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  pid_t p, p2;
  int sec;
  printf("%d about to create 2 child processes\n", getpid());
  (p = fork()) && (p2 = fork());
  if (p<0 || p2<0) {
    perror("error with forking");
    exit(1);
  }
  //child
  if (p==0 || p2==0) {
    srand(getpid());
    sec = rand() % 5 + 1;
    printf("%d %d sec\n", getpid(), sec);
    sleep(sec);
    printf("%d finished after %d sec\n", getpid(), sec);
    exit(sec);
    }
  //parent
  else {
    int status;
    pid_t n = wait(&status);
    if(WIFEXITED(status)) {
      printf("Main Process %d is done. Child %d slept for %d sec\n",
        getpid(), n, WEXITSTATUS(status));
    }
  }
  return 0;
}

