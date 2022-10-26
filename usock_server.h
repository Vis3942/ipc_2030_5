#ifndef USOCK_SERVER_H
#define USOCK_SERVER_H

void usock_message_handler();
void usock_init();
void usock_task();
int usock_write_message(char* send_buf, int send_buf_len);

#endif /* for USOCK_SERVER_H */