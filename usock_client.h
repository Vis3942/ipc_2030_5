#ifndef USOCK_CLIENT_H
#define USOCK_CLIENT_H

void usock_message_handler();
void usock_init();
void usock_task();
int usock_write_message(char* send_buf, int send_buf_len);



#endif // USOCK_CLIENT_H