#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define LISTEN_PORT 8080
#define BUF_SIZE 128

int main(int argc, char * argv[])
{
	int listenfd;
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {
		perror("create_listenfd error");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(LISTEN_PORT);

	if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("bind_listenfd error");
		exit(EXIT_FAILURE);
	}

	if (listen(listenfd, SOMAXCONN) < 0)
	{
		perror("listen_listenfd error");
		exit(EXIT_FAILURE);
	}

	int connfd;
	struct sockaddr_in peeraddr;
	socklen_t peerlen = sizeof(peeraddr);
	char buf[BUF_SIZE];
	int nbuf;

	for (;;){
		if ((connfd = accept(listenfd, (struct sockaddr *)&peeraddr, &peerlen)) < 0)
		{
			perror("accept_listenfd error");
			continue;
		}

		nbuf = recv(connfd, buf, BUF_SIZE, 0);
		buf[nbuf] = 0;
		if (!strcmp(buf, "exit"))
		{
			printf("exit_server\n");
			close(connfd);
			break;
		}

		printf("new conn(%s:%d); msg: %s\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port), buf);
		send(connfd, buf, nbuf, 0);
		close(connfd);
	}

	close(listenfd);
	return 0;
}
