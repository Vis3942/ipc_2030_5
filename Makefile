all: test_usock_server  test_usock_client


test_usock_server: test_usock_server.c usock_server.c usock_proto.c usock_utils.c utils.c logger.c
	gcc -o test_usock_server  test_usock_server.c  usock_server.c  usock_proto.c usock_utils.c utils.c logger.c -lpthread

test_usock_client: test_usock_client.c  usock_client.c  usock_proto.c usock_utils.c utils.c  logger.c
	gcc -o test_usock_client test_usock_client.c  usock_client.c  usock_proto.c usock_utils.c utils.c  logger.c -lpthread


clean:
	rm test_usock_server  test_usock_client