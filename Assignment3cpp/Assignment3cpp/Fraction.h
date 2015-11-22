#ifndef FRACTION_HEADER
#define FRACTION_HEADER

#include<iostream>
#include <string>
#include<fstream>
#include<ostream>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>
#include<regex>
#include<assert.h>

using namespace std;

class Fraction
{
private:
	long a; //numerator
	long b; //denominator

public:
	long geta(); //get numerator
	long getb(); //get denominator
	void seta(long); //set numerator
	void setb(long); //set denominator
	~Fraction(); //default destructor
	// constructor with default parameters
	Fraction(long x = 0, long y = 1) 
	{
		assert(y != 0);
		seta(x);
		setb(y);
	}
	//find gcd with given numbers
	static long gcd(long, long);
	//Normalize fraction
	void normalize();
	//Fraction constructor with string expression
	Fraction(const string& infixExpression);
	//Fraction constructor with char* expression
	Fraction(const char* infixExpression);
	//Tokenize an Expression
	static queue<string> Tokenize(const string& infixExpression);
	//Convert Infix expression to postfix expression
	static queue<string> infixToPostfix(queue<string>& infixExpression);
	//Find precedence of an operator
	static int precedence(string op);
	//Evaluate postfix expression
	static Fraction evaluatePostfix(queue<string>& postfixTokenQueue);
	//Compute result with given two operands and given operator.
	static Fraction computeResult(Fraction op1, Fraction op2, string ope);

	// member functions				
		Fraction& operator=	(const int& val);	// f =	i
		Fraction& operator+=	(const int& val);	// f +=	i
		Fraction& operator-=	(const int& val);	// f -=	i
		Fraction& operator*=	(const int& val);	// f *=	i
		Fraction& operator/= (const int& val);	// f /= i
	
		Fraction& operator= (const Fraction& rhs);	// f  = f
		Fraction& operator+= (const Fraction& rhs);	// f += f

		Fraction& operator-= (const Fraction& rhs);  // f -= f 

		Fraction& operator*= (const Fraction& rhs);  // f *= f 

		Fraction& operator/= (const Fraction& rhs);  // f /= f 

	// non-member functions 

		friend Fraction operator+(const Fraction& lhs, const Fraction& rhs); // f + f 

		friend Fraction operator+(const Fraction& lhs, const int& val);		// f	+	i
		friend Fraction operator+(const int& val, const Fraction& rhs);		// i + f
	
		friend Fraction operator-(const Fraction& lhs, const Fraction& rhs); // f - f
		friend Fraction operator-(const Fraction& lhs, const int& val);		// f - i
		friend Fraction operator-(const int& val, const Fraction& rhs);		// i - f
	
		friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);	// f * f
		friend Fraction operator*(const Fraction& lhs, const int& val);		// f * i
		friend Fraction operator*(const int& val, const Fraction& rhs);		// i * f
	
		friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);	// f / f
		friend Fraction operator/(const Fraction& lhs, const int& val);		// f / i
		friend Fraction operator/(const int& val, const Fraction& rhs);		// i / f
	
		friend Fraction operator+(const Fraction& rhs);	// +f				
		Fraction & Fraction::operator++();	// ++f				
		Fraction Fraction::operator++(int);	// f++				
		friend Fraction operator-(const Fraction& rhs);	// -f				
		Fraction & Fraction::operator--();	// --f				
		Fraction Fraction::operator--(int);	// f--				
	
		friend bool operator==(const Fraction& lhs, const Fraction& rhs); // f == f	
		friend bool operator==(const Fraction& lhs, const int& val);	// f == i	
		friend bool operator==(const int& val, const Fraction& rhs);	// i == f	
		friend bool operator!=(const Fraction& lhs, const Fraction& rhs); // f != f	
		friend bool operator!=(const Fraction& lhs, const int& val);	// f != i	
		friend bool operator!=(const int& val, const Fraction& rhs);	// i != f	

		friend bool operator<(const Fraction& lhs, const Fraction& rhs);	// f < f	
		friend bool operator<=(const Fraction& lhs, const Fraction& rhs); // f <= f	
		friend bool operator>(const Fraction& lhs, const Fraction& rhs);	// f > i	
		friend bool operator>=(const Fraction& lhs, const Fraction& rhs);	// i >= f

		string operator()(); // returns the string version of this fraction 

		friend istream& operator>> (istream& istr, Fraction& rhs);// operator>> overloading

		friend ostream& operator<< (ostream& ostr, const Fraction& rhs); //operator<< overloading

};

#endif