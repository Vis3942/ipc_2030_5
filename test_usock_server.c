#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include "sl_api.h"
#define SERVER_APP
#include "usock_proto.h"
#include "usock_server.h"

pthread_t server_id;

int main() {
  int loop_count = 0;
  int err;
  err = pthread_create(&server_id, NULL, &usock_task, NULL);

  while (1) {
    sleep(5);
  }

  return 0;
}
