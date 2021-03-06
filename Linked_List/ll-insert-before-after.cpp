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

void insertAtBeginning(Node *newNode)
{
	if(head == NULL && tail == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{

		head[0].previous = newNode;
		newNode[0].next = head;
		head = newNode; // head is just a identifier which identify the first Node of the list
		
	}
}

void insertAtMiddle(Node *previousNode, Node *newNode)
{
	
	newNode[0].previous = previousNode;
	newNode[0].next = previousNode[0].next;
	previousNode[0].next = newNode;
	previousNode[0].next[0].previous = newNode;
	
}

bool readFromFile(char *fileName)
{
	ifstream iFile;
	iFile.open(fileName);
	if(iFile.is_open())
	{	int numberOfInputs;
		iFile >> numberOfInputs;
		for (int i = 0 ; i < numberOfInputs ; i++)
		{
			int input;
			iFile >> input;
			Node *newNode = createNode(input);
			insertAtEnd(newNode);
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

void printNode(Node *node)
{
	if(node == NULL) cout << "there is no list" << endl;
	else cout << node[0].data << endl;
}

void traverseForward(void)
{
	cout << "Currrent List : " << endl;
	for(Node* current = head ; current != NULL ; current = current[0].next)
		printNode(current);

}

Node* searchItem(int searchKey)
{
	for(Node* current = head; current != NULL ; current = current[0].next)
	{
		if(current[0].data == searchKey)
		return current;
	}

	return NULL;
}

void insertBeforeItem(int existingItem, int newItem)
{

	Node * currentItem = searchItem(existingItem);
	if(currentItem == NULL)
	{
		cout << "Number " << existingItem << " is not found in the list" << endl;
		return;
	}
	else 
	{
		Node * newNode = createNode(newItem);
		if(currentItem == head)
		{
			insertAtBeginning(newNode);
		}
		else
		{
			insertAtMiddle(currentItem[0].previous, newNode);
		}
	}

}

void insertAfterItem(int existingItem, int newItem)
{


	Node * currentItem = searchItem(existingItem);
	if(currentItem == NULL)
	{
		cout << "Number " << existingItem << " is not found in the list" << endl;
		return;
	}
	else 
	{
		Node * newNode = createNode(newItem);
		if(currentItem == tail)
		{
			insertAtEnd(newNode);
		}
		else
		{
			insertAtMiddle(currentItem, newNode);
		}
	}

}

int main(int argc, char *argv[])
{

	createLinkedList();
	if(!readFromFile(argv[1]))
	{
		cout << "Issue with the file" << endl;
		return -1;
	}
	
	
	traverseForward();

	//## use un comment any one of the following two line ##
	
	//insertBeforeItem(45,42);
	
	insertAfterItem(45,48);


	// print after insert
	cout << "After inserting item " << endl;
	traverseForward();
}
