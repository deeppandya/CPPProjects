#include "Token.h"


//Setter function to set Token String
void Token::setTokenName(string name)
{
	tokenName = name;
}

//Getter function to Get Token String
string Token::getTokenName()
{
	return tokenName;
}

//Setter function to set Token Frequency
void Token::setTokenFrequency(int f)
{
	frequency = f;
}

//Getter function to set Token Frequency
int Token::getTokenFrequency()
{
	return frequency;
}

//Function to add line number for perticular Token
void Token::addLineNumber(int no)
{
	vector<int> v = getLineNumbers();
	if (v.size() > 0)
	{
		int num = v.back();
		if (no != num)
		{
			lineNumbers.push_back(no);
		}
	}
	else
	{
		lineNumbers.push_back(no);
	}
}

//Function to Get List of line numbers for perticular Token
vector<int> Token::getLineNumbers()
{
	return lineNumbers;
}
