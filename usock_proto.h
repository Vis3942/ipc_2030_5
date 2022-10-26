#ifndef USOCK_PROTO_H
#define USOCK_PROTO_H

extern char recv_buf[1024];
void send_message(void * send_buf, int send_buf_len, uint32_t message_type);
uint32_t process_recv_message(char* rd_buf, int rd_buf_len);

#endif // USOCK_PROTO_H