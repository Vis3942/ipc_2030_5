#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include "sl_api.h"
#define CLIENT_APP 1
#include "usock_proto.h"
#include "usock_client.h"

pthread_t client_id;

void test_send_data() {
  sl_der_client_derc_ind  tmp_derc_ind = {0};
  u8_t buf_wr[2048] ;
  int buf_wr_len = 0;
  tmp_derc_ind.derpMrId[0] = 'a'; 
  tmp_derc_ind.derpMrId[1] = 'b';
  tmp_derc_ind.derpMrId[2] = 'c';
  tmp_derc_ind.derpMrId[3] = 'd';
  tmp_derc_ind.derpMrId[4] = 'e';
  tmp_derc_ind.derpMrId[5] = 'f';
  tmp_derc_ind.derpMrId[6] = '0';
  tmp_derc_ind.derpMrId[7] = '1'; 
  tmp_derc_ind.derpMrId[8] = '2';
  tmp_derc_ind.derpMrId[9] = '3';
  tmp_derc_ind.derpMrId[10] = '4';
  tmp_derc_ind.derpMrId[11] = '5';
  tmp_derc_ind.derpMrId[12] = '6';
  tmp_derc_ind.derpMrId[13] = '7';
  tmp_derc_ind.derpMrId[14] = '8'; 
  tmp_derc_ind.derpMrId[15] = '9';
  tmp_derc_ind.derc.dercBase.rampTmsExists = 0 ;
  tmp_derc_ind.derc.dercBase.rampTms=7623;
  buf_wr_len = sizeof(tmp_derc_ind);
  memcpy(buf_wr, &tmp_derc_ind, buf_wr_len);
  send_message((void *)buf_wr, buf_wr_len, (uint32_t) SL_DER_CLIENT_DERC_IND);
}

int main() {
  int loop_count = 0;
  int err;
  err = pthread_create(&client_id, NULL, &usock_task, NULL);

  while (1) {
    sleep(5);
    if (loop_count % 5 == 0) {
      test_send_data();
    }
    loop_count ++;
  }

  return 0;

}
