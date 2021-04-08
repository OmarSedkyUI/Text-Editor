#pragma once
#include <iostream>
#include <list>
#include <fstream>
using namespace std;
#include <string>

class Node
{
public:
	Node* next;
	int LineNum;
	string Value;
public:
	Node();
	Node(string val);
	~Node();
};

class LinkedList
{
public:
	int size;
	Node* head;
	Node* tail;
public:
	LinkedList();
	void append(string value);
	void InsertAt(string value, int pos);
	void GetString(int linenumber);
	void deleteat(int pos);
	void UpdateLine(string newtext, int Line);
	void Find(string str);
	void FindAndReplace(string oldLine, string newLine);
	void Display();
	//void save(list<string> a);
	~LinkedList();
};