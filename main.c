#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  pid_t p;
  pid_t p2;
  p = fork();
  if (p<0) {
    perror("error with forking");
    exit(1);
  }
  //child
  if (p==0 || p2==0) {
    srand(getpid());
    int sec = rand() % (5) + 1;
    printf("%d %d sec\n", getpid(), sec);
    sleep(sec);
    printf("%d finished after %d sec", getpid(), sec);
  }
  //parent
  else {
    printf("%d about to create 2 child processes\n", getpid());
    p2 = fork();
    int status;
    int n = wait(&status);
    if(WIFEXITED(status)) {
      printf("Main Process %d is done. Child %d slept for a sec\n",
        getpid(), n);
    }
  }
  return 0;
}
