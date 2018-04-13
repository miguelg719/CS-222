#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{	
	if( argc != 2 )
	{
		printf("Usage: ./checksum <filename>");
		return 0;	
	}
	
	char* filename;
	filename = strdup(argv[1]); 
	
	int fd = open(filename, O_RDONLY);
	if( fd < 0 )
	{
		printf("./checksum: %s: No such file or directory", filename);
		return 0;
	}
	
	 
	unsigned int sum = 0;
	unsigned char buffer;
	int bytes = 1;
	int total;
	int i;
	int two = (1 << 16); 
	int r = 0;
	int s = 0;
	
	while( bytes == 1 )
	{
		bytes = read(fd, &buffer, sizeof(unsigned char));
		if( bytes != 0 )
		{
			sum += buffer;
			total += bytes;
		}
	}
	
	r = (sum % two) + (sum / two);
	s = (r % two) + (r / two);
	
	int blocks = 0;
	if( sum % 512 != 0 )
		blocks = total / 512 + 1;
	else 
		blocks = total / 512;
		
	printf("%d %d %s\n", s, blocks, filename);
	
	close(fd);
	
	return 0;
}
