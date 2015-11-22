#include "Fraction.h"

//get numerator
long Fraction::geta()
{
	return a;
}
//get denominator
long Fraction::getb()
{
	return b;
}
//set denominator
void Fraction::seta(long x)
{
	a = x;
}
//set denominator
void Fraction::setb(long y)
{
	b = y;
}
//deault destructor
Fraction::~Fraction()
{

}
/*Fraction::Fraction(long x = 0, long y = 1)
{
	
}*/
//find gcd of given two numbers
long Fraction::gcd(long x, long y)
{
	return y == 0 ? x : gcd(y, x % y);
}
//Normalize fraction
void Fraction::normalize()
{
	long tempgcd = gcd(geta(), getb());
	seta(geta() / tempgcd);
	setb(getb() / tempgcd);
}
//Fraction constructor with string
Fraction::Fraction(const string& infixExpression)
{
	Fraction f = evaluatePostfix(infixToPostfix(Tokenize(infixExpression)));
	f.normalize();
	*this = f;
}
//Fraction constructor with char*
Fraction::Fraction(const char* infixExpression)
{
	Fraction f = evaluatePostfix(infixToPostfix(Tokenize(infixExpression)));
	f.normalize();
	*this = f;
}
//Tokenize an Expression
queue<string> Fraction::Tokenize(const string& infixExpression)
{

	queue<string> que;
	stringstream ss;
	string temp;
	string infixexp = infixExpression;

	int i = 0;

	while (i < infixexp.size())
	{
		if ((string(1, infixexp[i])) == " ")	//ignore whitespace
		{
			i++;
			continue;
		}

		if (infixexp[i] == '+' || infixexp[i] == '-' || infixexp[i] == '*' || infixexp[i] == '/' || infixexp[i] == '(' || infixexp[i] == ')')	//just push the letter othan than digits
		{
			que.push(string(1, infixexp[i]));
			i++;
		}

		if (infixexp[i] <= '9'&&infixexp[i] >= '0')	//that means digit. so check for more than 1-digit numbers
		{
			string tempdigit;
			while (infixexp[i] >= '0'&&infixexp[i] <= '9')
			{
				tempdigit.append(string(1, infixexp[i]));
				i++;

				if (i == infixexp.length())
					break;

			}
			que.push(tempdigit);
		}

	}
	return que;
}

//Convert infix to postfix
queue<string> Fraction::infixToPostfix(queue<string>& infixExpression)
{
	queue<string> postfixQueue;
	stack<string> opStack;
	queue<string> inputinfix = infixExpression;
	while (!inputinfix.empty())
	{
		string token = inputinfix.front();
		if (isdigit(token[0]))
		{
			postfixQueue.push(token);
		}
		else if (token == "(")
		{
			opStack.push(token);
		}
		else if (token == ")")
		{
			while (!opStack.empty() && opStack.top()!="(")
			{
				postfixQueue.push(opStack.top());
				opStack.pop();
			}
			opStack.pop();
		}
		else
		{
			while (!opStack.empty() && precedence(opStack.top()) >= precedence(token))
			{
				postfixQueue.push(opStack.top());
				opStack.pop();
			}
			opStack.push(token);
		}
		inputinfix.pop();
	}

	while (!opStack.empty())
	{
		postfixQueue.push(opStack.top());
		opStack.pop();
	}

	return postfixQueue;
}
//Find precedence of an operator
int Fraction::precedence(string op)
{
	if (op == "*" || op == "/")
	{
		return 2;
	}
	else if (op == "+" || op == "-")
	{
		return 1;
	}
	else if (op == "(" || op == ")")
	{
		return 0;
	}
	else
	{
		return 5;
	}
}
//Function to evaluate postfix
Fraction Fraction::evaluatePostfix(queue<string>& postfixTokenQueue)
{
	stack<Fraction>operandStack;
	//stack<Fraction>opeartorStack;
	Fraction operand1;
	Fraction operand2;
	Fraction result;

	while (!postfixTokenQueue.empty())
	{
		string token = postfixTokenQueue.front();
		if (isdigit(token[0]))
		{
			Fraction f(stol(token));
			operandStack.push(f);
		}
		else
		{
			operand2 = operandStack.top();
			operandStack.pop();
			operand1 = operandStack.top();
			operandStack.pop();
			Fraction tempresult = computeResult(operand1, operand2, token);
			operandStack.push(tempresult);
		}
		postfixTokenQueue.pop();
	}
	result = operandStack.top();
	operandStack.pop();
	return result;
}
//Compute result for given operands and operator
Fraction Fraction::computeResult(Fraction op1, Fraction op2, string opr)
{
	Fraction result;
	if (opr == "+")
	{
		result = op1 + op2;
	}
	else if (opr == "-")
	{
		result = op1 - op2;
	}
	else if (opr == "*")
	{
		result = op1 * op2;
	}
	else if (opr == "/")
	{
		result = op1 / op2;
	}

	return result;
}


// member functions	

//operator= overloading
Fraction& Fraction::operator=	(const int& val)	// f =	i
{
	this->a = val;
	this->b = 1;
	return *this;
}
//operator+= overloading
Fraction& Fraction::operator+=	(const int& val)	// f +=	i
{
	this->a = this->a+(this->b*val);
	this->b = this->b;
	return *this;
}
//operator-= overloading
Fraction& Fraction::operator-=	(const int& val)	// f -=	i
{
	this->a = this->a - (this->b*val);
	this->b = this->b;
	return *this;
}
//operator*= overloading
Fraction& Fraction::operator*=	(const int& val)	// f *=	i
{
	this->a = this->a*val;
	this->b = this->b;
	return *this;
}
//operator/= overloading
Fraction& Fraction::operator/= (const int& val)	// f /= i
{
	this->a = this->a;
	this->b = this->b*val;
	return *this;
}

//operator= overloading 
Fraction& Fraction::operator= (const Fraction& rhs)	// f  = f
{
	this->a = rhs.a;
	this->b = rhs.b;
	return *this;
}
//operator+= overloading
Fraction& Fraction::operator+= (const Fraction& rhs)	// f += f
{
	this->a = (this->a*rhs.b) + (this->b*rhs.a);
	this->b = (this->b*rhs.b);
	return *this;
}
//operator-= overloading
Fraction& Fraction::operator-= (const Fraction& rhs)  // f -= f 
{
	this->a = (this->a*rhs.b) - (this->b*rhs.a);
	this->b = (this->b*rhs.b);
	return *this;
}
//operator*= overloading
Fraction& Fraction::operator*= (const Fraction& rhs)  // f *= f 
{
	this->a = (this->a * rhs.a);
	this->b = (this->b*rhs.b);
	return *this;
}
//operator/= overloading
Fraction& Fraction::operator/= (const Fraction& rhs)  // f /= f 
{
	this->a = (this->a * rhs.b);
	this->b = (this->b*rhs.a);
	return *this;
}

// non-member functions 

//operator+ overloading
Fraction operator+(const Fraction& lhs, const Fraction& rhs) // f + f 
{
	long x = (lhs.a*rhs.b) + (lhs.b*rhs.a);
	long y = (lhs.b*rhs.b);
	Fraction f(x, y);
	return f;
}
//operator+ overloading
Fraction operator+(const Fraction& lhs, const int& val)		// f	+	i
{
	long x = (lhs.a) + (lhs.b*val);
	long y = (lhs.b);
	Fraction f(x, y);
	return f;
}
//operator+ overloading
Fraction operator+(const int& val, const Fraction& rhs)		// i + f
{
	long x = (rhs.a) + (rhs.b*val);
	long y = (rhs.b);
	Fraction f(x, y);
	return f;
}
//operator- overloading
Fraction operator-(const Fraction& lhs, const Fraction& rhs) // f - f
{
	long x = (lhs.a*rhs.b) - (lhs.b*rhs.a);
	long y = (lhs.b*rhs.b);
	Fraction f(x, y);
	return f;
}
//operator- overloading
Fraction operator-(const Fraction& lhs, const int& val)		// f - i
{
	long x = (lhs.a) - (lhs.b*val);
	long y = (lhs.b);
	Fraction f(x, y);
	return f;
}
//operator- overloading
Fraction operator-(const int& val, const Fraction& rhs)		// i - f
{
	long x = (rhs.b*val)-rhs.a;
	long y = (rhs.b);
	Fraction f(x, y);
	return f;
}
//operator* overloading
Fraction operator*(const Fraction& lhs, const Fraction& rhs)	// f * f
{
	long x = (lhs.a) * (rhs.a);
	long y = (lhs.b) * (rhs.b);
	Fraction f(x, y);
	return f;
}
//operator* overloading
Fraction operator*(const Fraction& lhs, const int& val)		// f * i
{
	long x = (lhs.a) * (val);
	long y = (lhs.b) * (1);
	Fraction f(x, y);
	return f;
}
//operator* overloading
Fraction operator*(const int& val, const Fraction& rhs)		// i * f
{
	long x = (rhs.a) * (val);
	long y = (rhs.b) * (1);
	Fraction f(x, y);
	return f;
}
//operator/ overloading
Fraction operator/(const Fraction& lhs, const Fraction& rhs)	// f / f
{
	long x = (lhs.a) * (rhs.b);
	long y = (lhs.b) * (rhs.a);
	Fraction f(x, y);
	return f;
}
//operator/ overloading
Fraction operator/(const Fraction& lhs, const int& val)		// f / i
{
	long x = (lhs.a);
	long y = (lhs.b) * (val);
	Fraction f(x, y);
	return f;
}
//operator/ overloading
Fraction operator/(const int& val, const Fraction& rhs)		// i / f
{
	long x = (val) * (rhs.b);
	long y = (rhs.a);
	Fraction f(x, y);
	return f;
}
//operator+ overloading
Fraction operator+(const Fraction& rhs)	// +f				
{
	Fraction f = (1)*rhs;
	return f;
}
//operator ++f overloading
Fraction& Fraction::operator++()	// ++f				
{
	this->a = this->a + this->b;
	this->b = this->b;
	return *this;
}
//operator f++ overloading
Fraction Fraction::operator++(int)	// f++				
{
	Fraction f(this->a, this->b);
	this->a = this->a + this->b;
	this->b = this->b;
	return f;
}
//operator -f overloading
Fraction operator-(const Fraction& rhs)	// -f				
{
	Fraction f = (-1)*rhs;
	return f;
}
//operator --f overloading
Fraction & Fraction::operator--()	// --f				
{
	this->a = this->a - this->b;
	this->b = this->b;
	return *this;
}
//operator f-- overloading
Fraction Fraction::operator--(int)	// f--				
{
	Fraction f(this->a, this->b);
	this->a = this->a - this->b;
	this->b = this->b;
	return f;
}
//operator== overloading
bool operator==(const Fraction& lhs, const Fraction& rhs) // f == f	
{
	return ((lhs.a*rhs.b) == (lhs.b*rhs.a)) ? true: false;
}
//operator== overloading
bool operator==(const Fraction& lhs, const int& val)	// f == i	
{
	return ((lhs.a) == (lhs.b*val)) ? true : false;
}
//operator== overloading
bool operator==(const int& val, const Fraction& rhs)	// i == f	
{
	return ((val*rhs.b) == (rhs.a)) ? true : false;
}
//operator!= overloading
bool operator!=(const Fraction& lhs, const Fraction& rhs) // f != f	
{
	return ((lhs.a*rhs.b) != (lhs.b*rhs.a)) ? true : false;
}
//operator! overloading
bool operator!=(const Fraction& lhs, const int& val)	// f != i	
{
	return ((lhs.a) != (lhs.b*val)) ? true : false;
}
//operator!= overloading
bool operator!=(const int& val, const Fraction& rhs)	// i != f	
{
	return ((val*rhs.b) != (rhs.a)) ? true : false;
}
//operator< overloading
bool operator<(const Fraction& lhs, const Fraction& rhs)	// f < f	
{
	return ((lhs.a*rhs.b) < (rhs.a*lhs.b)) ? true : false;
}
//operator<= overloading
bool operator<=(const Fraction& lhs, const Fraction& rhs) // f <= f	
{
	return ((lhs.a*rhs.b) <= (rhs.a*lhs.b)) ? true : false;
}
//operator> overloading
bool operator>(const Fraction& lhs, const Fraction& rhs)	// f > i	
{
	return ((lhs.a*rhs.b) > (rhs.a*lhs.b)) ? true : false;
}
//operator>= overloading
bool operator>=(const Fraction& lhs, const Fraction& rhs)	// i >= f
{
	return ((lhs.a*rhs.b) >= (rhs.a*lhs.b)) ? true : false;
}
//operator() overloading
string Fraction::operator()() // returns the string version of this fraction 
{
	return this->a + "/" + this->b;
}
//operator>> overloading
istream& operator>> (istream& istr, Fraction& rhs)
{
	istr >> rhs.a;
	istr >> rhs.b;
	return istr;
}
//operator<< overloading
ostream& operator<< (ostream& ostr, const Fraction& rhs)
{
	ostr << rhs.a << "/" << rhs.b;
	return ostr;
}