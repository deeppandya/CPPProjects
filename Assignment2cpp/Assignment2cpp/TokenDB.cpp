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
		List lt;
		arr[i] = lt;
	}
}

//Function to read file and create Tokens
void TokenDB::ReadFile(string filename)
{
	string line;
	int linenum = 1;
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
			List &tokenlist = arr[count];
			Token token(tokenstring, linenum);
			tokenlist.insert(token);			
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
	for (int i = 0; i < arr.size(); i++)
	{
		List* tokenlist = &arr[i];
		tokenlist->printList();
		//cout << tokenlist<<endl;
	}
}


//Function to lookup a specific Token
void TokenDB :: lookup(string tokenstr)
{
	string tokenstring = trim(tokenstr);
	if (tokenstring != "")
	{
		Token token;
		token.setTokenName(tokenstring);
		char c = toupper(tokenstring.at(0));
		int count = c - 65;
		List &tokenlist = arr[count];
		Token* temptoken= tokenlist.lookup(token);
		if (temptoken != nullptr)
		{
			cout << (Token)*temptoken<<endl;
		}
		else
		{
			cout << "Token not found." << endl;
		}
		
	}
}

void TokenDB::ExportData()
{
	ofstream outfile("output.txt");
	if (outfile.is_open())
	{
		for (List tlist : arr)
		{
			tlist.WriteList(outfile);
		}
	}
	outfile.close();
	cout << "File has been exported.\nPlease check your project folder for 'output.txt'" << endl;
}

TokenDB::~TokenDB()
{
	
}