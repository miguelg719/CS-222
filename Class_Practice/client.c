#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

void readline(char buffer[])
{
	char c;
	int i = 0;
	while( (c = getchar()) != '\n' )
	{
		buffer[i] = c;
		i++;
	}
	
	buffer[i] = '\n';
	buffer[i+1] = '\0';
}

int main()
{
	int fd = -1;
	fd = socket(AF_INET, SOCK_STREAM, 0);
	
	printf("What is the port? ");
	int port;
	scanf("%d", &port);
	
	char ipAddress[100];
	printf("Enter IP address: ");
	scanf("%s", ipAddress);
	
	struct sockaddr_in address;
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress, &(address.sin_addr));
	
	connect( fd, (struct sockaddr*) &address, sizeof(address));
	
	char message[8192] = "";
	while(strcmp(message, "stop\n") != 0)
	{
		printf("Enter a message: ");
		readline(message);
		
		if(strcmp(message, "stop\n") != 0)
			send(fd, message, strlen(message), 0);
	}
	
	close(fd);
	
	return 0;
}
