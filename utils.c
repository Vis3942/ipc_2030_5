#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

char * app_name = "app_hello_world";

void version () {
  printf("App: %s -- Version: %04x d | compiled: %s\n", app_name, VERSION,  __DATE__);
}


