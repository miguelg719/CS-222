#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


void readLine(char line[])
{	
	int c = 0;	
	int i = 0;

	while( (c = getchar()) != '\n' )
	{
		line[i] = c;
		i++;
	}

	line[i] = '\0';
}

int main()
{
	int fd = -1;
	fd = socket(AF_INET, SOCK_STREAM, 0);
	
	char ipAddress[100];
	printf("Enter IP: ");
	scanf("%s", ipAddress);
	
	unsigned int port;
	printf("Enter port: ");
	scanf("%u", &port);
	
	char name[20];
	printf("Enter user name: ");
	scanf("%s", name);
	
	struct sockaddr_in address;
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress, &(address.sin_addr));
	
	connect( fd, (struct sockaddr*) &address, sizeof(address) );
	
	printf("\n*Chat Started*\n\n");
	
	char c = getchar();
	char message[8192] = "";
	char buffer[8192] = "";
	while(strcmp(message, "quit") != 0)
	{
		printf("%s: ", name);
		readLine(message);
		sprintf(buffer, "%s: %s", name, message);
		
		if(strcmp(message, "quit") != 0)
			send(fd, buffer, strlen(buffer), 0);
		else
			send(fd, message, strlen(message), 0);
	}
	
	
	printf("\n*Chat Ended*\n");
	
	close(fd);

	return 0;
}
