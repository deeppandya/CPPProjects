#include "TokenDB.h"

//Constructor to create an object with filename
TokenDB::TokenDB(string filename)
{
	ReadFile(filename);
}

//Function to assign list of alphabets in a array
void TokenDB::assignList()
{
	for (int i = 0; i < 26; i++)
	{
		list<Token> lt;
		arr[i] = lt;
	}
}

//Function to read file and create Tokens
void TokenDB::ReadFile(string filename)
{
	string line;
	int linenum = 1;
	vector<string> elems;
	ifstream file;
	file.open(filename);//Open file to read
	if (file.is_open())
	{
		assignList();
		while (getline(file, line))// Get line by new line character
		{
			SetToken(line, ' ', linenum);
			linenum++;
		}
	}
	file.close();
}

//Store Tokens in TokenDB 
void TokenDB::SetToken(const string &s, char delim,int linenum)
{

	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))//Get Token using space as a delimeter
	{
		string tokenstring = trim(item);
		if (tokenstring != "")
		{
			char c = toupper(tokenstring.at(0));
			int count = c - 65;
			list<Token> &tokenlist = arr[count];
			list<Token>::iterator it;
			if (tokenlist.size() > 0)
			{
				it = tokenlist.begin();
				for (Token &token : tokenlist)
				{
					string fstr = tokenstring;
					string str = token.getTokenName();
					//for (auto & c : str) c = toupper(c);
					//for (auto & c : fstr) c = toupper(c);
					if (str == fstr)
					{
						token.setTokenFrequency(token.getTokenFrequency() + 1);
						token.addLineNumber(linenum);
						break;
					}
					else
					{
						if (fstr.compare(str) > 0)
						{
							it++;
							if (it == tokenlist.end())
							{
								Token temptoken;
								temptoken.setTokenName(tokenstring);
								temptoken.setTokenFrequency(1);
								temptoken.addLineNumber(linenum);
								tokenlist.insert(it, temptoken);
								break;
							}
						}
						else
						{
							Token temptoken;
							temptoken.setTokenName(tokenstring);
							temptoken.setTokenFrequency(1);
							temptoken.addLineNumber(linenum);
							tokenlist.insert(it, temptoken);
							break;
						}
					}
				}
			}
			else
			{
				Token token;
				token.setTokenName(tokenstring);
				token.setTokenFrequency(1);
				token.addLineNumber(linenum);
				tokenlist.push_back(token);
			}
		}
	}
}

//Trim spectial characters form a token
string TokenDB::trim(const string & str)
{
	// locate the position of the first alphabet letter (if any) in str
	int left = 0;
	while (left < str.size() && !isalpha(str[left]))
	{
		++left;
	}

	// was there a first letter?
	if (left >= str.size())
	{
		return string{}; // no letters, return empty string
	}

	// locate the position of the last alphabet letter in str
	int right = str.size() - 1;
	while (right > left && !isalpha(str[right]))
	{
		--right;
	}

	// return everything between positions left and right
	return str.substr(left, right - left + 1);
}

//Function to print Token from TokenDB
void TokenDB::Print()
{
	for (list<Token> &tlist: arr)
	{
		char ch='\0';
		for (Token &token : tlist)
		{
			char c = toupper(token.getTokenName().at(0));
			if (ch != c)
			{
				ch = c;
				cout << c << " : " << endl;
			}
			cout << "Token : " << token.getTokenName() << endl;
			cout << "Token Frequency : " << token.getTokenFrequency() << endl;
			string linenumbers = "(";
			for (int i : token.getLineNumbers())
			{
				linenumbers.append(to_string(i));
				linenumbers.append(",");
			}
			linenumbers.pop_back();
			linenumbers.append(")");
			cout << "Line Numbers : " << linenumbers << "\n\n"<<endl;
		}
	}
	if (!arr.size() > 0)
	{
		cerr << "File Doesn't have any data." << endl;
	}
}


//Function to lookup a specific Token
void TokenDB :: lookup(string tokenstr)
{
	if (tokenstr != "")
	{
		char c = toupper(tokenstr.at(0));
		int count = c - 65;
		list<Token> &tokenlist = arr[count];
		list<Token>::iterator it;
		bool check = false;
		if (tokenlist.size() > 0)
		{
			it = tokenlist.begin();
			for (Token &token : tokenlist)
			{
				string fstr = tokenstr;
				string str = token.getTokenName();
				/*for (auto & c : str) c = toupper(c);
				for (auto & c : fstr) c = toupper(c);*/
				if (str == fstr)
				{
					cout << "Token : " << token.getTokenName() << endl;
					cout << "Token Frequency : " << token.getTokenFrequency() << endl;
					string linenumbers = "(";
					for (int i : token.getLineNumbers())
					{
						linenumbers.append(to_string(i));
						linenumbers.append(",");
					}
					linenumbers.pop_back();
					linenumbers.append(")");
					cout << "Line Numbers : " << linenumbers << "\n\n" << endl;
					check = true;
					break;
				}
			}
			if (!check)
			{
				cerr << "Error : nonexistent token ' " << tokenstr << " ' " << endl;
			}
		}
		else
		{
			cerr << "Error : nonexistent token ' " << tokenstr << " ' " << endl;
		}
	}
	else
	{
		cerr << "Please don't pass empty token for a lookup" << endl;
	}
}

void TokenDB::ExportData()
{

	ofstream outfile("output.txt");
	if (outfile.is_open())
	{
		for (list<Token> &tlist : arr)
		{
			char ch = '\0';
			for (Token &token : tlist)
			{
				char c = toupper(token.getTokenName().at(0));
				if (ch != c)
				{
					ch = c;
					outfile << c << " : " << endl;
				}
				outfile << "Token : " << token.getTokenName() << endl;
				outfile << "Token Frequency : " << token.getTokenFrequency() << endl;
				string linenumbers = "(";
				for (int i : token.getLineNumbers())
				{
					linenumbers.append(to_string(i));
					linenumbers.append(",");
				}
				linenumbers.pop_back();
				linenumbers.append(")");
				outfile << "Line Numbers : " << linenumbers << "\n\n" << endl;
			}
		}
	}
	outfile.close();
	cout << "File has been exported.\nPlease check your project folder for 'output.txt'" << endl;
}