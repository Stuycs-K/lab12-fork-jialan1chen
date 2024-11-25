#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t p;
  p = fork();
  if (p<0) {
    perror("error with forking");
    exit(1);
  }
  if (p==0) {
    printf("%d %d sec", getpid())
    //child

  }
  else {
    printf("%d about to create 2 child processes", getpid());
    //parent
  }
}
