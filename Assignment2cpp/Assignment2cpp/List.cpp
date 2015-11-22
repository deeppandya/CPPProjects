#include "List.h"

//NOde constructor
List::Node::Node(const Token& tokenaddr, Node* nodeptr)
{
	data = tokenaddr;
	next = nodeptr;
}

//Default Constructor
List::List()
{

}

//Copy Constructor
List::List(const List& list)
{
	first = list.first;
	length = list.length;
}

//operator== overloading
void List::operator=(const List& list)
{
	first = list.first;
	length = list.length;
}

//Destructor for the list
List::~List()
{
	
}

//Function to return list's size
int List::size() const
{
	return length;
}

//Function to insert Token
void List::insert(const Token& token)
{
	bool check = false;
	Token tk = token;
	Token* tkptr = lookup(token);
	if ( tkptr== nullptr)
	{
		if (length > 0)
		{
			point = first;
			Node* previous = NULL;
			for (int i = 0; i < length; i++)
			{
				Token temptoken = point->data;
				if (tk.getTokenName()>temptoken.getTokenName())
				{
					/*Node node(token, tempnode->next);
					length++;
					tempnode->next = &node;
					break;*/
					if (point->next != nullptr)
					{
						previous = point;
						point = point->next;
					}
				}
				else
				{
					/*if (point->next = nullptr)
					{*/
						Node* node=new Node(tk, point);
						if (point!=first)
						{
							previous->next=node;
							//previousnode->next = node;
						}
						else
						{
							first = node;
						}
						length++;
						check = true;
						break;
				}
			}
			if (!check)
			{
				Node* node=new Node(tk, point->next);
				previous = point;
				point->next = node;
				length++;
			}

		}
		else
		{
			Node* node=new Node(tk, nullptr);
			first = node;
			point = node;
			length++;
		}
	}
	else
	{
		tkptr->setTokenFrequency(tkptr->getTokenFrequency() + 1);
		tkptr->addLineNumber(tk.getLineNumbers().pop_Back());
	}
}

//Function to lookup for a token
Token* List::lookup(const Token& token) const
{
	Token* tk = new Token(token);
	Node* tempnode = first;
	for (int i = 0; i < length; i++)
	{
		if (tempnode != nullptr)
		{
			Token* temptoken = &tempnode->data;
			if (temptoken->isEquivalent(token))
			{
				return temptoken;
			}
			tempnode = tempnode->next;
		}
		
	}
	return nullptr;
}

//Function to get first pointer of Node
List::Node* List::getFirstNode()
{
	return first;
}

//Function to Print list
void List::printList()
{
	Node* current = first;
		while (current != nullptr)
		{
			Token tk = current->data;
			cout << tk;
			current = current->next;
		}
	
}

//Function to write list in an external file
void List::WriteList(ofstream& outfile)
{
	//ofstream outfile("output.txt");
	Node* current = first;
	while (current != nullptr)
	{
		Token tk = current->data;
		outfile << tk;
		current = current->next;
	}
	//outfile.close();
}

//Operator << overloading
ostream& operator<<(ostream& out, const List& list)
{
	/*List::Node* current = list.first;
	while (current != nullptr)
	{
		Token tk = current->data;
		out << "name : " + tk.getTokenName() << " Frequency : " << tk.getTokenFrequency() << endl;
		current = current->next;
	}*/
	List templist = list;
	List::Node* current = templist.first;
	while (current != nullptr)
	{
		Token tk = current->data;
		out << tk<< endl;
		current = current->next;
	}
	return out;
}
