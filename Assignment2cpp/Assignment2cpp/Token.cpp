#include "Token.h"
//Default constructor
Token::Token()
{

}

//Constructor with token name and line number
Token::Token(string name, int linenum)
{
	setTokenName(name);
	addLineNumber(linenum);
	frequency = 1;
}

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
	Vector &v = getLineNumbers();
	
	if (v.size() > 0)
	{
		int num = v.pop_Back();
		if (no != num)
		{
			lineNumbers.push_Back(no);
		}
	}
	else
	{
		lineNumbers.push_Back(no);
	}

}

//Function to Get List of line numbers for perticular Token
Vector Token::getLineNumbers()
{
	return lineNumbers;
}

//operator<< overloading to print token
ostream& operator<<(ostream& out, const Token& token)
{
	Token tk = token;
	out << "\nToken : " << tk.getTokenName() << "\nFrequency : " << tk.getTokenFrequency() << "\nLine numbers : " << tk.getLineNumbers() << endl;
	return out;
}

//operator<< overloading to print token to an external file
ofstream& operator<<(ofstream& fout, const Token& token)
{
	Token tk = token;
	fout << "\nToken : " << tk.getTokenName() << "\nFrequency : " << tk.getTokenFrequency() << "\nLine numbers : " << tk.getLineNumbers() << endl;
	return fout;
}

//Check token is equivalent or not
bool Token::isEquivalent(const Token& token)const
{
	Token tk = token;
	if (tk.getTokenName() == tokenName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Destructor
Token::~Token()
{

}
