#include "Token.h"
#include "TokenDB.h"


//Main function to initiate program
int main()
{
	string filename;
	cout << "Please Enter the file : ";
	cin >> filename;
	cout << "\n\n" << endl;

	//Create 'TokenDB' object with the filename to generate Token Database.
	TokenDB tokendb(filename);

	//Menu to select option like print,look up and exit
Menu:
	cout << "----- Options -----\n" << endl;
	cout << "1. Print " << endl;
	cout << "2. LookUp " << endl;
	cout << "3. Export Data" << endl;
	cout << "4. Exit " << endl;
	cout << "\n\n" << endl;
	cout << "Enter your option : ";
	string option = "";
	cin >> option;

	if (option.size() > 1 || !isdigit(option.at(0)))
	{
		cerr << "Please Enter valid option" << endl;
		goto Menu;
	}
	else
	{
		bool check = false;
		int mop = atoi(option.c_str());
		if (mop == 1)
		{
			//print Tokens from TokenDB
			tokendb.Print();
			goto Menu;
		}
		else if (mop == 2)
		{
			cout << "\nEnter the token string for a lookup : ";
			string input = "";
			cin >> input;
			//getline(cin, input);
			if (isalpha(input.at(0)))
			{
				//Search for a Token
				tokendb.lookup(input);
			}
			else
			{
				cerr << "Token should always start with alphabet." << endl;
			}

			goto Menu;
		}
		else if (mop == 3)
		{
			//Export data
			tokendb.ExportData();
			goto Menu;
		}
		else if (mop == 4)
		{
			// Exit option
			system("exit");
		}
		else
		{
			cerr << "\nPlease Select appropriate option.\n" << endl;
			goto Menu;
		}
	}

	

	return 0;
}