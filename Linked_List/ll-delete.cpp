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

void deleteNode(Node *node)
{
	delete [] node;
}

void deleteFirst(void)
{
	if(head == NULL) return;
	
	Node* node = head;
	head = head[0].next;
	if(head != NULL) head[0].previous = NULL;
	else tail = NULL;
	deleteNode(node);
	
}

void deleteLast(void)
{
	if(tail == NULL) return;
	
	Node* node = tail;
	tail = tail[0].previous;
	if(tail != NULL) tail[0].next = NULL;
	else tail = NULL;
	deleteNode(node);
	
}

void deleteList(void)
{
	if(head == NULL) return;
	while(head != tail)
	{
		deleteFirst();
	}
	
	deleteNode(head);
	head = NULL;
	tail = NULL;
	
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

int main(int argc, char *argv[])
{

	createLinkedList();
	if(!readFromFile(argv[1]))
	{
		cout << "Issue with the file" << endl;
		return -1;
	}
	
	
	traverseForward();

	//## use un comment any one of the following three line ##
	
	deleteFirst();
	
	//deleteLast();
	
	//deleteList();

	// print after dealiting 
	cout << "After deleting item " << endl;
	traverseForward();
}
