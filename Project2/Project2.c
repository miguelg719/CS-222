# include <stdio.h>
# define MAXLENGTH 2048

unsigned char rotate(unsigned char a, int count);
int bits(unsigned char a);
void tiling(unsigned char key[], int keyLength, int messageLength);
void chaining(unsigned char key[], int messageLength, int keyLength);

int main(){
	unsigned char message[MAXLENGTH];
	unsigned char key[MAXLENGTH];
	int messageLength = 0;		//Length of message
	int keyLength = 0;		//Length of key
	
	char in = getchar();
	while(messageLength < MAXLENGTH && in != (char)(255)){		//Import message
		message[messageLength] = (unsigned char) in;
		in = getchar();
		messageLength++;
	}

	if(messageLength == MAXLENGTH)
		while(in != (char)(255))
			in = getchar();

	in = getchar();
	while(keyLength < MAXLENGTH && keyLength < messageLength && in != EOF){
		key[keyLength] = (unsigned char) in;
		in = getchar();
		keyLength++;
	}

	if(keyLength == MAXLENGTH)
		while(in != EOF)
			in = getchar();

	if(keyLength < messageLength){		//Tiling
		tiling(key, keyLength, messageLength);
		keyLength = messageLength;		//Key is now as long as the message
	}

	chaining(key, messageLength, keyLength);

	int i;
	for(i = 0; i< messageLength; i++)
		putchar((unsigned char)(message[i] ^ key[i]));

	return 0;
}

unsigned char rotate(unsigned char a, int count){
	int i;
	for(i = 0; i< count; i++){
		if(1 & a){		//Least significant bit is a 1
			a = a >> 1;
			a = a + (1 << 6);
		}
		else	//Least significant bit is a 0
			a = a >> 1;
	}

	return a;
}

int bits(unsigned char a){
	int sum = 0;
	int i;
	for(i = 0; i < 8; i++)
		if( (1 << i) & a)
			sum += 1;

	return sum;
}

void tiling(unsigned char key[], int keyLength, int messageLength){
	int i;
	for(i = keyLength; i < messageLength; i++)
		key[i] = key[i - keyLength];
}

void chaining(unsigned char key[], int messageLength, int keyLength){
	int i;
	int sum = key[keyLength-1] % keyLength;
	for(i = 0; i < messageLength; i++){
		if(i == 0){
			key[i] = rotate((key[i] ^ key[sum]), bits(key[keyLength-1]));
			sum = sum + key[i];
			sum = sum % messageLength;
		}
		else{
			key[i] = rotate((key[i] ^ key[sum]), bits(key[i-1]));
			sum = sum + key[i];
			sum = sum % messageLength;
		}
	}
}



