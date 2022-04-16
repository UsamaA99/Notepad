// Muhammad Usama Azam
// 19I-1786
// Assignment 2
#include <iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

struct Node {
public:
	char d;
	Node* next;
	Node* down;
};

class List 
{
private:
	Node* head;
public:

	List(void) { head = NULL; }

	bool IsEmpty() { return head == NULL; }

	Node* InsertNode(int x,int y, char d);

	void enter(int x, int y)
	{
		int i2 = 0;
		Node* currN2 = head;
		Node* prev = NULL;
		while (currN2 && y > i2)
		{
			prev = currN2;
			currN2 = currN2->down;
			i2 += 1;
		}
		int currIndex = 1;
		Node* currNode = currN2;
		while (currNode && x > currIndex)
		{
			currNode = currNode->next;
			currIndex += 1;
		}
		char c = '\0';
		Node* newNode = new Node;
		newNode->d = c;
		if (y == 0 && x == 0)
		{
		newNode->next = NULL;
		newNode->down = head;
		head = newNode;
		}
		else if(x == 0 && y!=0)
		{
			newNode->next = NULL;
			newNode->down = prev->down;
			prev->down = newNode;
		}
		else if (currNode->next == NULL)
		{
			newNode->next = NULL;
			newNode->down = currN2->down;
			currN2->down = newNode;
		}
		else if (currNode->next != NULL && x != 0)
		{
			currNode->next->down = currN2->down;
			currN2->down = currNode->next;
			currNode->next = NULL;
		}
	}
	int RightArrows(int x, int y)
	{
		int b = 0;
		int i2 = 0;
		Node* currN2 = head;
		while (currN2 && y > i2)
		{
			currN2 = currN2->down;
			i2 += 1;
		}
		int currIndex = 0;
		Node* currNode = currN2;
		while (currNode && x > currIndex)
		{
			currNode = currNode->next;
			currIndex += 1;
		}
		if (currNode == NULL && (currN2 == NULL || currN2->down == NULL))
		{
			return b;
		}
		if (currN2->down && currNode == NULL)
		{
			return b += 2;
		}
		else if (currN2->down && currNode->d == '\0')
		{
			return b += 2;
		}
		else if (currNode->d == '\0')
		{
			return b;
		}
		else
			return b+=1;
	}
	int LeftArrows(int x, int y)
	{
		int b = 0;
		int i2 = 0;
		Node* prev = NULL;
		Node* currN2 = head;
		while (currN2 && y > i2)
		{
			prev = currN2;
			currN2 = currN2->down;
			i2 += 1;
		}
		Node* currNode = prev;
		while (currNode && currNode->d != '\0')
		{
			currNode = currNode->next;
			b += 1;
		}
		return b;
	}
	int UpArrows(int x, int y)
	{
		int i2 = 0;
		Node* prev = NULL;
		Node* currN2 = head;
		while (currN2 && y > i2)
		{
			prev = currN2;
			currN2 = currN2->down;
			i2 += 1;
		}
		int currIndex = 0;
		while (prev && prev->d != '\0' && x > currIndex)
		{
			prev = prev->next;
			currIndex += 1;
		}
		return currIndex;
	}
	int DownArrows(int x, int y)
	{
		int i2 = 0;
		Node* currN2 = head;
		if (currN2 == NULL)
		{
			return 0;
		}
		Node* next = currN2->down;
		while (currN2 && y > i2)
		{
			currN2 = currN2->down;
			next = currN2->down;
			i2 += 1;
		}
		int currIndex = 0;
		if (x == 0 && next)
		{
			return 1;
		}
		Node* prev = NULL;
		while (next && x > currIndex)
		{
			prev = next;
			next = next->next;
			currIndex += 1;
		}
		next = prev;
		if (currIndex == 0)
		{
			return 0;
		}
		if (currIndex != 1)
		{
			if (next->d == '\0')
			{
				currIndex -= 1;
			}
		}
		return currIndex;
	}
	void writetofile(string filename)
	{
		ofstream file;
		file.open(filename);
		if (file.fail()) {
			cout << "Couldn't open the file!" << endl;
			exit(1);
		}
		Node* currNode = head;
		Node* currNode2 = head;
		while (currNode2 != NULL)
		{
			while (currNode != NULL)
			{
				file << currNode->d;
				currNode = currNode->next;
			}
			file << endl;
			currNode2 = currNode2->down;
			currNode = currNode2;
		}
		file.close();
	}
	void DeleteNode(int x, int y)
	{
		int i2 = 0;
		Node* currN2 = head;
		Node* prev = NULL;
		Node* next = NULL;
		if (y == 0)
		{
			next = currN2->next;
		}
		while (currN2 && y > i2)
		{
			prev = currN2;
			currN2 = currN2->down;
			next = currN2->next;
			i2 += 1;
		}
		int currIndex = 1;
		Node* prev2 = NULL;
		Node* currNode = currN2;
		while (currNode != NULL && x > currIndex)
		{
			prev2 = currNode;
			currNode = currNode->next;
			currIndex += 1;
		}
		if (currNode == head)
		{
			Node* DeleteNode = currNode;
			if (next != NULL)
			{
				next->down = currN2->down;
				head = next;
				delete DeleteNode;
			}
			if (next == NULL)
			{
				Node* newNode = new Node;
				newNode->d = '\0';
				newNode->down = currN2->down;
				newNode->next = NULL;
				head = newNode;
				delete DeleteNode;
			}
		}
		else if (x == 1 && y != 0)
		{
			Node* DeleteNode = currNode;
			next->down = currNode->down;
			prev->down = next;
			delete DeleteNode;
		}
		else
		{
			Node* DeleteNode = currNode;
			prev2->next = currNode->next;
			currNode->next = NULL;
			delete DeleteNode;
		}
	}
	int DeleteEnter(int x, int y)
	{
		int i2 = 0;
		Node* currN2 = head;
		Node* prev = NULL;
		Node* prev2 = NULL;
		while (currN2 && y > i2)
		{
			prev2 = prev;
			prev = currN2;
			currN2 = currN2->down;
			i2 += 1;
		}
		int currIndex = 1;
		Node* currNode = prev;
		while (currNode->next != NULL && currNode->next->d != '\0')
		{
			currNode = currNode->next;
			currIndex += 1;
		}
		if (currNode->d == '\0' && currNode == head)
		{
			Node* DeleteNode = currNode;
			head = currN2;
			delete DeleteNode;
		}
		if (currNode->d == '\0' && currNode != head)
		{
			Node* DeleteNode = currNode;
			prev2->down = currN2;
			delete DeleteNode;
			return 0;
		}
		else
		currNode->next = prev->down;
		prev->down = currN2->down;
		return currIndex;
	}

	void DisplayList(void);

	~List(void);
	// destructor
};

Node* List::InsertNode(int x,int y, char c) 
{
	int i2 = 0;
	Node* currN2 = head;
	Node* prev = NULL;
	while (currN2 && y > i2)
	{
		prev = currN2;
		currN2 = currN2->down;
		i2 += 1;
	}
	int currIndex = 1;
	Node* currNode = currN2;
	while (currNode != NULL && x>currIndex)
	{
		currNode = currNode->next;
		currIndex += 1;
	}
	Node* newNode = new Node;
	newNode->d = c;
	if (x == 0)
	{
		if (y == 0)
		{
			if (head == NULL)
			{
				newNode->next = head;
				newNode->down = head;
				head = newNode;
			}
			else 
			{
				newNode->down = head->down;
				head->down = NULL;
				newNode->next = head;
				head = newNode;
			}
		}
		else if (currNode != NULL)
		{
			newNode->down = currN2->down;
			currN2->down = NULL;
			newNode->next = currN2;
			prev->down = newNode;
		}
		else
		{
			newNode->next = NULL;
			newNode->down = prev->down;
			prev->down = newNode;
		}
	}
	else
	{
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	return newNode;
}

void List::DisplayList()
{
	Node* currNode = head;
	Node* currNode2 = head;
	while (currNode2 != NULL)
	{
		while (currNode != NULL)
		{
			cout << currNode->d;
			currNode = currNode->next;
		}
		cout << endl;
		currNode2 = currNode2->down;
		currNode = currNode2;
	}
}

List::~List(void) {

	Node* currNode = head, * nextNode = NULL;
	Node* currN2 = head;
	while (currN2 != NULL)
	{
		currN2 = currN2->down;
		while (currNode != NULL)
		{
			nextNode = currNode->next;
			// destroy the current node
			delete currNode;
			currNode = nextNode;
		}
		currNode = currN2;
	}
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main(int argc, char* argv[]) {

	List list;
	string filename;
	int f;
	cout << "\t\tMenu\nTo Create a new File press 1\nTo Load from existing File press 0\n";
	cin >> f;

	switch (f)
	{
		case 1:
		{
			cout << "Enter FileName:";
			cin >> filename;
		}
			break;
		case 0:
		{
			cout << "Enter FileName to load data from:";
			cin >> filename;
			string str;
			ifstream inFile;
			inFile.open(filename);
			if (inFile.fail()) {
				cout << "Couldn't open the file!" << endl;
				return 0;
			}
			int j = 0;
			while (getline(inFile, str)) {
				int k = 0;
				for (int i = 0; i < str.length(); i++) {
					list.InsertNode(i, j, str.at(i));
					k += 1;
				}
				list.InsertNode(k, j, '\0');
				if (str == "\0")
				{
					list.enter(0, j);
				}
				j += 1;
			}
			inFile.close();
		}
			break;
		default:
			cout << "Invalid Case\n";
			exit(1);
	}

	system("cls");
	list.DisplayList();
	HANDLE  rhnd = GetStdHandle(STD_INPUT_HANDLE);  // handle to read console

	DWORD Events = 0;     // Event count
	DWORD EventsRead = 0; // Events read from console

	bool Running = true;

	int x = 0, y = 0;
	gotoxy(x, y);
	//programs main loop
	while (Running) {

		// gets the systems current "event" count
		GetNumberOfConsoleInputEvents(rhnd, &Events);

		if (Events != 0) { // if something happened we will handle the events we want

			// create event buffer the size of how many Events
			INPUT_RECORD eventBuffer[200];

			// fills the event buffer with the events and saves count in EventsRead
			ReadConsoleInput(rhnd, eventBuffer, Events, &EventsRead);

			// loop through the event buffer using the saved count
			for (DWORD i = 0; i < EventsRead; ++i) {

				// check if event[i] is a key event && if so is a press not a release
				if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown) {


					// check if the key press was an arrow key
					switch (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode) {

					case VK_UP: //up
						if (y != 0)
						{
							x = list.UpArrows(x, y);
							y--;
							gotoxy(x, y);
						}
						break;
					case VK_DOWN: //down
						if (list.DownArrows(x, y))
						{
							if (x != 0)
							{
								int temp;
								temp = list.DownArrows(x, y);
								if (temp == 1)
								{
									temp--;
									x = temp;
								}
								else
								x = temp;
							}
							y++;
							gotoxy(x, y);
						}
						break;
					case VK_RIGHT: //right
						if (list.RightArrows(x, y) == 2)
						{
							x = 0;
							y += 1;
							gotoxy(x, y);
						}
						else if (list.RightArrows(x, y))
						{
							x++;
							gotoxy(x, y);
						}
						break;
					case VK_LEFT: //left
						if (x != 0)
						{
							x--;
							gotoxy(x, y);
						}
						else if (x == 0 && y != 0)
						{
							x = list.LeftArrows(x, y);
							y -= 1;
							gotoxy(x, y);
						}
						break;
					default:

						if (eventBuffer->Event.KeyEvent.uChar.UnicodeChar == 27)
						{
							system("CLS");
							gotoxy(0, 0);
							cout << "Enter Name Path of the File in which to save data:";
							cin >> filename;
							list.writetofile(filename);
							exit(1);
						}
						if (eventBuffer->Event.KeyEvent.uChar.UnicodeChar == 13)
						{
							list.enter(x, y);
							system("CLS");
							gotoxy(0, 0);
							list.DisplayList();
							x = 0;
							y += 1;
							gotoxy(x, y);
							break;
						}
						if (eventBuffer->Event.KeyEvent.uChar.UnicodeChar == 8)
						{
							if (!(x == 0 && y == 0))
							{
								if (x == 0 && y != 0)
								{
									x = list.DeleteEnter(x, y);
									system("CLS");
									gotoxy(0, 0);
									x++;
									y--;
									list.DisplayList();
									gotoxy(x, y);
								}
								else
									list.DeleteNode(x, y);
									system("CLS");
									gotoxy(0, 0);
									x--;
									list.DisplayList();
									gotoxy(x, y);
							}
							break;
						}
						else
							list.InsertNode(x,y, eventBuffer->Event.KeyEvent.uChar.AsciiChar);
							system("CLS");
							gotoxy(0, 0);
							x++;
							list.DisplayList();
							gotoxy(x, y);
							break;
					}
				}

			} // end EventsRead loop

		}

	} // end program loop
	return 0;
}