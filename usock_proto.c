#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "logger.h"
#include "usock_proto.h"
#include "sl_api.h"


// #define SERVER_APP
#ifdef CLIENT_APP
#include "usock_client.h"
#else
#include "usock_server.h"
#endif

char recv_buf[1024];
char send_buf[1024];

// message type is based on defines in sl_api.h

void send_message(void * send_buf, int send_buf_len, uint32_t message_type) {
    int sent_len = -1;
    uint32_t send_len = (uint32_t) (send_buf_len + 8);
    // debug
    printf("proto: in send message\n");
    memset(send_buf, 0, 1024);
    memcpy(send_buf, &send_len, 4);
    memcpy((void*)&send_buf[4], &message_type, 4);
    memcpy((void*)&send_buf[8], send_buf, send_buf_len);
    sent_len = usock_write_message(send_buf, send_len);
    printf("sent %d bytes", sent_len);
    //console_log("sent %d bytes", sent_len);
}


uint32_t process_recv_message(char* rd_buf, int rd_buf_len) {
    // return the type of message received, and copy the contents of the message into recv_buf
    uint32_t  proto_message_len = 0;
    uint32_t  proto_message_type = 0;
    memcpy(&proto_message_len, rd_buf, 4);
    memcpy(&proto_message_type, &rd_buf[4], 4);
    if (proto_message_len <= 8) {
        printf("insufficient message packet recvd: lenght recvd: %d\n", proto_message_len);
        //console_log("insufficient message packet recvd: lenght recvd: %d\n", proto_message_len);
        return 0;
    }
    if (proto_message_len == rd_buf_len) {
        memcpy(recv_buf, (void*)send_buf[8], rd_buf_len - 8);
        printf("recvd msg type %02x\n", proto_message_type);
        //console_log("recvd msg type %02x\n", proto_message_type);
    }
    else {
        printf("recvd msg type %02x, incomplete message\n", proto_message_type);
        //console_log("recvd msg type %02x, incomplete message\n", proto_message_type);
        return 0; // UNKNOWN message type since incomplete message
    }
}