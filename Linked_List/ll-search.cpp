#include <iostream>
#include <fstream>

using namespace std;

struct Node 
{
	int data;
	Node *next, *previous;
};

Node *head, *tail;

void createLinkedList(void) 
{
	head = NULL;
	tail = NULL;
}

Node* createNode(int data)
{
	Node *temp;
	temp = new Node[1];
	temp[0].data = data;
	temp[0].next = NULL;
	temp[0].previous = NULL;
	return temp;
}

void insertAtEnd(Node *newNode)
{
	if(head == NULL && tail == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode[0].previous = tail;
		tail[0].next = newNode;
		tail = newNode;
	}
}


bool readFromFileAndInitialize(char *fileName)
{
	ifstream iFile;
	iFile.open(fileName);
	if(iFile.is_open())
	{
		int numberOfInputs;
		iFile >> numberOfInputs;
		
		for(int i=0; i<numberOfInputs; i++)
		{
			int input;
			iFile >> input;
			
			Node *newNode = createNode(input);
			insertAtEnd(newNode);
			//insertAtBeginning(newNode);
		}
		
		iFile.close();
	}
	else
	{
		cout << "Could not open file" << endl;
		return false;
	}
	return true;
}

bool searchItem(int searchkey)
{	int count = 0;
	for(Node * current = head; current != NULL ; current = current[0].next)
	{	count ++;
		if(current[0].data == searchkey)
		{	
			cout << " Item found in position : " << count << endl;
			return true;
		}
		
	}
	return false;

}

int main (int argc, char *argv[])
{

	createLinkedList();

	if(!readFromFileAndInitialize(argv[1]))
	{
		cout << "Issue with the file" << endl;
		return -1;
	}

	if(!searchItem(8))
	cout << "Could't find the  number "<< endl;

	return 0;

}
