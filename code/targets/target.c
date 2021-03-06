#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(char* arg)
{
  char localBuf[150];
  short len = 150;
  double var1=2.4;  
  int *ptr = NULL;
  strcpy(localBuf, arg);
  printf("foo() finishes normally.\n");
  return 0;
}

int kbhit(void)
{
  struct timeval tv;
  fd_set read_fd;
  tv.tv_sec=0;  tv.tv_usec=0;
  FD_ZERO(&read_fd);  FD_SET(0,&read_fd);
  if(select(1, &read_fd, NULL, NULL, &tv) == -1)
    return 0;
  if(FD_ISSET(0,&read_fd))
    return 1;
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
      fprintf(stderr, "target: argc != 2\n");
      exit(EXIT_FAILURE);
    }
  printf("Press any key to call foo function...\n");
  while(!kbhit())
    ;
  foo(argv[1]);
  return 0;
}


