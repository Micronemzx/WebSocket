#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#inclued <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sock;
	char message[BUF_SIZE];
	int str_len;
	socklen_t adr_sz;
	struct sockaddr_in serv_adr, clnt_adr;
	if (argc!=3) exit(1);
	
	serv_sock=socket(PF_INET, SOCK_DGRAM, 0);
	if (serv_sock == -1)
		error_handling();
	
	memset(&serv_adr,0,sizeof(serv_adr));
	serv_adr.sin_famil=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));
	while (1)
	{
		fputs("Insert mesage(q to quit):", stdout);
		fgets(message, sizeof(message), stdin);
		if (!strcmp(message,"q\n") || !strcmp(message,"Q\n"))
			break;
		sendo(sock, message, strlen(message), 0,(struct sockaddr*) &serv_adr,sizeof(serv_adr));
		adr_sz = sizeof(from_adr);
		str_len=recvfrom(sock,message,BUF_SIZE,0,(struct sockaddr*)&from_adr,&adr_sz);
		message[str_len]=0;
		printf("Message from server: %s",message);	
	}
	close(serv_sock);
	return 0;
}
