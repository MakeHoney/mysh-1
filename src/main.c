#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#include "commands.h"
#include "built_in.h"
#include "utils.h"
#include "signal_handlers.h"

int main()
{
  char buf[8096];

  char* temp;
  int bgpid;
  int status;
  int pid;


  signal(SIGINT, (void*)catch_sigint);
  signal(SIGTSTP, (void*)catch_sigtstp);

  while (1) {
//	signal(SIGSTOP, (void*)catch_sigtstp);
    fgets(buf, 8096, stdin);

    struct single_command commands[512];

    int n_commands = 0;

    mysh_parse_command(buf, &n_commands, &commands);

	memset(buf, 0x00, 8096);

	int ret = evaluate_command(n_commands, &commands, &bgpid);

	free_commands(n_commands, &commands);

    n_commands = 0;

    if (ret == 1) {
      break;
    }
 }
  return 0;
}
