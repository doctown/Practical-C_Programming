#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *stack;

void push (int data) {
  if (stack == NULL) {
    stack = calloc(0, sizeof(struct Node));
    (*stack).data = data;
    (*stack).next = NULL;
  } else {
    (*stack).next = malloc(sizeof(struct Node)); 
  }
}

int main(int argc, char *argv[]) {
  int fd;

  int flags = O_WRONLY | O_CREAT;

  fd = open("temporary", flags);
  if (fd == 0) {
    perror("cannot open file");
    exit(1);
  } else {
    char *buf = "hello\n";
    if (write(fd, "hello buddy\n", sizeof("hello buddy\n")) == 0)
      perror("write error\n");
  }
  
  close(fd);
  return 0;
}
