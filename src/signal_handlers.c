#include <stdio.h>
#include <signal.h>
#include "signal_handlers.h"

void catch_sigint(int signalNo)
{
//  while(getchar() != '\n');
  printf("\nenter \"exit\" to terminate this process...\n");
  signal(SIGINT, catch_sigint);
}

void catch_sigtstp(int signalNo)
{
  printf("\ncannot pause the process!\n");
  signal(SIGTSTP, catch_sigtstp);
}
