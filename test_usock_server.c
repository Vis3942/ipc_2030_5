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
#include <time.h>

pthread_t server_id;

void test_send_data() {
  sl_eder_server_dera_ind  tmp_dera_ind = {0};
  u8_t buf_wr[2048] ;
  int buf_wr_len = 0;
  tmp_dera_ind.deraExists = true;
  tmp_dera_ind.dera.availabilityDurationExists = true;
  tmp_dera_ind.dera.availabilityDuration = 4800;
  tmp_dera_ind.dera.maxChargeDurationExists = true;
  tmp_dera_ind.dera.maxChargeDuration = 4*60;
  buf_wr_len = sizeof(tmp_dera_ind);
  memcpy(buf_wr, &tmp_dera_ind, buf_wr_len);
  send_message((void *)buf_wr, buf_wr_len, (uint32_t) SL_EDER_SERVER_DERA_IND);
}



int main() {
  int loop_count = 0;
  int err;
  srand(time(NULL));   // Initialization, should only be called once.
  int rnd_sleep; 

  register_process_messages_callback(process_recv_message);
  err = pthread_create(&server_id, NULL, &usock_task, NULL);

  while (1) {
    rnd_sleep = rand();
    rnd_sleep = rnd_sleep %10;
    sleep(rnd_sleep);
    if (loop_count % 5 == 0) {
      test_send_data();
    }
    loop_count ++;
  }

  return 0;
}
