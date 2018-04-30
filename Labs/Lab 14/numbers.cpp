#include <iostream>
#include <string>

using namespace std;

string getName(int value)
{
	switch( value )
	{
	case 1: return "one";
	case 2: return "two";
	case 3: return "three";
	case 4: return "four";
	case 5: return "five";
	case 6: return "six";
	case 7: return "seven";
	case 8: return "eight";
	case 9: return "nine";
	}
	
	return "";
}

string getTens(int value)
{
	switch( value )
	{
	case 2: return "twenty";
	case 3: return "thirty";
	case 4: return "forty";
	case 5: return "fifty";
	case 6: return "sixty";
	case 7: return "seventy";
	case 8: return "eighty";
	case 9: return "ninety";
	}
	
	return "";
}

string getTeens(int value)
{
	switch( value )
	{
	case 0: return "ten";
	case 1: return "eleven";
	case 2: return "twelve";
	case 3: return "thirteen";
	case 4: return "fourteen";
	case 5: return "fifteen";
	case 6: return "sixteen";
	case 7: return "seventeen";
	case 8: return "eighteen";
	case 9: return "nineteen";
	}
	
	return "";
}

int main()
{
	int number;
	cout << "Enter a number: (0-999) ";
	cin >> number;

	int digit[2];
	int i = 0;
	while( number != 0 )
	{
		digit[i] = number % 10;
		i++;
		number /= 10;
	}
	
	string word1 = "";
	string word2 = "";
	string word3 = "";
	
	if( digit[2] != 0 )
		word1 = getName(digit[2]) + " hundred ";
		
	if( digit[1] != 0 && digit[1] != 1)
		word2 = getTens(digit[1]) + " ";
	
	if( digit[0] != 0 )
		word3 = getName(digit[0]) + " ";
		
	if( digit[1] == 1 )
		word3 = getTeens(digit[0]) + " ";
	
	string wordfinal = word1 + word2 + word3;
	
	if( digit[0] == 0 && digit[1] == 0 && digit[2] == 0 )
		cout << "Your number in words: zero" << endl;
	else
		cout << "Your number in words: " << wordfinal << endl;

	
	return 0;
}
