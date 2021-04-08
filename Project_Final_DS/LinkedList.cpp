#include "LinkedList.h"
#include <assert.h>
#include <iostream>
using namespace std;

Node::Node()
{
	Value = "";
	LineNum = 0;
	next = NULL;
}

Node::Node(string val)
{
	Value = val;
	next = NULL;
}

Node::~Node()
{

}

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

void LinkedList::append(string value)
{
	Node* temp = new Node(value);
	temp->LineNum = size + 1;
	if (head == NULL) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;

	}
	size++;
}

void LinkedList::InsertAt(string value, int pos)
{
	pos = pos - 1;
	assert(pos >= 0 && pos < size);

	Node* temp = head;
	Node* newNode = new Node(value);

	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
		temp = newNode;
		while (temp != NULL) {
			temp->LineNum = temp->LineNum + 1;
			temp = temp->next;

		}
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;

		newNode->next = temp->next;
		temp->next = newNode;
		temp = temp->next;
		temp->LineNum = pos;

		while (temp != NULL) {
			temp->LineNum = temp->LineNum + 1;
			temp = temp->next;

		}

	}
	size++;
}

void LinkedList::GetString(int linenumber)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->LineNum == linenumber)
		{
			cout << temp->Value << endl;
			return;
		}
		else
		{
			temp = temp->next;
		}
	}
}

void LinkedList::deleteat(int pos) {
	pos = pos - 1;
	assert(pos >= 0 && pos < size);
	Node* temp = head;
	if (pos == 0)
	{
		head = head->next;
		while (temp != NULL) {
			temp->LineNum = temp->LineNum - 1;
			temp = temp->next;

		}
		delete temp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;
		Node* del = temp->next;
		temp->next = del->next;
		delete del;
		if (pos == size - 1)
			tail = temp;
		temp = temp->next;
		while (temp != NULL) {
			temp->LineNum = temp->LineNum - 1;
			temp = temp->next;

		}
	}
	size--;
}

void LinkedList::UpdateLine(string newtext, int Line)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->LineNum == Line)
		{
			temp->Value = newtext;
			return;
		}
		else
		{
			temp = temp->next;
		}
	}
}

void LinkedList::Find(string str)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if ((temp->Value).find(str) != string::npos)
		{
			cout << temp->LineNum << endl;
		}
		temp = temp->next;
	}
}

void LinkedList::FindAndReplace(string oldLine, string newLine)
{
	Node* temp = head;
	while (temp != NULL)
	{
		temp->Value.replace(temp->Value.find(oldLine), temp->Value.length(), newLine);
		temp = temp->next;
	}

	/*Node* temp = head;
	while (temp != NULL)
	{
		if (temp->Value == oldLine)
		{
			temp->Value = newLine;
		}
		else
		{
			temp = temp->next;
		}
	}*/
}

void LinkedList::Display()
{
	Node* newNode = head;
	while (newNode != NULL)
	{
		cout << newNode->LineNum << "		" << newNode->Value << endl;
		newNode = newNode->next;
	}
}

/*void LinkedList::save(list<string> a)
{
	ofstream x;
	list<string>::iterator it = a.begin();
	for (int i = 0; i < a.size(); i++)
	{
		x.open("Test.txt", ios_base::app);
		x << *it << "    " << i + 1 << endl;
		x.close();
		it++;
	}
}*/

LinkedList::~LinkedList()
{

}